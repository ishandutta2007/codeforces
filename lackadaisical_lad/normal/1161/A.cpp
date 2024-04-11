#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        pos[x - 1].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = max(0, i - 1); j <= min(n - 1, i + 1); j++) {
            if (pos[i].empty()) {
                ans++;
                continue;
            }
            int x = pos[i][0];
            int y = pos[j].empty() ? -1 : pos[j].back();
            if (y < x) {
                ans++;
            }
        }
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