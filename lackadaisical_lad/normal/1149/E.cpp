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
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> mex(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }
    vector<int> used(n);
    vector<int> grundy(n);
    function<void(int)> dfs = [&](int v) -> void {
        used[v] = 1;
        vector<int> s(g[v].size() + 1);
        for (int u : g[v]) {
            if (!used[u]) {
                dfs(u);
            }
            if (mex[u] < s.size()) {
                s[mex[u]] = 1;
            }
        }
        while (s[mex[v]]) mex[v]++;
        grundy[mex[v]] ^= h[v];
    };
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i);
    }
    if (*max_element(grundy.begin(), grundy.end()) == 0) {
        cout << "LOSE\n";
        return;
    }
    int kek = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (grundy[i]) {
            kek = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mex[i] != kek) continue;
        if ((grundy[mex[i]] ^ h[i]) < h[i]) {
            h[i] ^= grundy[mex[i]];
            for (int j : g[i]) {
                h[j] ^= grundy[mex[j]];
                grundy[mex[j]] = 0;
            }
            break;
        }
    }
    cout << "WIN\n";
    for (int i = 0; i < n; i++) {
        cout << h[i] << " \n"[i + 1 == n];
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