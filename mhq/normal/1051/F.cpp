#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxLOG = 20;
const int maxN = (int)1e5 + 10;
int n, m;
ll val[maxN][maxLOG];
int up[maxN][maxLOG];
vector < pair < int, int > > g[maxN];
bool used[maxN];
set < int > extra;
int par[maxN];
int h[maxN];
void dfs(int v) {
    used[v] = true;
    for (auto t : g[v]) {
        int to = t.first;
        if (to == par[v]) {
            up[v][0] = t.first;
            val[v][0] = t.second;
            continue;
        }
        if (!used[to]) {
            par[to] = v;
            h[to] = h[v] + 1;
            dfs(to);
        }
        else {
            extra.insert(v);
            //extra.insert(to);
        }
    }
}
ll dist[maxN][45];
int sz = 1;
const ll INF = (ll)1e18;
void go_djk(int v) {
    //id[sz] = v;
    for (int i = 1; i <= n; i++) {
        dist[i][sz] = INF;
    }
    dist[v][sz] = 0;
    priority_queue < pair < ll, int > > q;
    q.push(make_pair(0, v));
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        int v = t.second;
        ll d = -t.first;
        if (d != dist[v][sz]) continue;
        for (auto t : g[v]) {
            int to = t.first;
            if (dist[to][sz] > d + t.second) {
                dist[to][sz] = d + t.second;
                q.push(make_pair(-dist[to][sz], to));
            }
        }
    }
    sz++;
}
void prepare() {
    dfs(1);
    for (int k = 0; k + 1 < maxLOG; k++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][k] == 0) continue;
            up[i][k + 1] = up[up[i][k]][k];
            val[i][k + 1] = val[i][k] + val[up[i][k]][k];
        }
    }
    for (int v : extra) {
        go_djk(v);
    }
}
ll lca(int u, int v) {
    if (h[u] < h[v]) {
        swap(u, v);
    }
    ll ans = 0;
    for (int i = maxLOG - 1; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) {
            ans += val[u][i];
            u = up[u][i];
        }
    }
    for (int i = maxLOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            ans += val[u][i];
            ans += val[v][i];
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (u != v) {
        ans += val[u][0];
        ans += val[v][0];
    }
    return ans;
}
void solve(int u, int v) {
    ll mn = INF;
    for (int i = 1; i < sz; i++) {
        mn = min(mn, dist[u][i] + dist[v][i]);
    }
    mn = min(mn, lca(u, v));
    cout << mn << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(make_pair(v, w));
        g[v].emplace_back(make_pair(u, w));
    }
    prepare();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        solve(u, v);
    }
    return 0;
}