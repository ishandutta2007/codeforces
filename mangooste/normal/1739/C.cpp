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

void solve(int test_num) {
    int n;
    cin >> n;

    vector choose(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
        }
    }

    vector<ll> dp(n + 1);
    dp[2] = 1;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = choose[i - 1][i / 2];
        dp[i] += choose[i - 2][i / 2 - 1] - dp[i - 2] - 1;
    }
    constexpr int MOD = 998244353;
    cout << dp[n] % MOD << ' ' << (choose[n][n / 2] - dp[n] - 1) % MOD << " 1\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}