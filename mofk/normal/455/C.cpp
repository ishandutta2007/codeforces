#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 3e5 + 5, INF = 1e9;

int n, m, q, id, mx;
int dad[MAX];
int d[MAX];
bool vis[MAX], visw[MAX];
vector <vi> a;
int h[MAX];
vi V;

int anc(int u) {
    if (dad[u] == u) return u;
    return dad[u] = anc(dad[u]);
}

void join(int u, int v) {
    int p = anc(u), q = anc(v);
    if (p == q) return;
    dad[q] = p;
    d[p] = max(max(d[p], d[q]), (d[p] + 1) / 2 + (d[q] + 1) / 2 + 1);
}

void dfs_down(int u) {
    V.pb(u);
    if (mx < h[u]) { mx = h[u]; id = u; }
    vis[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (vis[v]) continue;
        h[v] = h[u] + 1;
        dfs_down(v);
    }
}

void dfs_up(int u) {
    visw[u] = 1;
    if (mx < d[u]) { mx = d[u]; }
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (visw[v]) continue;
        d[v] = d[u] + 1;
        dfs_up(v);
    }
}

void init(void) {
    scanf("%d%d%d", &n, &m, &q);
    ff(i, 1, n) dad[i] = i;
    a.assign(n + 1, vi());
    ff(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
        a[v].pb(u);
        join(u, v);
    }
}

void process(void) {
    memset(d, 0, sizeof d);
    ff(i, 1, n) if (!vis[i]) {
        V.clear();
        id = mx = 0;
        dfs_down(i);
        mx = 0;
        dfs_up(id);
        for (int j = 0; j < V.size(); j++) d[V[j]] = mx;
    }
    ff(i, 1, q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int u; scanf("%d", &u);
            printf("%d\n", d[anc(u)]);
        }
        else {
            int u, v; scanf("%d%d", &u, &v);
            join(u, v);
        }
    }
}

int main(void) {
    init();
    process();
    return 0;
}