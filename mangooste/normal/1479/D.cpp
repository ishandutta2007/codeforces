#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

constexpr int N = 3e5 + 228, SZ = 2;
int MOD[SZ], BASE[SZ], POWER[SZ][N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x--;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < SZ; i++) {
        auto is_prime = [](int x) {
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };

        MOD[i] = rng() % int(3e8) + 7e8;
        while (!is_prime(MOD[i])) MOD[i]++;
        BASE[i] = rng() % MOD[i];
        if (!(BASE[i] & 1)) BASE[i]++;

        POWER[i][0] = 1;
        for (int j = 1; j < N; j++) {
            POWER[i][j] = 1ll * POWER[i][j - 1] * BASE[i] % MOD[i];
        }
    }

    struct node {
        int left = -1, right = -1;
        array<int, SZ> h;
        bool value;

        node(int value = 0) : value(value) {
            h.fill(value);
        }
        
        static array<int, SZ> merge(const node &left, const node &right, int len_right) {
            array<int, SZ> res;
            for (int i = 0; i < SZ; i++) {
                res[i] = right.h[i] + 1ll * left.h[i] * POWER[i][len_right] % MOD[i];
                if (res[i] >= MOD[i]) res[i] -= MOD[i];
            }
            return res;
        }
    };

    vector<node> tree;
    tree.reserve(6e6);

    auto new_node = [&](int value = 0) {
        tree.push_back(node(value));
        return len(tree) - 1;
    };

    int root = new_node();

    y_combinator([&](auto build, int v, int vl, int vr) -> void {
        if (vr - vl == 1) return;
        tree[v].left = new_node();
        tree[v].right = new_node();
        int vm = (vl + vr) >> 1;
        build(tree[v].left, vl, vm);
        build(tree[v].right, vm, vr);
    })(root, 0, n);

    auto update = y_combinator([&](auto update, int v, int vl, int vr, int pos) -> int {
        if (pos < vl || vr <= pos) return v;
        int u = new_node();
        if (vr - vl == 1) {
            tree[u] = node(tree[v].value ^ 1);
            return u;
        }

        tree[u] = tree[v];
        int vm = (vl + vr) >> 1;
        tree[u].left = update(tree[v].left, vl, vm, pos);
        tree[u].right = update(tree[v].right, vm, vr, pos);
        tree[u].h = node::merge(tree[tree[u].left], tree[tree[u].right], vr - vm);
        return u;
    });

    vector<int> roots(n);
    roots[0] = update(root, 0, n, a[0]);

    vector<int> p(n), pp(n), depth(n), tin(n), tout(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        if (depth[p[v]] - depth[pp[p[v]]] == depth[pp[p[v]]] - depth[pp[pp[p[v]]]]) {
            pp[v] = pp[pp[p[v]]];
        } else {
            pp[v] = p[v];
        }

        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            roots[u] = update(roots[v], 0, n, a[u]);
            p[u] = v;
            depth[u] = depth[v] + 1;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    auto lca = [&](int v, int u) {
        auto is_ancestor = [&](int v, int u) {
            return tin[v] <= tin[u] && tout[u] <= tout[v];
        };

        if (is_ancestor(v, u)) return v;
        while (true) {
            if (!is_ancestor(pp[v], u)) v = pp[v];
            else if (!is_ancestor(p[v], u)) v = p[v];
            else return p[v];
        }
        assert(false);
    };

    while (q--) {
        int v, u, l, r;
        cin >> v >> u >> l >> r;
        v--, u--, l--;

        auto query = y_combinator([&](auto query, int v, int vl, int vr, int pos) -> int {
            if (pos < vl || vr <= pos) return 0;
            if (vr - vl == 1) return tree[v].value;
            int vm = (vl + vr) >> 1;
            return query(tree[v].left, vl, vm, pos) ^ query(tree[v].right, vm, vr, pos);
        });

        int w = lca(v, u);
        if (l <= a[w] && a[w] < r && !(query(roots[v], 0, n, a[w]) ^ query(roots[u], 0, n, a[w]))) {
            cout << a[w] + 1 << '\n';
            continue;
        }

        cout << y_combinator([&](auto get, int v1, int v2, int vl, int vr) -> int {
            if (vr <= l || r <= vl || tree[v1].h == tree[v2].h) return -2;
            if (vr - vl == 1) {
                if (vl == a[w]) return -2;
                return vl;
            }
            int vm = (vl + vr) >> 1;
            int res = get(tree[v1].left, tree[v2].left, vl, vm);
            return res == -2 ? get(tree[v1].right, tree[v2].right, vm, vr) : res;
        })(roots[v], roots[u], 0, n) + 1 << '\n';
    }
}