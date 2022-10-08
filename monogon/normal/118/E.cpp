
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, u, v;
vector<int> adj[N], adjr[N];
vector<pair<int, int>> edges;
int t[N], par[N];
bool vis[N];
int c = 1;

void dfs(int x, int p) {
    par[x] = p;
    t[x] = c++;
    for(int y : adj[x]) {
        if(t[y] == 0) {
            dfs(y, x);
        }
    }
}

void dfs2(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs2(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    dfs(1, -1);
    for(int x = 1; x <= n; x++) {
        adj[x].clear();
    }
    for(auto p : edges) {
        tie(u, v) = p;
        if(par[v] == u || (par[u] != v && t[v] < t[u])) {
            adj[u].push_back(v);
            adjr[v].push_back(u);
        }else {
            adj[v].push_back(u);
            adjr[u].push_back(v);
        }
    }
    dfs2(1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << 0 << endl;
            return 0;
        }
        adj[i] = adjr[i];
    }
    fill(vis, vis + N, false);
    dfs2(1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int y : adj[i]) {
            cout << i << " " << y << endl;
        }
    }
}