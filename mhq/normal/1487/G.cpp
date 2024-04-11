#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 405;
int dp[maxN][maxN][4];
int ndp[maxN][maxN][4];
int n;
const int A = 26;
int c[A];
int D[maxN][maxN];
int single[maxN];
int tot;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < A; i++) cin >> c[i];
    dp[0][0][3] = 1;
    int big = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= i; x++) {
            for (int y = 0; y + x <= i; y++) {
                for (int last = 0; last < 4; last++) {
                    if (!dp[x][y][last]) continue;
                    for (int add = 0; add < 3; add++) {
                        if (add == last && add < 2) continue;
                        int ways = 1;
                        if (add == 2) {
                            ways = A - 2;
                            if (last == 2) ways--;
                        }
                        ndp[x + (add == 0)][y + (add == 1)][add] = sum(ndp[x + (add == 0)][y + (add == 1)][add],
                                                                        mult(ways, dp[x][y][last]));
                    }
                    dp[x][y][last] = 0;
                }
            }
        }
        for (int x = 0; x <= i + 1; x++) {
            for (int y = 0; y + x <= i + 1; y++) {
                for (int last = 0; last < 4; last++) {
                    dp[x][y][(i == big) ? 3 : last] = sum(dp[x][y][(i == big) ? 3 : last], ndp[x][y][last]);
                    ndp[x][y][last] = 0;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int c = 0; c < 4; c++) {
                D[i][j] = sum(D[i][j], dp[i][j][c]);
                single[i] = sum(single[i], dp[i][j][c]);
                tot = sum(tot, dp[i][j][c]);
            }
        }
    }
    for (int i = 0; i < A; i++) {
        for (int r = c[i] + 1; r <= n; r++) {
            tot = sub(tot, single[r]);
        }
    }
    for (int i = 0; i < A; i++) {
        for (int j = i + 1; j < A; j++) {
            for (int x = c[i] + 1; x <= n; x++) {
                for (int y = c[j] + 1; y <= n; y++) {
                    tot = sum(tot, D[x][y]);
                }
            }
        }
    }
    cout << tot;
    return 0;
}