#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 505;
int dp[maxN][maxN];
const int mod = 998244353;
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int c[2 * maxN][2 * maxN];
int n, x;
int pw[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    c[0][0] = 1;
    for (int i = 1; i < 2 * maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    for (int i = 0; i < maxN; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < maxN; j++) {
            pw[i][j] = mult(i, pw[i][j - 1]);
        }
    }
    cin >> n >> x;
    dp[0][0] = 1;
    for (int z = 1; z <= x; z++) dp[0][z] = 1;
    for (int cnt = 1; cnt <= n; cnt++) {
        if (cnt == 1) continue;
        for (int at_most = 1; at_most <= x; at_most++) {
            if (at_most > cnt - 1) {
                dp[cnt][at_most] = sum(dp[cnt][at_most], dp[cnt][at_most - (cnt - 1)]);
            }
            for (int take = 1; take <= cnt; take++) {
                if (cnt != take) {
                    if (at_most > (cnt - 1)) {
                        dp[cnt][at_most] = sum(dp[cnt][at_most], mult(dp[cnt - take][at_most - (cnt - 1)], mult(pw[cnt - 1][take], c[cnt][take])));
                    }
                }
                else {
                    dp[cnt][at_most] = sum(dp[cnt][at_most], mult(pw[min(cnt - 1, at_most)][take], c[cnt][take]));
                }
            }
        }
    }
    cout << dp[n][x] << '\n';
    return 0;
}