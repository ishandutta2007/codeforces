#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    const ll R = 50000;
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    vector<ll> a(n), pieces;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (ll k = 1; k <= R; k++) {
            pieces.push_back((a[i] + k - 1) / k - 1);
            pieces.push_back((a[i] + k - 1) / k);
            pieces.push_back((a[i] + k - 1) / k + 1);
        }
    }
    sort(pieces.begin(), pieces.end());
    pieces.resize(unique(pieces.begin(), pieces.end()) - pieces.begin());
    if (pieces.front() == 0)
        pieces.erase(pieces.begin());
    pieces.push_back(1e12);

    auto get = [&](ll d) {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += (a[i] + d - 1) / d * d - a[i];
        return sum;
    };

    for (ll d = 1; d <= R; d++) {
        if (get(d) <= k)
            ans = d;
    }
    int m = pieces.size();
    vector<ll> val(m);
    for (int i = 0; i < m; i++) {
        val[i] = get(pieces[i]);
        if (i && val[i - 1] <= k && val[i - 1] < val[i]) {
            if ((val[i] - val[i - 1]) % (pieces[i] - pieces[i - 1]))
                continue;
            ll slope = (val[i] - val[i - 1]) / (pieces[i] - pieces[i - 1]);
            ans = max(ans, pieces[i - 1] + min(pieces[i] - pieces[i - 1], (k - val[i - 1]) / slope));
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