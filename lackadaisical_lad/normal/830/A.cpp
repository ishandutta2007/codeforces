#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(k);
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = -1, r = 2e9 + 5;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll cur = -1;
        for (int i = 0; i < n && cur < k; i++) {
            ++cur;
            while (cur < k && abs(a[i] - b[cur]) + abs(b[cur] - p) > mid)
                ++cur;
        }
        if (cur == k)
            l = mid;
        else
            r = mid;
    }
    cout << r << '\n';
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