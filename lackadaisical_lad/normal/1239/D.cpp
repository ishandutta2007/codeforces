#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), gr(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<int> used(n + 1);
    function<void(int, vector<vector<int>>&)> dfs = [&](int v, vector<vector<int>>& g) {
        used[v] = 1;
        for (int u : g[v]) {
            if (!used[u]) {
                dfs(u, g);
            } 
        }
    };
    dfs(1, g);
    if (*min_element(used.begin() + 1, used.end()) == 0) {
        vector<int> l, r;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                l.push_back(i);
            } else {
                r.push_back(i);
            }
        }
        cout << "Yes\n";
        cout << l.size() << ' ' << r.size() << '\n';
        for (int v : l) {
            cout << v << ' ';
        }
        cout << '\n';
        for (int v : r) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    used.assign(n + 1, 0);
    dfs(1, gr);
    if (*min_element(used.begin() + 1, used.end()) == 0) {
        vector<int> l, r;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                r.push_back(i);
            } else {
                l.push_back(i);
            }
        }
        cout << "Yes\n";
        cout << l.size() << ' ' << r.size() << '\n';
        for (int v : l) {
            cout << v << ' ';
        }
        cout << '\n';
        for (int v : r) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "No\n";
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