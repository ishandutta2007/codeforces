#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), g(m);
    for (auto &el : b)
        cin >> el;
    for (auto &el : g)
        cin >> el;
    sort(b.rbegin(), b.rend());
    sort(g.begin(), g.end());
    if (b[0] > g[0]) {
        cout << "-1\n";
        return;
    }
    ll ans = accumulate(b.begin(), b.end(), 0LL) * m + accumulate(g.begin(), g.end(), 0LL);
    ans -= b[0] * (m - 1);
    if (b[0] == g[0])
        ans -= b[0];
    else
        ans -= b[1];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}