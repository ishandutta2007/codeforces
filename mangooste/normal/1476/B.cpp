#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using int128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for (auto &x : p)
        cin >> x;

    ll l = -1, r = ll(1e18);
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        pair<int128, int128> all{0, 1};
        int128 sum = p[0] + mid;

        bool all_is_ok = true;
        for (int i = 1; i < n && all_is_ok; i++) {
            all_is_ok &= int128(100) * p[i] <= k * sum;
            sum += p[i];
        }

        if (all_is_ok)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}