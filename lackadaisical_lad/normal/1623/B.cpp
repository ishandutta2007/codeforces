#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second = -a[i].second;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i].first << ' ' << -a[i].second << ' ';
        if (i + 1 == n || a[i].first != a[i + 1].first) {
            cout << a[i].first << '\n';
        } else {
            cout << -a[i + 1].second + 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}