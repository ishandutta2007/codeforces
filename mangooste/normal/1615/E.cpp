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

template<typename node>
struct segtree {
    int n;
    std::vector<node> tree;

    segtree(int n) : n(n), tree(4 * n, node()) {}

    template<typename T>
    segtree(const std::vector<T> &arr) : n(arr.size()), tree(4 * n) {
        build(1, 0, n, arr);
    }

    template<typename T>
    void build(int v, int vl, int vr, const std::vector<T> &arr) {
        if (vl == vr)
            return;

        if (vr - vl == 1) {
            tree[v] = node(arr[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, arr);
        build(v << 1 | 1, vm, vr, arr);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int size() const {
        return n;
    }

    template<typename... Args>
    void update(int l, int r, Args&&... args) {
        _update(1, 0, n, l, r, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void _update(int v, int vl, int vr, int l, int r, Args&&... args) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v].apply(std::forward<Args>(args)...);
            return;
        }

        tree[v].push(tree[v << 1]);
        tree[v].push(tree[v << 1 | 1]);
        tree[v].clear_after_push();

        int vm = (vl + vr) >> 1;
        _update(v << 1, vl, vm, l, r, std::forward<Args>(args)...);
        _update(v << 1 | 1, vm, vr, l, r, std::forward<Args>(args)...);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }

    node query(int l, int r) {
        assert(std::max(0, l) < std::min(n, r)); // or return node() in this case
        return _query(1, 0, n, l, r);
    }

    node _query(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return tree[v];

        tree[v].push(tree[v << 1]);
        tree[v].push(tree[v << 1 | 1]);
        tree[v].clear_after_push();

        int vm = (vl + vr) >> 1;
        if (r <= vm)
            return _query(v << 1, vl, vm, l, r);

        if (vm <= l)
            return _query(v << 1 | 1, vm, vr, l, r);

        return node::merge(_query(v << 1, vl, vm, l, r), _query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> tin(n), tout(n), parent(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            parent[u] = v;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    struct node {
        pair<int, int> best{-1e9, -1};
        int mod = 0;

        void apply(const pair<int, int> &p) {
            best = p;
        }

        void apply(int to_add) {
            mod += to_add;
            best.first += to_add;
        }

        void push(node &child) {
            child.apply(mod);
        }

        void clear_after_push() {
            mod = 0;
        }

        static node merge(const node &left, const node &right) {
            return {max(left.best, right.best), 0};
        }
    };

    segtree<node> tree(n);
    for (int i = 0; i < n; i++)
        tree.update(tin[i], tin[i] + 1, pair{0, i});

    for (int i = 0; i < n; i++)
        tree.update(tin[i], tout[i], 1);

    vector<bool> banned(n);
    int alive = n;
    ll answer = -1ll * (n / 2) * (n - n / 2);

    for (int it = 1; it <= k; it++) {
        int current = tree.query(0, n).best.second;
        tree.update(tin[current], tin[current] + 1, pair{-int(1e9), current});

        for (; !banned[current]; current = parent[current]) {
            banned[current] = true;
            alive--;
            tree.update(tin[current], tout[current], -1);
        }

        int take = min(alive, n / 2);
        answer = max(answer, 1ll * it * (n - it) - 1ll * take * (n - take));
    }

    cout << answer << '\n';
}