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
    for (auto &x : a) cin >> x;

    auto solve = [&](int i) {
        return max(0, max(a[i - 1], a[i + 1]) - a[i] + 1);
    };

    if (n & 1) {
        ll ans = 0;
        for (int i = 1; i < n - 1; i += 2) ans += solve(i);
        cout << ans << '\n';
        return;
    }

    vector<ll> dp_pref(n);
    for (int i = 1; i < n - 1; i++) {
        if (i - 2 >= 0) dp_pref[i] = dp_pref[i - 2];
        dp_pref[i] += solve(i);
    }
    
    vector<ll> dp_suf(n);
    for (int i = n - 2; i > 0; i--) {
        if (i + 2 < n) dp_suf[i] = dp_suf[i + 2];
        dp_suf[i] += solve(i);
    }

    ll ans = min(dp_pref[n - 2], dp_pref[n - 3]);
    for (int i = 1; i < n - 4; i += 2) {
        ans = min(ans, dp_pref[i] + dp_suf[i + 3]);
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