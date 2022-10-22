#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

struct DSU {
    int n;
    vec< int > p, sz;

    DSU(): n(0) { }

    DSU(int _n) : n(_n) {
        p.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int v = 1;v <= n;v++) {
            p[v] = v;
        }
    }

    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(rand() & 1) swap(u, v);
        p[u] = v;
        sz[v] += sz[u];
        return true;
    }

    int get_size(int v) {
        return sz[find(v)];
    }
};

const int N = 1e6 + 5;

int n;
int a[N];
vec< int > g[N];
int added[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec< int > perm(n);
    for(int i = 0;i < n;i++) perm[i] = i + 1;

    sort(ALL(perm), [&](int u, int v) {
        return a[u] < a[v];
    });

    DSU dsu_min(n), dsu_max(n);

    ll res = 0;
    ll help = 0;

    for(int iter = 0;iter < n;iter++) {
        int v = perm[iter];
        added[v] = 1;
        int tot = 1;
        for(int u : g[v]) {
            if(added[u]) {
                tot += dsu_max.get_size(u);
            }
        }
        for(int u : g[v]) {
            if(added[u]) {
                int tmp = dsu_max.get_size(u);
                res += 1ll * tmp * (tot - tmp - 1) * a[v];
                help += 1ll * tmp * a[v];
            }
        }
        for(int u : g[v]) {
            if(added[u]) {
                dsu_max.merge(v, u);
            }
        }
    }

    memset(added, 0, sizeof(int) * N);

    for(int iter = n - 1;iter >= 0;iter--) {
        int v = perm[iter];
        added[v] = 1;
        int tot = 1;
        for(int u : g[v]) {
            if(added[u]) {
                tot += dsu_min.get_size(u);
            }
        }
        for(int u : g[v]) {
            if(added[u]) {
                int tmp = dsu_min.get_size(u);
                res -= 1ll * tmp * (tot - tmp - 1) * a[v];
                help -= 1ll * tmp * a[v];
            }
        }
        for(int u : g[v]) {
            if(added[u]) {
                dsu_min.merge(v, u);
            }
        }
    }

    cout << res / 2 + help << "\n";

    return 0;
}