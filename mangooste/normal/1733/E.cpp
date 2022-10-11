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
    #define dprint(...)
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    constexpr int N = 125;
    vector dp1(N, vector<ll>(N)), dp2 = dp1;

    auto fill_dp = [](ll val, int limit, vector<vector<ll>> &dp) {
        for (auto &v : dp) fill(all(v), 0);
        dp[0][0] = val;
        for (int i = 0; i < N; i++) {
            for (int j = 0; i + j < limit && j < N; j++) {
                if (j + 1 < N) dp[i][j + 1] += (dp[i][j] + 1) / 2;
                if (i + 1 < N) dp[i + 1][j] += dp[i][j] / 2;
            }
        }
    };

    int q;
    cin >> q;
    while (q--) {
        ll t;
        int x, y;
        cin >> t >> x >> y;
        t -= x + y;
        if (t < 0) {
            cout << "NO\n";
            continue;
        }

        fill_dp(t, x + y, dp1);
        fill_dp(t + 1, x + y, dp2);
        cout << (dp1[x][y] != dp2[x][y] ? "YES" : "NO") << '\n';
    }
}