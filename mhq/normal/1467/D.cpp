#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 5005;
int dp[maxN][maxN];
int coef[maxN];
int a[maxN];
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < k; i++) {
        for (int where = 1; where <= n; where++) {
            if (where > 1) dp[i + 1][where - 1] = sum(dp[i + 1][where - 1], dp[i][where]);
            if (where < n) dp[i + 1][where + 1] = sum(dp[i + 1][where + 1], dp[i][where]);
        }
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            coef[j] = sum(coef[j], mult(dp[i][j], dp[k - i][j]));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans = sum(ans, mult(coef[i], a[i]));
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        ans = sub(ans, mult(coef[i], a[i]));
        a[i] = x;
        ans = sum(ans, mult(coef[i], a[i]));
        cout << ans << '\n';
    }
    return 0;
}