#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int n, m, dfn[N], dfncnt, low[N], sz[N];
int s[N], top, cnt, c[N];

bool ins[N];

vector<int> g[N];

void inline clear() {
    for (int i = 1; i <= n; i++) dfn[i] = low[i] = ins[i] = sz[i] = 0, g[i].clear();
    dfncnt = 0;
    top = cnt = 0;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++dfncnt;
    s[++top] = u, ins[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int v; ++cnt;
        do {
            v = s[top--], ins[v] = 0, c[v] = cnt, sz[cnt]++;
        } while (v != u);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1, a, b; i <= m; i++) {
            scanf("%d%d", &a, &b);
            g[a].pb(b);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) tarjan(i);
        
        if (cnt == 1) puts("No");
        else {
            puts("Yes");
            printf("%d %d\n", sz[1], n - sz[1]);
            for (int i = 1; i <= n; i++)
                if (c[i] == 1) printf("%d ", i);
            puts(""); 
            for (int i = 1; i <= n; i++)
                if (c[i] != 1) printf("%d ", i);
            puts("");
        }
        clear();
    }
    return 0;
}