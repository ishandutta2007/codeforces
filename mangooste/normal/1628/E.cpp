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

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}
    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        int n = int(a.size());
        int lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);

        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    T query(int l, int r) const {
        assert(l < r);
        int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
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
            tree[v].apply(std::forward<Args>(args)..., vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        tree[v].push(tree[v << 1], vl, vm);
        tree[v].push(tree[v << 1 | 1], vm, vr);
        tree[v].clear_after_push();

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

        int vm = (vl + vr) >> 1;
        tree[v].push(tree[v << 1], vl, vm);
        tree[v].push(tree[v << 1 | 1], vm, vr);
        tree[v].clear_after_push();

        if (r <= vm)
            return _query(v << 1, vl, vm, l, r);

        if (vm <= l)
            return _query(v << 1 | 1, vm, vr, l, r);

        return node::merge(_query(v << 1, vl, vm, l, r), _query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> edges(n - 1);
    for (auto &[w, v, u] : edges) {
        cin >> v >> u >> w;
        v--, u--;
    }
    sort(all(edges));

    vector<int> parent(n), first(n), last(n), nxt(n, -1), nxt_cost(n);
    iota(all(parent), 0);
    iota(all(first), 0);
    iota(all(last), 0);

    auto root = y_combinator([&](auto root, int v) -> int {
        return parent[v] == v ? v : parent[v] = root(parent[v]);
    });

    for (auto [w, v, u] : edges) {
        v = root(v);
        u = root(u);
        parent[u] = v;
        nxt[last[u]] = first[v];
        nxt_cost[last[u]] = w;
        first[v] = first[u];
    }

    vector<int> costs, order;
    for (int v = first[root(0)]; v != -1; v = nxt[v]) {
        order.push_back(v);
        costs.push_back(nxt_cost[v]);
    }
    costs.pop_back();

    auto merge = [](const int x, const int y) { return max(x, y); };
    sparse_table<int, decltype(merge)> sparse(costs, merge);

    vector<int> where(n);
    for (int i = 0; i < n; i++)
        where[order[i]] = i;

    struct node {
        int max_where = -1, min_where = 1e9, cur_max = -1, cur_min = 1e9, mod = -1;

        void apply(int type, int value, int l, int r) {
            if (type == 0) {
                max_where = min_where = value;
            } else if (type == 1) {
                if (value == 1) {
                    cur_max = max_where;
                    cur_min = min_where;
                } else {
                    cur_max = -1;
                    cur_min = 1e9;
                }
                mod = value;
            } else {
                assert(false);
            }
        }

        void push(node &child, int l, int r) {
            if (mod != -1)
                child.apply(1, mod, l, r);
        }

        void clear_after_push() {
            mod = -1;
        }

        static node merge(const node &left, const node &right) {
            return {
                max(left.max_where, right.max_where),
                min(left.min_where, right.min_where),
                max(left.cur_max, right.cur_max),
                min(left.cur_min, right.cur_min),
                -1
            };
        }
    };

    segtree<node> tree(n);
    for (int i = 0; i < n; i++)
        tree.update(i, i + 1, 0, where[i]);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            tree.update(l, r, 1, type == 1);
        } else if (type == 3) {
            int v;
            cin >> v;
            v--;

            auto cur = tree.query(0, n);
            int answer = -1;
            if (cur.cur_min < where[v])
                answer = max(answer, sparse.query(cur.cur_min, where[v]));

            if (cur.cur_max > where[v])
                answer = max(answer, sparse.query(where[v], cur.cur_max));

            cout << answer << '\n';
        } else {
            assert(false);
        }
    }
}