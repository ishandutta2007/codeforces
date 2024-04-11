#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
 
vector <int> adj[N], po[N];
int vis[N], fa[N], dep[N];
int T, n, m, ans;
 
void dfs1(int u) {
    if (ans) return;
    if (dep[u] >= (n + 1) / 2) {
        printf("PATH\n%d\n", (n + 1) / 2);
        ans = 1;
        int now = u;
        while (now) {
            printf("%d ", now);
            now = fa[now];
        }
        printf("\n");
        return;
    }
    vis[u] = 1; po[dep[u]].push_back(u);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]) continue;
        fa[v] = u; dep[v] = dep[u] + 1; dfs1(v);
    }
}
 
int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) adj[i].clear(), po[i].clear(), vis[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dep[1] = 1; dfs1(1);
        if (!ans) {
            printf("PAIRING\n");
            vector < pair <int, int> > res;
            for (int i = 1; i <= (n - 1) / 2; i++) {
                for (int j = 1; j < (int)po[i].size(); j += 2) {
                    res.push_back(make_pair(po[i][j - 1], po[i][j]));
                }
            }
            printf("%d\n", (int)res.size());
            for (int i = 0; i < (int)res.size(); i++) printf("%d %d\n", res[i].first, res[i].second);
        }
    }
    return 0;
}