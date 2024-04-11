#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], x + dp[i]);
        if (2 * i <= n) dp[2 * i] = min(dp[2 * i], y + dp[i]);
        if (i && 2 * i <= n + 1) dp[2 * i - 1] = min(dp[2 * i - 1], x + y + dp[i]);
    }
    answer(dp[n]);
}