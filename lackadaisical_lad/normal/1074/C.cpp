#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    int ans3 = 0;
    auto maxx = *max_element(x.begin(), x.end());
    auto minx = *min_element(x.begin(), x.end());
    auto maxy = *max_element(y.begin(), y.end());
    auto miny = *min_element(y.begin(), y.end());
    for (int i = 0; i < n; i++) {
        ans3 = max(ans3, x[i] - minx + y[i] - miny);
        ans3 = max(ans3, x[i] - minx + maxy - y[i]);
        ans3 = max(ans3, maxx - x[i] + y[i] - miny);
        ans3 = max(ans3, maxx - x[i] + maxy - y[i]);
    }
    ans3 *= 2;
    cout << ans3 << ' ';
    int ans4 = (maxx - minx + maxy - miny) * 2;
    for (int i = 4; i <= n; i++)
        cout << ans4 << ' ';
    cout << '\n';
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