#include <stdio.h>

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    // Rows
    for(int i = 0; i < 3; i++)
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

    // Columns
    for(int i = 0; i < 3; i++)
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main() {
    int player = 1;
    int choice;
    char mark;
    int moves = 0;

    while(1) {
        printBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d (%c), secim et (1-9): ", player, mark);
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Yanlis secim! Yeniden dene.\n");
            continue;
        }

        board[row][col] = mark;
        moves++;

        if(checkWin()) {
            printBoard();
            printf("🎉 Player %d (%c) qazandi!\n", player, mark);
            break;
        }

        if(moves == 9) {
            printBoard();
            printf("🤝 Heç-heçə!\n");
            break;
        }

        player++;
    }

    return 0;
}
