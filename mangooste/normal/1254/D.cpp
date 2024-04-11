#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template<int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template<typename T>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template<typename T>
    mint power(T degree) const {
        degree = normalize(degree, mod - 1);
        mint prod = 1;
        mint a = *this;

        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(-1);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % mod;
        return *this;
    }

    mint& operator/=(const mint &x) {
        return *this *= x.inv();
    }

    friend mint operator+(const mint &x, const mint &y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    mint operator++(int) {
        value++;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint operator--(int) {
        value--;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        cin >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = int(bit.size()) - 1;

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

template<typename T>
struct graph {
    struct edge {
        int from, to;
        T cost;
    };

    int n;
    std::vector<edge> edges;
    std::vector<std::vector<int>> g;

    graph(int n = 0) : n(n), g(n) {}

    int size() const {
        return n;
    }

    void resize(int new_n) {
        n = new_n;
        g.resize(new_n);
    }

    void reserve(int mem) {
        edges.reserve(mem);
    }

    int another(int id, int v) const {
        return v ^ edges[id].from ^ edges[id].to;
    }

    virtual int add(int from, int to, T cost) = 0;
};

template<typename T>
struct forest : public graph<T> {
    using graph<T>::n;
    using graph<T>::edges;
    using graph<T>::g;

    std::vector<int> root;
    std::vector<int> parent;
    std::vector<int> previous_edge;
    std::vector<int> depth;
    std::vector<int> subtree_size;
    std::vector<T> dist;
    std::vector<int> tin;
    std::vector<int> tout;

    forest(int n = 0) : graph<T>(n) {}

    int add(int from, int to, T cost = T(1)) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = int(edges.size());
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }

    bool is_parent(int v, int u) const {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }

    bool is_root(int v) const {
        return root[v] == v;
    }

    bool connected(int v, int u) const {
        return root[v] == root[u];
    }

    void set_default() {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        previous_edge.assign(n, -1);
        depth.assign(n, 0);
        subtree_size.assign(n, 0);
        dist.assign(n, T(0));
        tin.assign(n, 0);
        tout.assign(n, 0);
    }

    void set_root(int new_root, int start_timer = std::numeric_limits<int>::max()) {
        if (root.empty())
            set_default();

        static int timer = 0;
        if (start_timer != std::numeric_limits<int>::max())
            timer = start_timer;

        std::function<void(int)> dfs = [&](int v) {
            subtree_size[v] = 1;
            tin[v] = timer++;
            for (const int id : g[v]) {
                int u = v ^ edges[id].from ^ edges[id].to;
                if (u == parent[v])
                    continue;

                root[u] = root[v];
                parent[u] = v;
                previous_edge[u] = id;
                depth[u] = depth[v] + 1;
                dist[u] = dist[v] + edges[id].cost;

                dfs(u);
                subtree_size[v] += subtree_size[u];
            }
            tout[v] = timer;

            for (int i = 0; i < int(g[v].size()); i++) {
                int u = v ^ edges[g[v][i]].from ^ edges[g[v][i]].to;
                if (u == parent[v]) {
                    for (int j = i; j > 0; j--)
                        std::swap(g[v][j], g[v][j - 1]);

                    break;
                }
            }
        };

        parent[new_root] = root[new_root] = new_root;
        previous_edge[new_root] = -1;
        depth[new_root] = 0;
        dist[new_root] = T(0);
        dfs(new_root);
    }

    void init() {
        set_default();
        for (int v = 0; v < n; v++)
            if (root[v] == v)
                set_root(v);
    }

    std::vector<int> order(int start) const {
        std::vector<int> order;

        std::function<void(int, int)> dfs = [&](int v, int parent) {
            order.push_back(v);
            for (const int id : g[v]) {
                int u = v ^ edges[id].from ^ edges[id].to;
                if (u == parent)
                    continue;

                dfs(u, v);
            }
        };

        dfs(start, start);
        return order;
    }
};

template<typename T>
struct lca_forest : public forest<T> {
    struct sparse_table {
        std::vector<std::vector<int>> sparse;

        sparse_table() {}
        sparse_table(const std::vector<int> &a) {
            if (a.empty())
                return;

            int n = int(a.size());
            int lg = std::__lg(n);
            sparse.reserve(lg);
            sparse.emplace_back(a);
            for (int level = 1; level <= lg; level++) {
                sparse.emplace_back(std::vector<int>(n - (1 << level) + 1));
                for (int i = 0; i < int(sparse.back().size()); i++)
                    sparse[level][i] = std::min(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
            }
        }

        int query(int l, int r) const {
            assert(l < r);
            int level = std::__lg(r - l);
            return std::min(sparse[level][l], sparse[level][r - (1 << level)]);
        }
    };

    using forest<T>::n;
    using forest<T>::edges;
    using forest<T>::g;
    using forest<T>::root;
    using forest<T>::parent;
    using forest<T>::previous_edge;
    using forest<T>::depth;
    using forest<T>::subtree_size;
    using forest<T>:: dist;
    using forest<T>::tin;
    using forest<T>::tout;

    sparse_table rmq;
    std::vector<int> path;
    std::vector<int> events;

    lca_forest(int n = 0) : forest<T>(n) {}

    void set_root(int new_root, bool init_rmq = true) {
        forest<T>::set_root(new_root);
        path.reserve(int(path.size()) + subtree_size[new_root] - 1);
        events.reserve(int(events.size()) + subtree_size[new_root] - 1);

        std::function<void(int)> dfs = [&](int v) {
            for (const int id : g[v]) {
                int u = v ^ edges[id].from ^ edges[id].to;
                if (u == parent[v])
                    continue;

                path.push_back(v);
                events.push_back(tin[v]);
                dfs(u);
            }
        };

        dfs(new_root);
        if (init_rmq)
            rmq = sparse_table(events);
    }

    void init() {
        forest<T>::set_default();
        for (int v = 0; v < n; v++)
            if (root[v] == v)
                set_root(v, false);

        rmq = sparse_table(events);
    }

    int lca(int v, int u) const {
        if (v == u)
            return v;

        std::tie(v, u) = minmax(tin[v], tin[u]);
        return path[rmq.query(v, u)];
    }

    int length(int v, int u) const {
        return depth[v] + depth[u] - 2 * depth[lca(v, u)];
    }

    T distance(int v, int u) const {
        return dist[v] + dist[u] - T(2) * dist[lca(v, u)];
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    lca_forest<int> tree(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        tree.add(v, u);
    }
    tree.set_root(0);

    const int B = 210;
    vector<mint> sum(n);
    vector<int> big;
    for (int i = 0; i < n; i++)
        if (len(tree.g[i]) > B)
            big.push_back(i);

    binary_indexed_tree<mint> bit(n + 1);
    const mint inv_n = mint(n).inv();

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int v, d;
            cin >> v >> d;
            v--;

            bit.add(tree.tin[v], d);
            bit.add(tree.tin[v] + 1, 0 - d);
            if (len(tree.g[v]) > B) {
                sum[v] += d;
                continue;
            }

            mint value = mint(tree.subtree_size[v]) * inv_n * d;
            bit.add(0, value);
            bit.add(tree.tin[v], 0 - value);

            mint to_sub = 0;
            for (auto id : tree.g[v]) {
                int u = tree.another(id, v);
                if (u == tree.parent[v])
                    continue;

                value = (n - mint(tree.subtree_size[u])) * inv_n * d;
                bit.add(tree.tin[u], value - to_sub);
                to_sub = value;
            }

            value = mint(tree.subtree_size[v]) * inv_n * d;
            bit.add(tree.tout[v], value - to_sub);
        } else if (type == 2) {
            int v;
            cin >> v;
            v--;

            mint answer = bit.query(tree.tin[v]);
            for (auto u : big) {
                if (u == v || sum[u].value == 0)
                    continue;

                if (!tree.is_parent(u, v))
                    answer += mint(tree.subtree_size[u]) * inv_n * sum[u];
                else {
                    int pos = partition_point(1 + all(tree.g[u]), [&](int id) {
                        return tree.tin[tree.another(id, u)] <= tree.tin[v];
                    }) - tree.g[u].begin() - 1;
                    answer += mint(n - tree.subtree_size[tree.another(tree.g[u][pos], u)]) * inv_n * sum[u];
                }
            }

            cout << answer << '\n';
        } else {
            assert(false);
        }
    }
}