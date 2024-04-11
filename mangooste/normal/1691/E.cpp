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

void solve(int test_num) {
    int n;
    cin >> n;
    array<vector<pair<int, int>>, 2> segs;
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        coords.push_back(l);
        coords.push_back(r);
        segs[c].emplace_back(l, r);
    }

    sort(all(coords));
    coords.resize(unique(all(coords)) - coords.begin());
    auto coord = [&](int x) {
        return lower_bound(all(coords), x) - coords.begin();
    };
    
    struct segtree_left {
        int n;
        vector<set<pair<int, int>, greater<>>> open;
        vector<pair<int, int>> tree;

        segtree_left(int n = 0) : n(n), open(n), tree(2 * n, {-1, -1}) {
            for (int i = 0; i < n; i++) {
                add_segment(i, -1, -1, false);
            }
        }

        void add_segment(int l, int r, int id, bool remove) {
            if (remove) open[l].erase({r, id});
            else open[l].emplace(r, id);
            l += n;
            tree[l] = *open[l - n].begin();
            for (l >>= 1; l; l >>= 1) {
                tree[l] = max(tree[l << 1], tree[l << 1 | 1]);
            }
        }

        pair<int, int> query(int l, int r) {
            r++;
            pair<int, int> res{-1, -1};
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, tree[l++]);
                if (r & 1) res = max(res, tree[--r]);
            }
            return res;
        }
    };

    struct segtree_right {
        int n;
        segtree_left tree;

        segtree_right(int n = 0) : n(n), tree(n) {}

        void add_segment(int l, int r, int id, bool remove) {
            l = n - 1 - l, r = n - 1 - r;
            swap(l, r);
            tree.add_segment(l, r, id, remove);
        }

        pair<int, int> query(int l, int r) {
            l = n - 1 - l, r = n - 1 - r;
            swap(l, r);
            auto [rr, id] = tree.query(l, r);
            rr = n - 1 - rr;
            return {rr, id};
        }
    };

    int m = len(coords);
    array<segtree_left, 2> tree_left;
    tree_left.fill(segtree_left(m));
    array<segtree_right, 2> tree_right;
    tree_right.fill(segtree_right(m));

    for (int rot : {0, 1}) {
        for (int i = 0; i < len(segs[rot]); i++) {
            auto &[l, r] = segs[rot][i];
            l = coord(l);
            r = coord(r);
            tree_left[rot].add_segment(l, r, i, false);
            tree_right[rot].add_segment(l, r, i, false);
        }
    }

    array<vector<bool>, 2> used;
    for (int rot : {0, 1}) {
        used[rot].resize(len(segs[rot]));
    }

    int comps = 0;
    for (int rot : {0, 1}) {
        for (int i = 0; i < len(segs[rot]); i++) {
            if (used[rot][i]) continue;
            comps++;

            auto remove_segment = [&](int rot, int v) -> void {
                used[rot][v] = true;
                auto [l, r] = segs[rot][v];
                tree_left[rot].add_segment(l, r, v, true);
                tree_right[rot].add_segment(l, r, v, true);
            };

            y_combinator([&](auto dfs, int rot, int v) -> void {
                remove_segment(rot, v);
                while (true) {
                    auto [r, u] = tree_left[rot ^ 1].query(0, segs[rot][v].second);
                    if (r >= segs[rot][v].first) {
                        dfs(rot ^ 1, u);
                    } else {
                        break;
                    }
                }
                while (true) {
                    auto [l, u] = tree_right[rot ^ 1].query(segs[rot][v].first, m - 1);
                    if (l <= segs[rot][v].second) {
                        dfs(rot ^ 1, u);
                    } else {
                        break;
                    }
                }
            })(rot, i);
        }
    }
    cout << comps << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}