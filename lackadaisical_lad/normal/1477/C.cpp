#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rng);
    auto get = [&](int pos) {
        ll x1 = x[p[pos + 1]] - x[p[pos]];
        ll y1 = y[p[pos + 1]] - y[p[pos]];
        ll x2 = x[p[pos + 2]] - x[p[pos + 1]];
        ll y2 = y[p[pos + 2]] - y[p[pos + 1]];
        return (x1 * x2 + y1 * y2 < 0);
    };
    bool bad = true;
    while (bad) {
        bad = false;
        for (int j = 0; j + 2 < n; j++) {
            if (!get(j)) {
                swap(p[j + 1], p[j + 2]);
                bad = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " \n"[i + 1 == n];
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