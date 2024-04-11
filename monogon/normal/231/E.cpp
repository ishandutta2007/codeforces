
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// spanning tree. LCA. each new edge we contract into a cycle.
// build new tree of cycles.
// answer is 2^(# cycles on path in component tree)
// each node in component tree is either singleton or contracted cycle.
// Simple path allows repeat vertices, just not repeat edges.

const int N = 1e5 + 5, M = 1e9 + 7;
int n, m, u, v, k, dsu[N], par[N][20], depth[N];
vi adj[N];
ll pow2[N];

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
int tin[N], tout[N], t = 0;

void dfs(int x) {
    vis[x] = true;
    tin[x] = t++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y][0] = x;
            dfs(y);
        }
    }
    tout[x] = t++;
}
void dfs2(int x) {
    vis[x] = true;
    tin[x] = t++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y][0] = x;
            depth[y] = depth[x] + (dsu[y] != -1);
            dfs2(y);
        }
    }
    tout[x] = t++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}
int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int l = 19; l >= 0; l--) {
        if(!anc(par[x][l], y)) x = par[x][l];
    }
    return par[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow2[0] = 1;
    rep(i, 1, N) pow2[i] = (2 * pow2[i - 1]) % M;
    cin >> n >> m;
    fill(dsu + 1, dsu + n + 1, -1);
    vector<pii> edge, ve;
    rep(i, 0, m) {
        cin >> u >> v;
        ve.emplace_back(u, v);
        if(trace(u) != trace(v)) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            join(u, v);
        }else {
            edge.emplace_back(u, v);
        }
    }
    fill(dsu + 1, dsu + n + 1, -1);
    par[1][0] = 1;
    dfs(1);
    for(auto &p : edge) {
        tie(u, v) = p;
        while(!anc(u, v)) {
            join(u, par[u][0]);
            u = par[u][0];
        }
        while(v != u) {
            join(v, par[v][0]);
            v = par[v][0];
        }
    }
    rep(i, 1, n + 1) adj[i].clear();
    for(auto &p : ve) {
        tie(u, v) = p;
        if((u = trace(u)) != (v = trace(v))) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    u = trace(1);
    par[u][0] = u;
    depth[u] = (dsu[u] != -1);
    t = 0;
    fill(vis + 1, vis + n + 1, false);
    dfs2(u);
    for(int l = 1; l < 20; l++) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }

    cin >> k;
    while(k--) {
        cin >> u >> v;
        u = trace(u);
        v = trace(v);
        int c = lca(u, v);
        int d = depth[u] + depth[v] - 2 * depth[c] + (dsu[c] != -1);
        cout << pow2[d] << '\n';
    }
}