#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

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

        const int n = int(a.size()), lg = std::__lg(n);
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
        const int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    int size() const {
        return int(bit.size()) - 1;
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
            r = bit.size();

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

void solve(int test_num) {
    int n, q;
    cin >> n >> q;
    vector<int> p(n), a(n);
    for (auto &x : p) cin >> x, x--;
    for (auto &x : a) cin >> x, x--;
    
    int k = count(all(a), -1);
    vector<int> extra(k - 1);
    for (auto &x : extra) cin >> x, x--;

    auto vals = extra;
    for (auto x : a) {
        if (x != -1) vals.push_back(x);
    }
    sort(all(vals));
    assert(unique(all(vals)) == vals.end());

    auto coord = [&](int x) {
        return lower_bound(all(vals), x) - vals.begin();
    };
    for (auto &x : a) {
        if (x != -1) x = coord(x);
    }
    for (auto &x : extra) x = coord(x);

    auto sparse_merge = [&](const int i, const int j) {
        return p[i] > p[j] ? i : j;
    };
    vector<int> sparse_init(n);
    iota(all(sparse_init), 0);
    sparse_table<int, decltype(sparse_merge)> sparse(sparse_init, sparse_merge);

    vector<array<int, 2>> children(n);
    const int root = y_combinator([&](auto dfs, int l, int r) -> int {
        if (r <= l) return -1;
        int root = sparse.query(l, r);
        assert(l <= root && root < r);
        children[root][0] = dfs(l, root);
        children[root][1] = dfs(root + 1, r);
        return root;
    })(0, n);

    vector<int> tin(n), tout(n), color(n, n), parent(n, -1);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        tin[v] = timer++;
        if (a[v] != -1) color[v] = a[v];

        for (auto u : children[v]) {
            if (u == -1) continue;
            color[u] = color[v];
            parent[u] = v;
            dfs(u);
        }
        tout[v] = timer;
    })(root);

    vector<int> know(n, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) know[a[i]] = i;
    }
    vector<int> down(n);
    for (int i = 0; i < n; i++) {
        for (int j : {0, 1}) down[i] += children[i][j] != -1;
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if (!down[i] && a[i] == -1) {
            st.emplace(color[i], i);
        }
    }

    int upper = n;
    for (int val = 0; val < n - 1; val++) {
        int need = val - (val >= upper);

        auto remove = [&](int v) {
            if (a[v] != -1) know[a[v]] = -1;
            int u = parent[v];
            if (u == -1) return;
            down[u]--;
            assert(down[u] >= 0);
            if (a[u] == -1 && !down[u]) {
                st.emplace(color[u], u);
            }
        };

        if (need < 0 || know[need] == -1) {
            if (st.empty()) {
                upper = -1;
                break;
            }

            auto [c, v] = *st.begin();
            st.erase(st.begin());
            remove(v);
            continue;
        }

        int v = know[need];
        if (down[v]) {
            if (upper != n) {
                upper = -1;
                break;
            }
            upper = val;
            val--;
            continue;
        }
        remove(v);
    }

    auto solve = [&](int pref) {
        vector<int> know(n, -1);
        for (int i = 0; i < n; i++) {
            if (a[i] != -1) know[a[i]] = i;
        }
        vector<int> down(n);
        for (int i = 0; i < n; i++) {
            for (int j : {0, 1}) down[i] += children[i][j] != -1;
        }
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            if (!down[i] && a[i] == -1) {
                st.emplace(color[i], i);
            }
        }

        for (int val = 0; val < n - 1; val++) {
            int need = val - (val >= pref);

            auto remove = [&](int v) {
                int u = parent[v];
                if (a[v] != -1) know[a[v]] = -1;
                if (u == -1) return;
                down[u]--;
                assert(down[u] >= 0);
                if (a[u] == -1 && !down[u]) {
                    st.emplace(color[u], u);
                }
            };

            if (need < 0 || know[need] == -1) {
                if (st.empty()) return false;
                auto [c, v] = *st.begin();
                st.erase(st.begin());
                remove(v);
                continue;
            }

            int v = know[need];
            if (down[v]) return false;
            remove(v);
        }
        return true;
    };

    int l = -1, r = upper;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (solve(mid) ? r : l) = mid;
    }
    int lower = r;

    while (q--) {
        int x;
        cin >> x;
        x = coord(x);
        cout << (lower <= x && x <= upper ? "YES" : "NO") << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}