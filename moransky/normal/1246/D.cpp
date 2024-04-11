#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e5 + 5, S = 1e6 + 5;

int n, fa[N], sz[N], a[N], t, dep[N];
int len, d[S];

vector<int> g[N];

bool inline cmp(int x, int y) {
    return dep[x] < dep[y];
}

void dfs(int u) {
    sz[u] = 1;
    dep[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
        sz[u] += sz[v];
    }
    sort(g[u].begin(), g[u].end(), cmp);
    if (g[u].size()) dep[u] = dep[g[u].back()] + 1;
}

void dfs2(int u) {
    a[++t] = u;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (i) {
            int oo = dep[g[u][i - 1]];
            while (oo--) d[++len] = v;
        }
        dfs2(v);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", fa + i), g[fa[i]].pb(i);
    dfs(0);
    dfs2(0);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    printf("%d\n", len);
    for (int i = 1; i <= len; i++) printf("%d ", d[i]);
    return 0;
}