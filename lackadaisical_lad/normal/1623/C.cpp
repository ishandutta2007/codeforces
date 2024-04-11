#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll l = 0, r = 1e9 + 5;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        auto a = h;
        for (int i = n - 1; i >= 2; i--) {
            ll d = min((a[i] - mid) / 3, h[i] / 3);
            d = max(0LL, d);
            a[i - 2] += d * 2;
            a[i - 1] += d;
            a[i]     -= d * 3;
        }
        if (*min_element(a.begin(), a.end()) >= mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
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