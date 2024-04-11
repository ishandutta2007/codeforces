#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> p(n), l(n), r(n);
    for (int i = 1; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    int ans = 0;
    vector<ll> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] < l[i]) {
            ans++;
            dp[i] = r[i];
        } else {
            dp[i] = min<ll>(dp[i], r[i]);
        }
        dp[p[i]] += dp[i];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}