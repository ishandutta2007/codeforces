#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
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
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> h(n + 1);
    auto bfs = [&](int root) {
        h.assign(n + 1, 0);
        queue<int> q;
        q.push(root);
        h[root] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (!h[u]) {
                    h[u] = h[v] + 1;
                    q.push(u);
                }
            }
        }
    };
    bfs(a);
    if (h[b] <= da + 1) {
        cout << "Alice\n";
        return;
    }
    int low = 1;
    for (int i = 1; i <= n; i++) {
        if (h[i] > h[low]) {
            low = i;
        }
    }
    bfs(low);
    int diam = *max_element(h.begin(), h.end()) - 1;
    if (da * 2 >= diam || da * 2 >= db) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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