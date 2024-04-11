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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> tree(2 * n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree[n + i] = {x, i};
    }
    for (int i = n - 1; i; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    auto get_max = [&](int l, int r) {
        pair<int, int> res{0, -1};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res.second;
    };

    vector<array<int, 2>> childs(n, {-1, -1});
    int root = y_combinator([&](auto solve, int l, int r) -> int {
        if (r <= l) return -1;
        if (r - l == 1) return l;
        int root = get_max(l, r);
        childs[root][0] = solve(l, root);
        childs[root][1] = solve(root + 1, r);
        return root;
    })(0, n);

    vector<int> l(q), r(q);
    for (auto &x : l) cin >> x, x--;
    for (auto &x : r) cin >> x, x--;

    vector<ll> ans(q);
    array<vector<vector<pair<int, int>>>, 2> queries;
    queries.fill(vector<vector<pair<int, int>>>(n));
    for (int i = 0; i < q; i++) {
        ans[i] += r[i] - l[i] + 1;
        int w = get_max(l[i], r[i] + 1);
        queries[0][l[i]].emplace_back(w, i);
        queries[1][r[i]].emplace_back(w, i);
    }

    for (int rot : {0, 1}) {
        vector<int> sz(n);
        vector<ll> sum_d(n);

        y_combinator([&](auto dfs, int v) -> void {
            sz[v] = 1;
            for (int i : {0, 1}) {
                int u = childs[v][i];
                if (u == -1) continue;
                dfs(u);
                sz[v] += sz[u];
                sum_d[v] += sum_d[u] + sz[u];
            }
        })(root);

        vector<int> id(n, -1), st;
        vector<ll> pref_sz{0}, pref_dp{0};

        y_combinator([&](auto dfs, int v) -> void {
            if (v == -1) return;
            id[v] = len(st);
            st.push_back(v);
            int right = childs[v][1];
            pref_sz.push_back(pref_sz.back() + 1 + (right == -1 ? 0 : sz[right]));
            pref_dp.push_back(pref_dp.back() + id[v] + (right == -1 ? 0 : 1ll * sz[right] * (id[v] + 1) + sum_d[right]));

            for (auto [w, num] : queries[rot][v]) {
                assert(id[w] != -1);
                ans[num] += pref_dp[id[v] + 1] - pref_dp[id[w] + 1];
                ans[num] -= (pref_sz[id[v] + 1] - pref_sz[id[w] + 1]) * id[w];
            }

            dfs(childs[v][0]);
            id[v] = -1;
            st.pop_back();
            pref_sz.pop_back();
            pref_dp.pop_back();
            dfs(childs[v][1]);
        })(root);

        for (int i = 0; i < n; i++) {
            swap(childs[i][0], childs[i][1]);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
    }
}