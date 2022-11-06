#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int board[N][N];
int k;

void generate(int n) {
    if (n == 0) {
        board[1][1] = 1;
        return;
    }

    generate(n - 1);

    int p = (1 << n);
    for (int i = 1; i <= p / 2; i++) {
        for (int j = p / 2 + 1; j <= p; j++) {
            board[i][j] = board[i][j - p / 2];
        }
    }

    for (int i = p / 2 + 1; i <= p; i++) {
        for (int j = 1; j <= p / 2; j++) {
            board[i][j] = board[i - p / 2][j];
        }
    }

    for (int i = p / 2 + 1; i <= p; i++) {
        for (int j = p / 2 + 1; j <= p; j++) {
            board[i][j] = 1 - board[i - p / 2][j - p / 2];
        }
    }
}

int main() {
    scanf("%d", &k);

    generate(k);

    for (int i = 1; i <= (1 << k); i++) {
        for (int j = 1; j <= (1 << k); j++) {
            printf("%c", board[i][j] == 1 ? '+' : '*');
        }
        printf("\n");
    }

    return 0;
}