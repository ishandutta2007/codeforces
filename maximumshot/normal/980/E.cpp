#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e6 + 5;
const int LOG = 22;

int n, k;
vec< int > g[N];
int par[LOG][N];
int h[N];
int tin[N];
int tout[N];
int good[N];
int link[N];

void init() {
    for(int i = 1;i <= n;i++) {
        link[i] = i;
    }
}

int find(int x) {
    return link[x] == x ? x : link[x] = find(link[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(rand() & 1) swap(x, y);
    link[y] = x;
    return true;
}

void dfs(int v, int from = -1) {
    static int timer = 1;
    tin[v] = timer++;
    h[v] = from == -1 ? 0 : h[from] + 1;
    par[0][v] = from;
    for(int to : g[v]) {
        if(to == from) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

int get_lca(int u, int v) {
    if(h[u] < h[v]) swap(u, v);
    for(int i = LOG - 1;i >= 0;i--) {
        int pu = par[i][u];
        if(pu == -1 || h[pu] < h[v]) continue;
        u = pu;
    }
    for(int i = LOG - 1;i >= 0;i--) {
        int pu = par[i][u];
        int pv = par[i][v];
        if(pu == -1 || pv == -1 || pu == pv) continue;
        u = pu;
        v = pv;
    }
    if(u != v) u = par[0][u];
    return u;
}

int get_dist(int u, int v, int w = -1) {
    if(w == -1) {
        w = get_lca(u, v);
    }
    return h[u] + h[v] - 2 * h[w];
}

bool in_tree(int PAR, int SON) {
    return tin[PAR] <= tin[SON] && tout[SON] <= tout[PAR];
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    init();

    fill((int*)par, (int*)par + N * LOG, -1);

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int j = 1;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            int pv = par[j - 1][v];
            if(pv == -1) {
                par[j][v] = -1;
            }else {
                par[j][v] = par[j - 1][pv];
            }
        }
    }

    int need = n - k;

    good[n] = 1;
    need--;

    int root = n;

    for(int v = n - 1;v >= 1 && need > 0;v--) {
        if(find(v) == find(root)) continue;
        if(!in_tree(root, v) && !in_tree(v, root)) {
            int w = get_lca(v, root);
            int di = get_dist(v, root, w);
            if(di <= need) {
                need -= di;
                for(int u = v;;u = par[0][u]) {
                    good[u] = 1;
                    merge(u, root);
                    if(u == w) break;
                }
                for(int u = par[0][root];u != w;u = par[0][u]) {
                    good[u] = 1;
                    merge(u, root);
                }
                root = w;
            }
        }else if(in_tree(root, v)) {
            int u = v;
            for(int j = LOG - 1;j >= 0;j--) {
                int pu = par[j][u];
                if(pu == -1) continue;
                if(in_tree(pu, root)) continue;
                if(good[pu]) continue;
                u = pu;
            }
            u = par[0][u];
            int di = h[v] - h[u];
            if(di <= need) {
                need -= di;
                for(u = v;!good[u];u = par[0][u]) {
                    good[u] = 1;
                    merge(u, root);
                }
            }
        }else {
            int di = h[root] - h[v];
            if(di <= need) {
                need -= di;
                for(int u = par[0][root];;u = par[0][u]) {
                    good[u] = 1;
                    merge(u, root);
                    if(u == v) break;
                }
                root = v;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        if(!good[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}