#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

ll binpow(ll a, ll p, int mod = MOD) {
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
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    vector<int> id(n);
    vector<pair<int, int>> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        s.insert({0, i + 1});
    }
    sort(h.rbegin(), h.rend());
    for (int i = 0; i < n; i++) {
        auto p = *s.begin();
        s.erase(s.begin());
        p.first += h[i].first;
        id[h[i].second] = p.second;
        s.insert(p);
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << id[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}