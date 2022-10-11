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

    int n;
    cin >> n;
    vector<array<int, 3>> queries(n);
    vector<int> coords;

    for (auto &[a, b, c] : queries) {
        cin >> a >> b >> c;
        if (a == 1) {
            coords.push_back(b);
            coords.push_back(c);
        } else {
            b--, c--;
        }
    }

    sort(all(coords));
    coords.resize(unique(all(coords)) - coords.begin());

    auto get_coord = [&](int x) {
        return lower_bound(all(coords), x) - coords.begin();
    };

    vector<pair<int, int>> segs;
    vector<int> par, min_l, max_r;

    auto root = y_combinator([&](auto root, int v) -> int {
        return par[v] == v ? v : par[v] = root(par[v]);
    });

    auto unite = [&](int v, int u) {
        v = root(v);
        u = root(u);
        if (v == u) return;
        par[u] = v;
        min_l[v] = min(min_l[v], min_l[u]);
        max_r[v] = max(max_r[v], max_r[u]);
    };

    int m = len(coords);
    vector<set<pair<int, int>, greater<>>> values_right(m);
    vector<array<int, 3>> tree_right(2 * m, {int(-1e9), -1, -1});
    vector<set<pair<int, int>>> values_left(m);
    vector<array<int, 3>> tree_left(2 * m, {int(1e9), -1, -1});

    for (int i = 0; i < m; i++) {
        values_right[i].insert({int(-1e9), -1});
        values_left[i].insert({int(1e9), -1});
    }

    auto rebuild_right = [&](int pos) {
        auto new_value = *values_right[pos - m].begin();
        tree_right[pos] = {new_value.first, new_value.second, pos - m};
        for (pos >>= 1; pos; pos >>= 1) {
            tree_right[pos] = max(tree_right[pos << 1], tree_right[pos << 1 | 1]);
        }
    };

    auto rebuild_left = [&](int pos) {
        auto new_value = *values_left[pos - m].begin();
        tree_left[pos] = {new_value.first, new_value.second, pos - m};
        for (pos >>= 1; pos; pos >>= 1) {
            tree_left[pos] = min(tree_left[pos << 1], tree_left[pos << 1 | 1]);
        }
    };

    for (auto &q : queries) {
        if (q[0] == 1) {
            int l = get_coord(q[1]), r = get_coord(q[2]);
            segs.emplace_back(l, r);

            int cur_id = len(par);
            par.push_back(cur_id);
            min_l.push_back(l);
            max_r.push_back(r);

            while (true) {
                auto query = [&](int l, int r) {
                    array<int, 3> res{int(-1e9), -1, -1};
                    for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) res = max(res, tree_right[l++]);
                        if (r & 1) res = max(res, tree_right[--r]);
                    }
                    return res;
                };

                auto [mx, id, from] = query(0, r);
                if (mx <= r) {
                    auto cur = query(0, l);
                    mx = cur[0], id = cur[1], from = cur[2];
                    if (mx <= l) break;
                }

                unite(cur_id, id);
                values_right[from].erase(values_right[from].begin());
                rebuild_right(from + m);
            }

            while (true) {
                auto query = [&](int l, int r) {
                    array<int, 3> res{int(1e9), -1, -1};
                    for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) res = min(res, tree_left[l++]);
                        if (r & 1) res = min(res, tree_left[--r]);
                    }
                    return res;
                };

                auto [mn, id, from] = query(l + 1, m);
                if (mn >= l) {
                    auto cur = query(r + 1, m);
                    mn = cur[0], id = cur[1], from = cur[2];
                    if (mn >= r) break;
                }

                unite(cur_id, id);
                values_left[from].erase(values_left[from].begin());
                rebuild_left(from + m);
            }

            cur_id = root(cur_id);
            int new_l = min_l[cur_id], new_r = max_r[cur_id];

            values_right[new_l].emplace(new_r, cur_id);
            rebuild_right(new_l + m);

            values_left[new_r].emplace(new_l, cur_id);
            rebuild_right(new_r + m);
        } else {
            int v = q[1], u = q[2];
            cout << (min_l[root(u)] <= segs[v].first && segs[v].second <= max_r[root(u)] ? "YES" : "NO") << '\n';
        }
    }
}