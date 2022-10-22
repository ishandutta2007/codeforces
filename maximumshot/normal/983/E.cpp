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
const ll inf64 = ll(1e18);

const int N = 2e5 + 5;
const int LOG = 22;

int n, m;
int link[LOG][N];
int par[LOG][N];
vec< int > g[N];
int h[N];
pii path[N];
pii mn[N]; // {h, v}

void read_input() {
    fill((int*)par, (int*)par + N * LOG, -1);
    scanf("%d", &n);
    for(int i = 2;i <= n;i++) {
        scanf("%d", &par[0][i]);
        h[i] = h[par[0][i]] + 1;
        g[par[0][i]].push_back(i);
    }
    for(int v = 1;v <= n;v++) {
        mn[v] = make_pair(h[v], v);
    }
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
}

inline int get_lca(int x, int y) {
    if(h[x] < h[y]) swap(x, y);
    for(int j = LOG - 1;j >= 0;j--) {
        int px = par[j][x];
        if(px == -1 || h[px] < h[y]) continue;
        x = px;
    }
    for(int j = LOG - 1;j >= 0;j--) {
        int px = par[j][x];
        int py = par[j][y];
        if(px == -1 || py == -1 || px == py) continue;
        x = px;
        y = py;
    }
    if(x != y) x = par[0][x];
    return x;
}

void dfs_mn(int v) {
    for(int to : g[v]) {
        dfs_mn(to);
        mn[v] = min(mn[v], mn[to]);
    }
}

void build_link() {
    fill((int*)link, (int*)link + LOG * N, -1);
    for(int v = 1;v <= n;v++) {
        link[0][v] = mn[v].second;
    }
    for(int j = 1;j < LOG;j++) {
        for(int v = 1;v <= n;v++) {
            int lv = link[j - 1][v];
            if(lv == -1) {
                link[j][v] = -1;
            }else {
                link[j][v] = link[j - 1][lv];
            }
        }
    }
}

void read_bus() {
    scanf("%d", &m);
    for(int w, u, v, iter = 1;iter <= m;iter++) {
        scanf("%d %d", &u, &v);
        path[iter] = {u, v};
        w = get_lca(u, v);
        mn[u] = min(mn[u], make_pair(h[w], w));
        mn[v] = min(mn[v], make_pair(h[w], w));
    }
    dfs_mn(1);
    build_link();
}

inline int query(int x, int y, int &nx, int &ny) {
    nx = ny = -1;
    if(h[x] < h[y]) swap(x, y);
    int z = get_lca(x, y);
    if(z == y) { // vertical
        int res = 0;
        for(int j = LOG - 1;j >= 0;j--) {
            int lx = link[j][x];
            if(lx == -1 || h[lx] <= h[y]) continue;
            x = lx;
            res += (1 << j);
        }
        x = link[0][x];
        if(x != -1 && h[x] <= h[y]) {
            res++;
        }else {
            res = -1;
        }
        return res;
    }

    int res = 0;
    int w = z;

    for(int j = LOG - 1;j >= 0;j--) {
        int lx = link[j][x];
        if(lx == -1 || h[lx] <= h[w]) continue;
        x = lx;
        res += (1 << j);
    }

    for(int j = LOG - 1;j >= 0;j--) {
        int ly = link[j][y];
        if(ly == -1 || h[ly] <= h[w]) continue;
        y = ly;
        res += (1 << j);
    }

    int lx = link[0][x];
    int ly = link[0][y];

    if(lx == -1 || ly == -1 || h[lx] > h[w] || h[ly] > h[w]) {
        return -1;
    }

    nx = x;
    ny = y;

    return res;
}

vec< pii > ask[N];
int tin[N];
int tout[N];

void prep(int v) {
    static int timer = 1;
    tin[v] = timer++;
    for(int to : g[v]) {
        prep(to);
    }
    tout[v] = timer++;
}

set< int > pts[N];

void calc(int v, vec< int > &result) {

    for(int to : g[v]) {
        calc(to, result);
        if(pts[to].size() > pts[v].size()) {
            swap(pts[to], pts[v]);
        }
        for(int x : pts[to]) {
            pts[v].insert(x);
        }
    }

    for(pii pr : ask[v]) {
        int u, id;
        tie(u, id) = pr;
        int le = tin[u];
        int ri = tout[u];
        auto fnd = pts[v].lower_bound(le);
        if(fnd != pts[v].end() && *fnd <= ri) {
            result[id]++;
        }else {
            result[id] += 2;
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    read_input();
    read_bus();

    int q;

    scanf("%d", &q);

    vec< int > result(q);

    for(int x, y, iter = 0;iter < q;iter++) {
        scanf("%d %d", &x, &y);
        int nx, ny;
        nx = ny = -1;
        result[iter] = query(x, y, nx, ny);
        if(nx != -1) {
            ask[nx].push_back({ny, iter});
        }
    }

    prep(1);

    for(int i = 1;i <= m;i++) {
        int u, v;
        tie(u, v) = path[i];
        pts[u].insert(tin[v]);
        pts[v].insert(tin[u]);
    }

    calc(1, result);

    for(int x : result) {
        printf("%d\n", x);
    }

    return 0;
}