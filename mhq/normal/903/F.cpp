#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
int dp[maxN][(1 << 12)];
const int inf = (int)1e7 + 10;
int n;
int a[5];
char c[5][maxN];
int masks[maxN];
int prec[10][10];
int rowmask[maxN];
void precalc() {
    for (int j = 1; j <= 4; j++) {
        for (int k = 1; k <= 5 - j; k++) {
            if (k == 4) continue;
            for (int x1 = j; x1 <= j + k - 1; x1++) {
                for (int x2 = 0; x2 <= k - 1; x2++) {
                    prec[j][k] |= 1 << (4 * x2 + x1 - 1);
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    precalc();
    for (int i = 1; i <= 4; i++) cin >> a[i];
    for (int i = 1; i < maxN; i++) {
        for (int j = 0; j < (1 << 12); j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == '*') {
                rowmask[j] |= (1 << (i - 1));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k <= 2; k++) {
                if (c[j][i + k] == '*') {
                    masks[i] |= 1 << (4 * k + (j - 1));
                }
            }
        }
    }
    dp[1][masks[1]] = 0;
    for (int i = 1; i <= n; i++) {
        for (int mask = (1 << 12) - 1; mask >= 0; mask--) {
            if ((mask & 15) == 0) {
                int to = (mask >> 4) + (rowmask[i + 3] << 8);
                dp[i + 1][to] = min(dp[i + 1][to], dp[i][mask]);
            }
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 5 - j; k++) {
                    if (k == 4) {
                        dp[i + 4][masks[i + 4]] = min(dp[i + 4][masks[i + 4]], dp[i][mask] + a[4]);
                    }
                    int to = (mask | prec[j][k]) ^ prec[j][k];
                    dp[i][to] = min(dp[i][to], dp[i][mask] + a[k]);
                }
            }
        }
    }
    int t1 = min(dp[n - 2][0], dp[n - 1][0]);
    int t2 = min(dp[n][0], dp[n + 1][0]);
    int t3 = min(dp[n + 2][0], dp[n + 3][0]);
    cout << min(min(t1, t2), min(t3, dp[n + 4][0]));
	return 0;
}