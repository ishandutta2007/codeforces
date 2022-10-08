
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
int x[N], y[N], deg[N], par[N];
vector<int> adj[N];
bool vis[N];

// LCA of two leaves u and v.
// if LCA = u or LCA = v, this is the root
// otherwise, cut the branches of LCA that lead to u and v

int query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    cin >> u;
    return u;
}
int solve(int u) {
    return cout << "! " << u << endl, 0;
}
void dfs(int x, int p) {
    par[x] = p;
    for(int y : adj[x]) {
        if(par[y] == 0) dfs(y, x);
    }
}

void trim(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(y != par[x]) trim(y);
    }
}

int parent(int x) {
    int y = x;
    while(par[par[y]] != par[y]) y = par[y];
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> x[i] >> y[i];
        deg[x[i]]++;
        deg[y[i]]++;
        adj[x[i]].push_back(y[i]);
        adj[y[i]].push_back(x[i]);
    }
    while(true) {
        int u = -1, v = -1;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && deg[i] <= 1) {
                (u == -1 ? u : v) = i;
            }
        }
        if(deg[u] == 0) return solve(u);
        int w = query(u, v);
        if(w == u || w == v) return solve(w);
        fill(par, par + N, 0);
        dfs(w, w);
        trim(u = parent(u));
        trim(v = parent(v));
        deg[w] -= 2;
    }
}