#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 1e5 + 5;
const int LOG = 18;

int n, q;
int a[N];
vec< int > g[N];
int root = 1;
int par[LOG][N];
int tin[N];
int tout[N];
int height[N];

ll delt[8 * N];
ll tree[8 * N];

void push(int v, int tl, int tm, int tr) {
    if(!delt[v]) return;
    delt[v << 1] += delt[v];
    delt[v << 1 | 1] += delt[v];
    tree[v << 1] += 1ll * (tm - tl + 1) * delt[v];
    tree[v << 1 | 1] += 1ll * (tr - tm) * delt[v];
    delt[v] = 0;
}

void merge(int v) {
    tree[v] = tree[v << 1] + tree[v << 1 | 1];
}

void update_tree(int v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        delt[v] += x;
        tree[v] += 1ll * x * (tr - tl + 1);
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        if(l <= tm) {
            update_tree(v << 1, tl, tm, l, r, x);
        }
        if(r > tm) {
            update_tree(v << 1 | 1, tm + 1, tr, l, r, x);
        }
        merge(v);
    }
}

ll get_sum(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return tree[v];
    }else {
        int tm = (tl + tr) >> 1;
        push(v, tl, tm, tr);
        ll res = 0;
        if(l <= tm) {
            res += get_sum(v << 1, tl, tm, l, r);
        }
        if(r > tm) {
            res += get_sum(v << 1 | 1, tm + 1, tr, l, r);
        }
        merge(v);
        return res;
    }
}

void dfs(int v, int dfs_par = -1) {
    height[v] = v == 1 ? 0 : height[dfs_par] + 1;
    par[0][v] = dfs_par;
    static int timer = 1;
    tin[v] = timer++;
    for(int to : g[v]) {
        if(to == dfs_par) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

inline int _get_lca(int u, int v) {
    if(height[u] < height[v]) swap(u, v);
    for(int j = LOG - 1;j >= 0;j--) {
        int pu = par[j][u];
        if(pu == -1 || height[pu] < height[v]) continue;
        u = pu;
    }
    for(int j = LOG - 1;j >= 0;j--) {
        int pu = par[j][u];
        int pv = par[j][v];
        if(pu == -1 || pv == -1 || pu == pv) continue;
        u = pu;
        v = pv;
    }
    if(u != v) u = par[0][u];
    return u;
}

inline int get_lca(int u, int v) {
    int w = _get_lca(u, v);
    if(w == root) return w;
    if(tin[root] < tin[w] && tout[w] < tout[root]) {
        return w;
    }
    if(tin[w] < tin[root] && tout[root] < tout[w]) {
        int w1 = _get_lca(u, root);
        int w2 = _get_lca(v, root);
        int d1 = height[root] - height[w1];
        int d2 = height[root] - height[w2];
        return d1 <= d2 ? w1 : w2;
    }
    return w;
}

int get_jump(int v, int d) {
    // for 1 .. d : v = par[0][v]
    for(int j = 0;j < LOG;j++) {
        if((1 << j) & d) {
            v = par[j][v];
        }
    }
    return v;
}

void update(int u, int v, int x) {
    int w = get_lca(u, v);
    if(w == root) {
        update_tree(1, 1, n + n, 1, n + n, x);
        return;
    }
    if(tin[root] < tin[w] && tout[w] < tout[root]) {
        update_tree(1, 1, n + n, tin[w], tout[w], x);
        return;
    }
    if(tin[w] < tin[root] && tout[root] < tout[w]) {
        int dist = height[root] - height[w];
        int z = get_jump(root, dist - 1);
        update_tree(1, 1, n + n, 1, n + n, x);
        update_tree(1, 1, n + n, tin[z], tout[z], -x);
        return;
    }
    update_tree(1, 1, n + n, tin[w], tout[w], x);
}

ll query(int v) {
    if(v == root) {
        return get_sum(1, 1, n + n, 1, n + n) / 2;
    }
    if(tin[root] < tin[v] && tout[v] < tout[root]) {
        return get_sum(1, 1, n + n, tin[v], tout[v]) / 2;
    }
    if(tin[v] < tin[root] && tout[root] < tout[v]) {
        int dist = height[root] - height[v];
        int z = get_jump(root, dist - 1);
        return (get_sum(1, 1, n + n, 1, n + n) - get_sum(1, 1, n + n, tin[z], tout[z])) / 2;
    }
    return get_sum(1, 1, n + n, tin[v], tout[v]) / 2;
}

int main() {

    fill((int*)par, (int*)par + LOG * N, -1);

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    for(int v = 1;v <= n;v++) {
        update_tree(1, 1, n + n, tin[v], tin[v], a[v]);
        update_tree(1, 1, n + n, tout[v], tout[v], a[v]);
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

    for(int type, iter = 0;iter < q;iter++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &root);
        }else if(type == 2) {
            int u, v, x;
            scanf("%d %d %d", &u, &v, &x);
            update(u, v, x);
        }else if(type == 3) {
            int v;
            scanf("%d", &v);
#ifdef debug
            printf("%lld\n", query(v));
#else
            printf("%I64d\n", query(v));
#endif
        }
    }

    return 0;
}