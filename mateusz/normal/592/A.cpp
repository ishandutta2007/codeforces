#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char board[N][N];

int main() {

    for (int i = 1; i <= 8; i++) {
        scanf("%s", &board[i][1]);
    }

    int shortestWhite = 100;
    int shortestBlack = 100;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (board[i][j] == 'W') {
                bool clear = true;
                for (int k = 1; k < i; k++) {
                    if (board[k][j] == 'B') {
                        clear = false;
                        break;
                    }
                }
                if (clear) {
                    shortestWhite = min(shortestWhite, i);
                }
            } else if (board[i][j] == 'B') {
                bool clear = true;
                for (int k = i + 1; k <= 8; k++) {
                    if (board[k][j] == 'W') {
                        clear = false;
                        break;
                    }
                }
                if (clear) {
                    shortestBlack = min(shortestBlack, 9 - i);
                }
            }
        }
    }
    if (shortestWhite <= shortestBlack) {
        printf("A\n");
    } else {
        printf("B\n");
    }
    return 0;
}