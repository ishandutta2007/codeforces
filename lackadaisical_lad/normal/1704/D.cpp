#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(m));
    vector<ll> bal(n);    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            bal[i] += c[i][j] * j;
        }
        // cout << bal[i] << " \n"[i + 1 == n];
    }
    auto mn = *min_element(bal.begin(), bal.end());
    for (int i = 0; i < n; i++)
        if (bal[i] != mn) {
            cout << i + 1 << ' ' << bal[i] - mn << '\n';
            break;
        }
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