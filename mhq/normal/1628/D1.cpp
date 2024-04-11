#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2005;
const int mod = (int)1e9 + 7;
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
int m, k;
int dp[maxN][maxN];
void solve() {
    cin >> n >> m >> k;
    const int inv2 = (mod + 1) / 2;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n - m; j++) {
            if (i == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (j == 0) {
                dp[i][j] = mult(i, k);
                continue;
            }
            dp[i][j] = mult(inv2, sum(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[m][n - m] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}