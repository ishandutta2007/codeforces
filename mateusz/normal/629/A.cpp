#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n;
char board[N][N];

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %s", &board[i][1]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 'C') {
                for (int k = i + 1; k <= n; k++) {
                    if (board[k][j] == 'C') ans++;
                }

                for (int k = j + 1; k <= n; k++) {
                    if (board[i][k] == 'C') ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}