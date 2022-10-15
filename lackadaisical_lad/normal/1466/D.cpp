#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        ans += w[i];
    }

    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
    }
    multiset<pair<int, int>> kek;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 1) {
            kek.insert({-w[i],deg[i] - 1});
        }
    }

    cout << ans << ' ';
    for (int i = 2; i < n; i++) {
        auto p = *kek.begin();
        kek.erase(kek.begin());
        ans -= p.first;
        p.second--;
        if (p.second) {
            kek.insert(p);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}