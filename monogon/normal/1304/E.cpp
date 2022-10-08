
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// find either:
// 1. shortest path from a to b in tree.
// 2. shortest path that goes through x->y
// 3. shortest path that goes through y->x
// make sure one of them has the same parity of k and is at most k.

// shortest path found by depth + LCA

const int N = 1e5 + 5;
int n, q, u, v, x, y, a, b, par[N][20], depth[N], tin[N], tout[N];
ll k;
bool vis[N];
vector<int> adj[N];
int t = 0;

void dfs(int x) {
    vis[x] = true;
    tin[x] = t++;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y][0] = x;
            depth[y] = depth[x] + 1;
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
    for(int k = 19; k >= 0; k--) {
        if(!anc(par[x][k], y)) {
            x = par[x][k];
        }
    }
    return par[x][0];
}
int dist(int x, int y) {
    int c = lca(x, y);
    return depth[x] - 2 * depth[c] + depth[y];
}
bool check(int d, int k) {
    return d <= k && (d % 2) == (k % 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1][0] = 1;
    depth[1] = 0;
    dfs(1);
    for(int k = 1; k < 20; k++) {
        for(int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
    cin >> q;
    while(q--) {
        cin >> x >> y >> a >> b >> k;
        if(check(dist(a, b), k) || check(dist(a, x) + dist(y, b) + 1, k) || check(dist(a, y) + dist(x, b) + 1, k)) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}