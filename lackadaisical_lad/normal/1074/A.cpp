#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vert(n);
    for (int i = 0; i < n; i++)
        cin >> vert[i];
    sort(vert.begin(), vert.end());
    vector<int> hor;
    int extra = 0;
    for (int i = 0; i < m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 > 1)
            continue;
        if (x2 == 1e9) {
            extra++;
            continue;
        }
        hor.push_back(x2);
    }
    sort(hor.begin(), hor.end());
    int ans = min(vert.size(), hor.size());
    int cnt = hor.size();
    for (int i = 0; i < n; i++) {
        while (cnt > 0 && hor[hor.size() - cnt] < vert[i])
            cnt--;
        ans = min(ans, i + cnt);
    }
    cout << ans + extra << '\n';
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