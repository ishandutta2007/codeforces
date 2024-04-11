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

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    vector<int> sz(n), label(n), parent(n, -1);

    y_combinator([&](auto dfs, int v) -> void {
        sz[v] = 1;
        for (auto &[u, i] : g[v]) {
            g[u].erase(find(all(g[u]), pair{v, i}));
            label[u] = i;
            parent[u] = v;
            dfs(u);
            sz[v] += sz[u];
        }
        nth_element(g[v].begin(), all(g[v]), [&](const auto v, const auto u) {
            return sz[v.first] > sz[u.first];
        });
    })(0);

    vector<int> tin(n), tout(n), head(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        for (int i = 0; i < len(g[v]); i++) {
            int u = g[v][i].first;
            head[u] = i == 0 ? head[v] : u;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    struct node {
        array<ll, 2> sums{0, 0};
        array<int, 2> cnt{0, 0};
        int mod = 0;

        void apply(int label, int l, int r) {
            sums[0] += label;
            cnt[0]++;
        }

        void apply(int l, int r) {
            mod ^= 1;
            swap(sums[0], sums[1]);
            swap(cnt[0], cnt[1]);
        }

        void push(node &child, int l, int r) {
            if (mod)
                child.apply(l, r);
        }

        void clear_after_push() {
            mod = 0;
        }

        static node merge(const node &left, const node &right) {
            return {array{left.sums[0] + right.sums[0], left.sums[1] + right.sums[1]},
                array{left.cnt[0] + right.cnt[0], left.cnt[1] + right.cnt[1]},
                0};
        }
    };

    segtree<node> tree(n);
    for (int i = 0; i < n; i++)
        tree.update(tin[i], tin[i] + 1, label[i]);

    auto flip = [&](int v) {
        for (; v != -1; v = parent[head[v]])
            tree.update(tin[head[v]], tin[v] + 1);
    };

    flip(0);
    for (int type, tot = 1;;) {
        cin >> type;

        if (type == 1) {
            int v;
            cin >> v;
            v--;
            tot++;

            flip(v);
            if (tree.query(0, n).cnt[1] * 2 == tot)
                cout << tree.query(0, n).sums[1] << endl;
            else
                cout << 0 << endl;
        } else if (type == 2) {
            if (tree.query(0, n).cnt[1] * 2 != tot) {
                cout << 0 << endl;
                continue;
            }

            vector<int> inds;
            inds.reserve(n / 2);
            for (int i = 0; i < n; i++)
                if (tree.query(tin[i], tin[i] + 1).cnt[1])
                    inds.push_back(label[i]);

            sort(all(inds));
            cout << tot / 2;
            for (auto id : inds)
                cout << ' ' << id;

            cout << endl;
        } else if (type == 3) {
            break;
        } else {
            assert(false);
        }
    }
}