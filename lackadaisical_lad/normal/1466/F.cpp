#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

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

const int N = 5e5 + 5;

int p[N], full[N];

int getRoot(int v) {
    return p[v] == v ? v : p[v] = getRoot(p[v]);
}

bool unite(int v, int u) {
    v = getRoot(v);
    u = getRoot(u);
    if (v == u) return false;
    if (full[v] && full[u]) {
        return false;
    }
    p[u] = v;
    full[v] |= full[u];
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    iota(p, p + m, 0);
    ll sz = 1;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int v;
            cin >> v;
            v = getRoot(v - 1);
            if (!full[v]) {
                full[v] = 1;
                sz = sz * 2 % mod;
                ans.push_back(i);
            }
        }
        if (k == 2) {
            int v, u;
            cin >> v >> u;
            v--;
            u--;
            if (unite(v, u)) {
                sz = sz * 2 % mod;
                ans.push_back(i);
            }
        }
    }

    cout << sz << ' ' << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}