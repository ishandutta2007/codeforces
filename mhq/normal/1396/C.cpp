#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e6 + 10;
ll a[maxN];
ll dp[maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    ll r1, r2, r3, d;
    cin >> r1 >> r2 >> r3 >> d;
    ll ans = d * (n - 1);
    dp[0][1] = 3e18;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll f0 = a[i] * r1 + r3;
        ll f1 = min(r2, r1 * (a[i] + 1)) + r1;
        dp[i][0] = 3e18;
        dp[i][1] = 3e18;
        dp[i][0] = dp[i - 1][1] + 2 * d + f1;
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + f0);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + f0 + 2 * d);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + f1);
        if (i == n) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + f0 + d);
        }
    }
    ans += min(dp[n][0], dp[n][1] + 2 * d);
    cout << ans;
    return 0;
}