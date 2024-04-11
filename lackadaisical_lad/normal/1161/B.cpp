#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        --a[i].first;
        --a[i].second;
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> b(m);
    for (int i = 1; i < n; i++) {
        if (n % i)
            continue;
        for (int j = 0; j < m; j++) {
            b[j].first = (a[j].first + i) % n;
            b[j].second = (a[j].second + i) % n;
            if (b[j].first > b[j].second)
                swap(b[j].first, b[j].second);
        }
        sort(b.begin(), b.end());
        if (a == b) {
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
    // cin >> T;
    while (T--) {
        solve();
    }
}