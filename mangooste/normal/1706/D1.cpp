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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    a.resize(unique(all(a)) - a.begin());
    n = len(a);

    const int M = a.back() + 1;
    vector<int> dp(M, -1);
    for (auto &x : a) {
        int div = x / k, prev_div = -1;
        while (true) {
            int from = x / (div + 1) + 1;
            if (prev_div != -1) {
                assert(prev_div != div);
                dp[prev_div] = max<int>(dp[prev_div], from > k ? 1e9 : div);
            }
            if (from == 1) break;

            prev_div = div;
            div = x / (from - 1);
        }
    }

    int mx = 1;
    for (auto &x : a) mx = max(mx, x / k);

    int ans = 1e9;
    for (int mn = 0; mn <= a[0]; mn++) {
        mx = max(mx, mn);
        ans = min(ans, mx - mn);
        mx = max(mx, dp[mn]);
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