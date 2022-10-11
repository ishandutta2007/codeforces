#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct DSU {
    int n;
    vec<int> par, sz;

    DSU() {}
    DSU(int n) : n(n), par(n), sz(n, 1) { iota(all(par), 0); }

    inline int get_par(int v) {
        return par[v] == v ? v : par[v] = get_par(par[v]);
    }

    inline bool unite(int v, int u) {
        v = get_par(v), u = get_par(u);
        if (u == v) return false;
        if (sz[v] < sz[u]) swap(v, u);
        par[u] = v;
        sz[v] += sz[u];
        return true;
    }
};

const int N = 2e5 + 4;
vec<int> g[N];
int n, m, edges[N][3], ans[N], par[N], sz[N], dep[N];
bool in[N];
int timer, tin[N], tout[N], head[N];

inline int another(int i, int v) {
    return edges[i][0] ^ edges[i][1] ^ v;
}

void init(int v) {
    sz[v] = 1;
    for (auto i : g[v]) {
        int u = another(i, v);
        par[u] = v;
        g[u].erase(find(all(g[u]), i));
        dep[u] = dep[v] + 1;
        init(u);
        sz[v] += sz[u];
    }
    sort(all(g[v]), [&](int a, int b) { return sz[a] > sz[b]; });
}

void init_hld(int v) {
    tin[v] = timer++;
    for (int i = 0; i < len(g[v]); i++) {
        int u = another(g[v][i], v);
        head[u] = (i == 0 ? head[v] : u);
        init_hld(u);
    }
    tout[v] = timer;
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

struct HLD {
    struct segtree {
        int n;
        vec<int> tree;

        segtree() {}
        segtree(int n) : n(n), tree(2 * n, INT_MAX) {}

        inline void set(int pos, int val) {
            pos += n;
            tree[pos] = val;
            for (pos >>= 1; pos; pos >>= 1) {
                tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
            }
        }

        inline void setmin(int l, int r, int val) {
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) tree[l] = min(tree[l], val), l++;
                if (r & 1) r--, tree[r] = min(tree[r], val);
            }
        }

        inline int get_min(int l, int r) const {
            int res = INT_MAX;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = min(res, tree[l++]);
                if (r & 1) res = min(res, tree[--r]);
            }
            return res;
        }

        inline int get_pos(int pos) const {
            int res = INT_MAX;
            for (pos += n; pos; pos >>= 1) {
                res = min(res, tree[pos]);
            }
            return res;
        }
    };

    segtree tree;

    HLD() {}
    HLD(int n) : tree(n) {}

    inline void set(int v, int val) {
        tree.set(tin[v], val);
    }

    inline int get_min(int v, int u) {
        int res = INT_MAX;
        for (int rep = 0; rep < 2; rep++, swap(v, u)) {
            while (!is_par(head[v], u)) {
                res = min(res, tree.get_min(tin[head[v]], tin[v] + 1));
                v = par[head[v]];
            }
        }
        if (tin[v] > tin[u]) swap(v, u);
        res = min(res, tree.get_min(tin[v] + 1, tin[u] + 1));
        return res;
    }

    inline void setmin(int v, int u, int val) {
        for (int rep = 0; rep < 2; rep++, swap(v, u)) {
            while (!is_par(head[v], u)) {
                tree.setmin(tin[head[v]], tin[v] + 1, val);
                v = par[head[v]];
            }
        }
        if (tin[v] > tin[u]) swap(v, u);
        tree.setmin(tin[v] + 1, tin[u] + 1, val);
    }
};

HLD hld_edges, hld_ways;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--, edges[i][1]--;
    }
    vec<ar<int, 4>> all_edges;
    all_edges.reserve(m);
    for (int i = 0; i < m; i++) {
        all_edges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
    }
    sort(all(all_edges), [&](ar<int, 4> &a, ar<int, 4> &b) { return a[2] < b[2]; });
    DSU dsu(n);
    for (auto [v, u, w, i] : all_edges) {
        if (!dsu.unite(v, u)) continue;
        g[v].push_back(i);
        g[u].push_back(i);
        in[i] = true;
    }
    init(0);
    init_hld(0);
    hld_edges = hld_ways = HLD(n);
    for (int i = 0; i < m; i++) {
        if (!in[i]) continue;
        if (dep[edges[i][0]] > dep[edges[i][1]]) swap(edges[i][0], edges[i][1]);
        hld_edges.set(edges[i][1], -edges[i][2]);
    }
    for (int i = 0; i < m; i++) {
        if (in[i]) continue;
        hld_ways.setmin(edges[i][0], edges[i][1], edges[i][2] - 1);
    }
    for (int i = 0; i < m; i++) {
        if (in[i]) {
            int res = hld_ways.tree.get_pos(tin[edges[i][1]]);
            if (res == INT_MAX) res = -1;
            cout << res << ' ';
        } else {
            cout << -hld_edges.get_min(edges[i][0], edges[i][1]) - 1 << ' ';
        }
    }
    cout << '\n';
}