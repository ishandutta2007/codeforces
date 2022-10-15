#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    ll g = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i) {
            g = gcd(g, abs(x[i] - x[0]));
        }
    }
    for (int i = 0; i < n; i++) {
        if ((k - x[i]) % g == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}