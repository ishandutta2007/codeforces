#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int32_t main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    ll ans = 1e18;
    auto solve = [&](int i) {
        ll cur = 0;
        ll prev = 0;
        for (int j = i + 1; j < n; ++j) {
            ll m = (prev ? (a[j] + prev) / a[j] : 1);
            cur += m;
            prev = a[j] * m;
        }
        prev = 0;
        for (int j = i - 1; j >= 0; --j) {
            ll m = (prev ? (a[j] + prev) / a[j] : 1);
            cur += m;
            prev = a[j] * m;
        }
        return cur;
    };
    for (int i = 0; i < n; ++i) {
        ans = min(ans, solve(i));
    }
    cout << ans << '\n';
}