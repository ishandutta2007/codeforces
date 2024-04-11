#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int pw(int a, long long b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * a * r % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}

int n, m, k;
long long c[500005];
map <long long, vector <pair <int, int>>> edge;
int dad[500005];
vector <int> changed;

int anc(int u) {
    if (dad[u] == u) return u;
    changed.push_back(u);
    dad[u] = anc(dad[u]);
    return dad[u];
}
bool join(int u, int v) {
    u = anc(u), v = anc(v);
    if (u == v) return 0;
    dad[v] = u;
    changed.push_back(v);
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        long long key = c[u] ^ c[v];
        edge[key].push_back(make_pair(u, v));
    }
    for (int i = 1; i <= n; ++i) dad[i] = i;
    int ans = 0;
    for (auto val: edge) {
        vector <pair <int, int>> &edges = val.second;
        for (auto u: changed) dad[u] = u;
        changed.clear();
        int cnt = n;
        for (auto e: edges) cnt -= join(e.first, e.second);
        ans = (ans + pw(2, cnt)) % mod;
    }
    int mul = pw(2, n);
    mul = ((1LL << k) - edge.size()) % mod * mul % mod;
    cout << (ans + mul) % mod << endl;
    return 0;
}