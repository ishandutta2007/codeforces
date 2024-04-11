#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 52;
int dp[maxN][maxN][maxN][maxN];
int sum[maxN][maxN];
int n;
char c[maxN][maxN];
int getSum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            sum[i][j] = (c[i][j] == '#') + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {
                for (int t = j; t <= n; t++) {
                    dp[i][j][k][t] = 55;
                }
            }
        }
    }
    for (int lenX = 1; lenX <= n; lenX++) {
        for (int lenY = 1; lenY <= n; lenY++) {
            for (int i = 1; i + lenX - 1 <= n; i++) {
                for (int j = 1; j + lenY - 1 <= n; j++) {
                    int kX = i + lenX - 1;
                    int kY = j + lenY - 1;
                    int t = getSum(i, j, kX, kY);
                    if (t == 0) {
                        dp[i][j][kX][kY] = 0;
                    }
                    else {
                        dp[i][j][kX][kY] = max(lenX, lenY);
                    }
                    for (int where = i + 1; where <= kX; where++) {
                        dp[i][j][kX][kY] = min(dp[i][j][kX][kY], dp[i][j][where - 1][kY] + dp[where][j][kX][kY]);
                    }
                    for (int where = j + 1; where <= kY; where++) {
                        dp[i][j][kX][kY] = min(dp[i][j][kX][kY], dp[i][j][kX][where - 1] + dp[i][where][kX][kY]);
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][n];
    return 0;
}