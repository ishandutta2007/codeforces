#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    constexpr int LOG = 20, MASK = 1 << LOG;
    vector<int> dp_lcm(MASK, 1), lower_bit(MASK), parity(MASK);
    for (int mask = 1; mask < MASK; mask++) {
        parity[mask] = __builtin_parity(mask);
        lower_bit[mask] = __builtin_ctz(mask);
        dp_lcm[mask] = lcm(dp_lcm[mask ^ (1 << lower_bit[mask])], lower_bit[mask] + 1);
    }

    vector<int> dp(LOG);
    for (int i = 1; i < LOG; i++) {
        for (int mask = 0; mask < (1 << (i - 1)); mask++) {
            dp[i] += m * (mask == 0 ? i : lower_bit[mask] + 1) / dp_lcm[mask ^ (1 << (i - 1))] * (parity[mask] ? -1 : 1);
        }
    }

    vector<bool> ok(n + 1, true);
    ll ans = 1;
    for (int x = 2; x <= n; x++) {
        if (!ok[x]) continue;
        ll value = x;
        for (int d = 1; value <= n; value *= x, d++) {
            ans += dp[d];
            ok[value] = false;
        }
    }
    cout << ans << '\n';
}