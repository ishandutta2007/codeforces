#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 4e5 + 5;
const int LOG = 20;

int n;
int p[N];
vector< int > g[N];

int tin[N], tout[N], timer = 1;
int height[N];
int first_pos[N];
int euler[N], sz;
pii rmq[LOG][N];
int _log[N];

void dfs(int v) {
    tin[v] = timer++;
    euler[sz++] = v;
    for(int to : g[v]) {
        dfs(to);
        euler[sz++] = v;
    }
    tout[v] = timer++;
}

void build_lca() {
    for(int v = 1;v <= n;v++) {
        first_pos[v] = -1;
    }
    for(int i = 0;i < sz;i++) {
        int v = euler[i];
        if(first_pos[v] == -1) {
            first_pos[v] = i;
        }
    }

    for(int i = 1;i <= sz;i++) {
        _log[i] = _log[i - 1] + 1;
        if((1 << _log[i]) > i) _log[i]--;
    }

    for(int i = 0;i < sz;i++) {
        int v = euler[i];
        rmq[0][i] = {height[v], v};
    }

    for(int j = 1;j < LOG;j++) {
        for(int i = 0;i + (1 << j) - 1 < sz;i++) {
            rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int get_lca(int x, int y) {
    int l = first_pos[x];
    int r = first_pos[y];
    if(l > r) swap(l, r);
    int len = r - l + 1;
    int lg = _log[len];
    return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]).second;
}

bool is_vertex_in_subtree(int S, int P) {
    return tin[P] <= tin[S] && tout[S] <= tout[P];
}

bool is_vertex_on_path(int v, pii path) {
    int s, t;
    tie(s, t) = path;
    int w = get_lca(s, t);
    return is_vertex_in_subtree(v, w) &&
           (is_vertex_in_subtree(s, v) || is_vertex_in_subtree(t, v));
}

bool is_one_path_in_second_path(pii small_path, pii big_path) {
    return is_vertex_on_path(small_path.first, big_path) &&
           is_vertex_on_path(small_path.second, big_path);
}

pii union_path(pii p1, pii p2) {
    set< int > q = {p1.first, p1.second, p2.first, p2.second};
    for(int s : q) {
        for(int t : q) {
            if(
                is_one_path_in_second_path(p1, {s, t}) &&
                is_one_path_in_second_path(p2, {s, t})
            ) {
                return {s, t};
            }
        }
    }
    return {-1, -1};
}

struct Node {
    int s, t;
};

Node merge(Node l, Node r) {
    if(l.s == -1 || r.s == -1) {
        return {-1, -1};
    }
    pii hlp = union_path({l.s, l.t}, {r.s, r.t});
    return {hlp.first, hlp.second};
}

Node tree[4 * N];
int handler[N];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = {handler[tl], handler[tl]};
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

void update(int v, int tl, int tr, int pos, int _handler) {
    if(tl == tr) {
        tree[v] = {_handler, _handler};
    }else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) {
            update(v << 1, tl, tm, pos, _handler);
        }else {
            update(v << 1 | 1, tm + 1, tr, pos, _handler);
        }
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }
}

pair< int, Node > get(int len, Node cur, int v, int tl, int tr) {
    if(tl == tr) {
        Node tot = merge(cur, tree[v]);
        if(tot.s != -1) return {len + 1, tot};
        else return {len, cur};
    }else {
        int tm = (tl + tr) >> 1;
        Node nd = merge(tree[v << 1], cur);
        if(nd.s != -1) {
            return get(len + tm - tl + 1, nd, v << 1 | 1, tm + 1, tr);
        }else {
            return get(len, cur, v << 1, tl, tm);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int v = 1;v <= n;v++) {
        scanf("%d", &p[v]);
        handler[ p[v] ] = v;
    }

    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[x].push_back(i);
        height[i] = height[x] + 1;
    }

    dfs(1);
    build_lca();

    build(1, 0, n - 1);

//    for(int l = 0;l < n;l++) {
//        for(int r = l;r < n;r++ ){
//            int s, t;
//            Node nd = get(1, 0, n - 1, l, r);
//            s = nd.s;
//            t = nd.t;
//            cout << "[" << l << " .. " << r << "] " << s << " --> " << t << "\n";
//        }
//    }

    int qsize;

    scanf("%d", &qsize);

    for(int qiter = 0;qiter < qsize;qiter++) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int u, v;
            scanf("%d %d", &u, &v);
            int pu = p[u];
            int pv = p[v];

            update(1, 0, n - 1, p[v], u);
            update(1, 0, n - 1, p[u], v);

            p[u] = pv;
            p[v] = pu;

            handler[pu] = v;
            handler[pv] = u;
        }else {
            printf("%d\n", get(0, {handler[0], handler[0]}, 1, 0, n - 1).first);
        }
    }

    return 0;
}