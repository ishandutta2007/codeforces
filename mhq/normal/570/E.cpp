#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sumMod(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 505;
int n, m;
int dp[maxN][maxN];
char c[maxN][maxN];
int ndp[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    dp[1][n] = (c[1][1] == c[n][m]);
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    for (int sum = 3; sum <= (n + m + 2 - sum); sum++) {
        memset(ndp, 0, sizeof ndp);
        int other_sum = n + m + 2 - sum;
        for (int x = 1; x <= n && x < sum; x++) {
            int y = sum - x;
            if (y > m || y < 1) continue;
            for (int other_x = 1; other_x <= n && other_x < other_sum; other_x++) {
                int other_y = other_sum - other_x;
                if (other_y > m || other_y < 1) continue;
                if (c[x][y] != c[other_x][other_y]) continue;
                ndp[x][other_x] = sumMod(ndp[x][other_x], dp[x][other_x]);
                ndp[x][other_x] = sumMod(ndp[x][other_x], dp[x][other_x + 1]);
                ndp[x][other_x] = sumMod(ndp[x][other_x], dp[x - 1][other_x + 1]);
                ndp[x][other_x] = sumMod(ndp[x][other_x], dp[x - 1][other_x]);
            }
        }
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                dp[x][y] = ndp[x][y];
            }
        }
        if (sum + 1 > (n + m + 2 - sum - 1)) {
            int tot = 0;
            if (sum == n + m + 2 - sum) {
                for (int x = 1; x <= n; x++) {
                    tot = sumMod(tot, dp[x][x]);
                }
            }
            else {
                for (int x = 1; x <= n; x++) {
                    tot = sumMod(tot, dp[x][x]);
                    tot = sumMod(tot, dp[x][x + 1]);
                }
            }
            cout << tot << '\n';
        }
    }
    return 0;
}