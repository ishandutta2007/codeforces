#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    if (n == 1) {
        cout << ((m / 6 * 3) + (m % 6 > 3 ? m % 6 - 3 : 0)) * 2 << '\n';
        return;
    }
    if (n == 2) {
        if (m == 2)
            cout << "0\n";
        else if (m == 3)
            cout << "4\n";
        else if (m == 7)
            cout << "12\n";
        else
            cout << m * 2 << '\n';
        return;
    }
    cout << n * m - (n * m % 2) << '\n';
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