#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++) {
        ++ans;
        int j = i;
        int mn = a[i];
        int mx = a[i];
        while (j < n && mx - mn <= 2 * x) {
            ++j;
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
        }
        i = j - 1;
    }
    cout << ans << '\n';
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