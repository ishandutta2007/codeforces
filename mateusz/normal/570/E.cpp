#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 1e9 + 7;

const pair<int, int> moves[] = {{-1, 0}, {-1,  1}, {0, 0}, {0, 1}};
int diagonals, n, m;
char board[N][N];
int dp[2][N][N];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

inline int cellsOnDiagonal(int diag) {
    if (2 * diag > diagonals + 1) {
        return cellsOnDiagonal(diagonals - diag + 1);
    }
    return min(diag, min(n, m));
}

pair<int, int> getCell(int diag, int nr) {
    int col = min(m, diag) - nr + 1;
    int row = nr + max(0, diag - m);
    return make_pair(row, col);
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }

    diagonals = n + m -1;

    dp[1][1][1] = board[1][1] == board[n][m];

    for (int i = 2; 2 * i <= diagonals + 1; i++) {
        for (int j = 1; j <= cellsOnDiagonal(i); j++) {
            for (int k = 1; k <= cellsOnDiagonal(diagonals - i + 1); k++) {
                pair<int, int> leftCell = getCell(i, j);
                pair<int, int> rightCell = getCell(diagonals - i + 1, k);
                dp[i % 2][j][k] = 0;
                if (board[leftCell.first][leftCell.second] != board[rightCell.first][rightCell.second]) {
                    continue;
                }
                for (int l = 0; l < 4; l++) {
                    int cellLeft = j + moves[l].first;
                    int cellRight = k + moves[l].second;
                    if (i > m) {
                        cellLeft++;
                    }
                    if (diagonals - i + 1 >= m) {
                        cellRight--;
                    }
                    if (1 <= cellLeft && cellLeft <= cellsOnDiagonal(i - 1) &&
                        1 <= cellRight && cellRight <= cellsOnDiagonal(diagonals - i + 2)) {
                        add(dp[i % 2][j][k], dp[(i % 2) ^ 1][cellLeft][cellRight]);
                    }
                }
            }
        }
    }

    int ans = 0;
    int firstDiagonal = diagonals / 2 + diagonals % 2;
    int secondDiagonal = diagonals - firstDiagonal + 1;
    for (int i = 1; i <= cellsOnDiagonal(firstDiagonal); i++) {
        for (int j = 1; j <= cellsOnDiagonal(secondDiagonal); j++) {
            pair<int, int> leftCell = getCell(firstDiagonal, i);
            pair<int, int> rightCell = getCell(secondDiagonal, j);
            if (abs(leftCell.first - rightCell.first) + abs(leftCell.second - rightCell.second) <= 2 * (firstDiagonal != secondDiagonal)) {
                add(ans, dp[firstDiagonal % 2][i][j]);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}