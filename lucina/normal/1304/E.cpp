#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10 , lg = 18;
int n, dis[nax], up[nax][lg + 1], tin[nax], tout[nax], timer;
vector<int> a[nax];
 
void dfs(int nod, int pa) {
    tin[nod] = ++ timer;
    up[nod][0] = pa;
    for (int i : a[nod]) {
        if (i == pa) continue;
        dis[i] = dis[nod] + 1;
        dfs(i, nod);
    }
    tout[nod] = ++ timer;
}
inline bool ancestor (int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
inline int lca (int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int j = lg ; j >= 0 ; j --) {
        if (!ancestor(up[u][j], v))
            u = up[u][j];
    }
    return up[u][0] ;
}
inline int dist (int u, int v) {
    int lc = lca(u, v);
    return dis[u] + dis[v] - 2 * dis[lc];
}
 
bool query () {
    int x, y, u, v, k;
    scanf("%d %d %d %d %d", &x, &y, &u, &v, &k);
 
    int cur_dist = dist(u, v);
    if (cur_dist <= k && (cur_dist ^ k) % 2 == 0)
        return true;
 
    cur_dist = dist(u, x) + dist(v, y) + 1;
    if (cur_dist <= k && (cur_dist ^ k) % 2 == 0)
        return true;
 
    cur_dist = dist(u, y) + dist(v, x) + 1;
    if (cur_dist <= k && (cur_dist ^ k) % 2 == 0)
        return true;
 
    return false;
}
 
int main () {
    tout[0] = numeric_limits<int>::max();
 
    scanf("%d", &n);
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
 
    dfs(1, 0);
 
    for (int i = 1 ; i <= lg ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
 
    int q;
    for (scanf("%d", &q) ; q -- ;) {
        puts(query() ? "YES" : "NO");
    }
    /**
    3 2 1
      < <
    */
}
/*
    Good Luck
        -Lucina
*/