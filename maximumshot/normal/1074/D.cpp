#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int Q = 4e5 + 5;

unordered_map< int, int > vs;
int tot = 0;
vec< pii > g[Q];
int color[Q], sz[Q], xr[Q];

int add_vertex(int v) {
    if(!vs.count(v)) {
        vs[v] = tot;
        color[tot] = tot;
        sz[tot] = 1;
        tot++;
    }
    return vs[v];
}


void dfs(int v, int par, int COLOR, int XR) {
    color[v] = COLOR;
    xr[v] = XR;
    for(pii ed : g[v]) {
        int to = ed.first;
        if(to == par) continue;
        int we = ed.second;
        dfs(to, v, COLOR, XR ^ we);
    }
}

void add_edge(int u, int v, int x) {
    if(color[u] == color[v]) return;
    if(sz[ color[u] ] > sz[ color[v] ]) {
        swap(u, v);
    }
    sz[ color[v] ] += sz[ color[u] ];
    g[u].push_back({v, x});
    g[v].push_back({u, x});
    dfs(u, v, color[v], xr[v] ^ x);
}

int query(int u, int v) {
    return color[u] == color[v] ? xr[u] ^ xr[v] : -1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int q;

    scanf("%d", &q);

    int last = 0;

    for(int iter = 0;iter < q;iter++) {
        if(last == -1) last = 1;
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int _l, _r, _x;
            scanf("%d %d %d", &_l, &_r, &_x);
            int l = _l ^ last;
            int r = _r ^ last;
            int x = _x ^ last;
            if(l > r) swap(l, r);
            l++, r++;
            l = add_vertex(l - 1);
            r = add_vertex(r);
            add_edge(l, r, x);
        }else {
            int _l, _r;
            scanf("%d %d", &_l, &_r);
            int l = _l ^ last;
            int r = _r ^ last;
            if(l > r) swap(l, r);
            l++, r++;
            l = add_vertex(l - 1);
            r = add_vertex(r);
            last = query(l, r);
            printf("%d\n", last);
        }
    }

    return 0;
}