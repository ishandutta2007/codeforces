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
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    array<vector<int>, 2> dp_pref;
    dp_pref.fill(vector<int>(n));
    vector<int> dp(n), ans(n);
    for (int i = 0; i < n; i++) {
        if (i - 3 >= 0) {
            dp_pref[(i - 3) & 1][a[i - 3]] = max(dp_pref[(i - 3) & 1][a[i - 3]], dp[i - 3]);
        }
        dp[i] = max(1, dp_pref[(i & 1) ^ 1][a[i]] + 1);
        if (i && a[i - 1] == a[i]) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
        ans[a[i]] = max(ans[a[i]], dp[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }    
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}