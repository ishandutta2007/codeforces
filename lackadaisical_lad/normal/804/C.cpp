#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
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
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        comp[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> comp[i][j];
        }
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> vis(n);
    vector<int> col(m + 1, -1);
    function<void(int)> dfs = [&](int i) {
        vis[i] = 1;
        set<int> kek;
        for (int j = 0; j <= comp[i].size(); j++) {
            kek.insert(j);
        }
        for (int v : comp[i]) {
            kek.erase(col[v]);
        }
        for (int v : comp[i]) {
            if (col[v] == -1) {
                col[v] = *kek.begin();
                kek.erase(kek.begin());
            }
        }
        for (int u : g[i]) {
            if (!vis[u]) dfs(u);
        }
    };
    dfs(0);
    for (int i = 1; i <= m; i++) {
        if (col[i] == -1) {
            col[i] = 0;
        }
    }
    cout << *max_element(col.begin(), col.end()) + 1 << endl;
    for (int i = 1; i <= m; i++) {
        cout << col[i] + 1 << " \n"[i == m];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}