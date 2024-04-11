#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10, lim = 1e6;
 
int n, m, ans[nax];
 
void answer();
 
struct DSU {
    int n;
    int par[nax],  sz[nax];
 
    DSU ()  {}
    DSU (int n) {
        fill(sz + 1, sz + 1 + n, 1);
        iota(par + 1, par + 1 + n, 1);
    }
 
    int find (int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
 
    bool unite (int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        if (sz[u] == ::n) answer();
        par[v] = u;
 
        return true;
    }
};
 
vector<int> e[lim + 1];
pair< int, int> E[nax];
vector<pair<int, int> > a[nax];
 
 
bool vis[nax];
int low[nax];
int tin[nax];
int timer ; 
 
void dfs (int nod, int from_edge) {        
    vis[nod] = true;
    tin[nod] = ++ timer;
    low[nod] = tin[nod];
    for (auto it : a[nod]) {
        if (!vis[it.first]) {
            dfs(it.first, it.second);
            low[nod] = min(low[nod], low[it.first]);
            if (tin[nod] < low[it.first]) ans[it.second] = 1;
        } 
        else  if (it.second != from_edge){
            low[nod] = min(low[nod], tin[it.first]);
        }        
        
    }
} 
 
int main () {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m ; ++ i) {
        int w;
        scanf("%d %d %d", &E[i].first, &E[i].second, &w);
        e[w].push_back(i);
    }
 
    DSU ds(n);
    vector<int> to_clear ;
    for (int i = 1 ; i <= lim ; ++ i) {
        if (e[i].empty()) continue;
        for (int it : e[i]) {
 
            int u = ds.find(E[it].first), v = ds.find(E[it].second);
 
            if (u == v) {
                ans[it] = 0;
            }
            else {
                ans[it] = 2;
                to_clear.push_back(v);
                to_clear.push_back(u);
                a[u].emplace_back(v, it);
                a[v].emplace_back(u, it);
            }
        }
 
        timer = 0;

 
        for (int it : to_clear)
            if (!vis[it]) dfs(it, 0);
 
        for (int it : e[i])
            ds.unite(E[it].first, E[it].second);
 
 
        for (int it: to_clear) {
            a[it].clear();
            vis[it] = false;
        }
        to_clear.clear();
    }
 
}
void answer() {
    for (int i = 1 ; i <= m ; ++ i) {
        puts(ans[i] == 1 ? "any" : ans[i] == 2 ? "at least one" : "none");
    }
}