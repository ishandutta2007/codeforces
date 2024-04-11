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
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pref[i + 1] = pref[i] + x;
    }

    if (k >= n) {
        ll ans = pref.back();
        ans += 1ll * k * n;
        ans -= 1ll * n * (n + 1) / 2;
        cout << ans << '\n';
        return;
    }

    ll ans = 0;
    for (int i = k; i <= n; i++) {
        ans = max(ans, pref[i] - pref[i - k]);
    }
    ans += 1ll * k * (k - 1) / 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}