
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4e5 + 5;
int n, m, u, v;
int t[N], t2[N], l[N], dsu[N], par[N];
vector<int> adj[N];
vector<pair<int, int>> edges;
int c = 1;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

void dfs(int x) {
    t[x] = c++;
    for(int y : adj[x]) {
        if(t[y] == 0) {
            par[y] = x;
            dfs(y);
        }
    }
    l[x] = t[x];
    for(int y : adj[x]) {
        if(par[x] == y) continue;
        if(t[y] < t[x]) {
            l[x] = min(l[x], t[y]);
        }else {
            l[x] = min(l[x], l[y]);
            if(l[y] < t[y]) {
                join(x, y);
            }
        }
    }
}
void dfs2(int x) {
    t2[x] = c++;
    for(int y : adj[x]) {
        if(t2[y] == 0) dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + N, -1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.emplace_back(u, v);
    }
    dfs(1);
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        if(dsu[i] < dsu[idx]) idx = i;
    }
    c = 1;
    dfs2(idx);
    cout << -dsu[idx] << endl;
    for(auto p : edges) {
        tie(u, v) = p;
        if(trace(u) != trace(v)) {
            if(t2[u] < t2[v]) swap(u, v);
        }else if(par[u] == v || par[v] == u) {
            if(par[u] == v) swap(u, v);
        }else if(t[u] < t[v]) {
            swap(u, v);
        }
        cout << u << " " << v << endl;
    }
}