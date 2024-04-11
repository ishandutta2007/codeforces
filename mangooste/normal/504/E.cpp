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

template<typename T>
struct suffix_array {
    std::vector<int> order, suffix_position, lcp;

    suffix_array(T str = T()) {
        str.push_back(*std::min_element(str.begin(), str.end()) - 1);
        int n = str.size();

        order.resize(n);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](const int i, const int j) {
            return str[i] < str[j];
        });

        suffix_position.resize(n);
        for (int i = 0; i < n; i++)
            suffix_position[order[i]] = i == 0 ? 0 : suffix_position[order[i - 1]] + (str[order[i]] != str[order[i - 1]]);

        std::vector<int> ptr(n), new_order(n), new_suffix_positoin(n);
        for (int len = 1; suffix_position[order.back()] != n - 1; len <<= 1) {
            std::fill(ptr.begin(), ptr.begin() + suffix_position[order.back()] + 1, 0);
            for (int i = 0; i < n; i++)
                if (suffix_position[i] + 1 < n)
                    ptr[suffix_position[i] + 1]++;

            for (int i = 1; i <= suffix_position[order.back()]; i++)
                ptr[i] += ptr[i - 1];

            for (const int position : order) {
                int suffix = (position - len + n) % n;
                new_order[ptr[suffix_position[suffix]]++] = suffix;
            }
            std::swap(order, new_order);

            for (int i = 0; i < n; i++)
                new_suffix_positoin[order[i]] = i == 0 ? 0 : new_suffix_positoin[order[i - 1]]
                + (suffix_position[order[i]] != suffix_position[order[i - 1]]
                || suffix_position[(order[i] + len) % n] != suffix_position[(order[i - 1] + len) % n]);

            std::swap(suffix_position, new_suffix_positoin);
        }
        assert(order[0] == n - 1);

        lcp.resize(n);
        int current_lcp = 0;
        for (int suffix = 0; suffix < n - 1; suffix++, current_lcp = current_lcp == 0 ? 0 : current_lcp - 1) {
            int previous_suffix = order[suffix_position[suffix] - 1];
            while (str[suffix + current_lcp] == str[previous_suffix + current_lcp])
                current_lcp++;

            lcp[suffix_position[suffix]] = current_lcp;
        }
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> sz(n);

    y_combinator([&](auto dfs, int v) -> void {
        sz[v] = 1;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);
            sz[v] += sz[u];
        }
        nth_element(g[v].begin(), all(g[v]), [&](const int v, const int u) {
            return sz[v] > sz[u];
        });
    })(0);

    vector<int> head(n), tin(n), tout(n), length(n), par(n);
    int timer = 0;

    y_combinator([&](auto dfs, int v) -> void {
        length[head[v]]++;
        tin[v] = timer++;
        for (int i = 0; i < len(g[v]); i++) {
            int u = g[v][i];
            head[u] = i == 0 ? head[v] : u;
            par[u] = v;
            dfs(u);
        }
        tout[v] = timer;
    })(0);

    string ss(2 * n, '?');
    for (int i = 0; i < n; i++) {
        ss[tin[i]] = s[i];
        int h = head[i];
        ss[n + tin[h] + length[h] - 1 - (tin[i] - tin[h])] = s[i];
    }
    suffix_array sa(ss);

    auto merge = [&](const int &a, const int &b) {
        return a < b ? a : b;
    };
    sparse_table<int, decltype(merge)> sp(sa.lcp, merge);

    auto get_lcp = [&](int l1, int r1, int l2, int r2) {
        if (l1 == l2) return min(r1 - l1, r2 - l2);
        if (sa.suffix_position[l1] > sa.suffix_position[l2]) {
            swap(l1, l2);
            swap(r1, r2);
        }
        int cur = sp.query(sa.suffix_position[l1] + 1, sa.suffix_position[l2] + 1);
        return min({cur, r1 - l1, r2 - l2});
    };

    int q;
    cin >> q;
    while (q--) {
        int v1, u1, v2, u2;
        cin >> v1 >> u1 >> v2 >> u2;
        v1--, u1--, v2--, u2--;

        auto query = [&](int from, int to) {
            auto is_ancestor = [&](int v, int u) {
                return tin[v] <= tin[u] && tout[u] <= tout[v];
            };

            static vector<pair<int, int>> left_path;
            left_path.clear();
            while (!is_ancestor(head[from], to)) {
                int h = head[from];
                left_path.emplace_back(n + tin[h] + length[h] - 1 - (tin[from] - tin[h]), n + tin[h] + length[h]);
                from = par[h];
            }

            static vector<pair<int,int>> right_path;
            right_path.clear();
            while (!is_ancestor(head[to], from)) {
                int h = head[to];
                right_path.emplace_back(tin[h], tin[to] + 1);
                to = par[h];
            }

            int h = head[to];
            assert(head[from] == h);
            if (is_ancestor(to, from)) {
                left_path.emplace_back(n + tin[h] + length[h] - 1 - (tin[from] - tin[h]), n + tin[h] + length[h] - (tin[to] - tin[h]));
            } else {
                assert(is_ancestor(from, to));
                left_path.emplace_back(tin[from], tin[to] + 1);
            }

            reverse(all(right_path));
            for (auto &x : right_path) left_path.push_back(x);
            return left_path;
        };

        auto first = query(v1, u1);
        auto second = query(v2, u2);
        reverse(all(first));
        reverse(all(second));

        int ans = 0;
        while (true) {
            while (!first.empty() && first.back().first == first.back().second) {
                first.pop_back();
            }
            while (!second.empty() && second.back().first == second.back().second) {
                second.pop_back();
            }
            if (first.empty() || second.empty()) break;

            auto [l1, r1] = first.back();
            auto [l2, r2] = second.back();
            int cur_lcp = get_lcp(l1, r1, l2, r2);
            ans += cur_lcp;
            if (cur_lcp < min(r1 - l1, r2 - l2)) break;
            first.back().first += cur_lcp;
            second.back().first += cur_lcp;
        }
        cout << ans << '\n';
    }
}