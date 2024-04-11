
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// choose one particular minimum spanning tree.
// Suppose all edge weights in tree are <= W
// Consider an edge not in the tree, with edge weight <= W.
// Then adding the edge, it creates a cycle.
// It should have strictly the maximum weight in this cycle.

const int N = 2e5 + 5;
int n, m, u, v, dsu[N];
ll w;
vector<tuple<ll, int, int>> edge;
vector<pair<int, ll>> adj[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

bool vis[N];
int par[N][20], tin[N], tout[N], t = 0;
ll mx[N][20];

void dfs(int x) {
    tin[x] = t++;
    vis[x] = true;
    for(auto &p : adj[x]) {
        auto [y, w] = p;
        if(!vis[y]) {
            par[y][0] = x;
            mx[y][0] = w;
            dfs(y);
        }
    }
    tout[x] = t++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int i = 19; i >= 0; i--) {
        if(!anc(par[x][i], y)) x = par[x][i];
    }
    return par[x][0];
}
ll getmx(int x, int c) {
    if(anc(x, c)) return LLONG_MIN;
    ll ans = LLONG_MIN;
    for(int i = 19; i >= 0; i--) {
        if(!anc(par[x][i], c)) {
            ans = max(ans, mx[x][i]);
            x = par[x][i];
        }
    }
    return max(ans, mx[x][0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + N, -1);
    rep(i, 0, m) {
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }
    sort(all(edge));
    ll W = -1;
    vector<tuple<ll, int, int>> ve;
    for(auto &p : edge) {
        tie(w, u, v) = p;
        if(trace(u) == trace(v)) {
            ve.push_back(p);
        }else {
            W = w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            join(u, v);
        }
    }
    par[1][0] = 1;
    dfs(1);
    for(int l = 1; l < 20; l++) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
            mx[i][l] = max(mx[i][l - 1], mx[par[i][l - 1]][l - 1]);
        }
    }

    ll ans = 0;
    for(auto &p : ve) {
        tie(w, u, v) = p;
        if(w <= W) {
            int c = lca(u, v);
            ll m = max(getmx(u, c), getmx(v, c));
            ans += max(0LL, m - w + 1);
        }
    }
    cout << ans << '\n';
}