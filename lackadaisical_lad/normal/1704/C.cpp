#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    vector<int> seg(m);
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        seg[i] = a[(i + 1) % m] - a[i] - 1;
        if (seg[i] < 0)
            seg[i] += n;
    }
    sort(seg.rbegin(), seg.rend());
    int ans = 0;
    int days = 0;
    for (int i = 0; i < m; i++) {
        seg[i] -= days * 2;
        if (seg[i] <= 0)
            break;
        if (seg[i] == 1) {
            ans++;
            days++;
            continue;
        }
        ans += seg[i] - 1;
        days += 2;
    }
    cout << n - ans << '\n';
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