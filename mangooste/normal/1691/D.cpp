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

template<typename T, bool max_mode>
struct segtree {
    int n;
    vector<pair<T, int>> tree;

    segtree(const vector<T> &a) : n(len(a)), tree(2 * n) {
        for (int i = 0; i < n; i++) {
            tree[n + i] = {a[i], i};
        }
        for (int i = n - 1; i; i--) {
            tree[i] = max_mode ? max(tree[i << 1], tree[i << 1 | 1]) : min(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    pair<T, int> query(int l, int r) {
        pair<T, int> res = {max_mode ? numeric_limits<T>::min() : numeric_limits<T>::max(), -1};
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = max_mode ? max(res, tree[l++]) : min(res, tree[l++]);
            }
            if (r & 1) {
                res = max_mode ? max(res, tree[--r]) : min(res, tree[--r]);
            }
        }
        return res;
    }
};

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    segtree<int, true> tree_a(a);
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    segtree<ll, false> tree_min(pref);
    segtree<ll, true> tree_max(pref);
    bool ok = true;

    y_combinator([&](auto solve, int l, int r) -> void {
        if (r - l <= 1) return;
        auto [value_max, pos_max] = tree_a.query(l, r);
        solve(l, pos_max);
        solve(pos_max + 1, r);
        ok &= value_max >= tree_max.query(pos_max + 1, r + 1).first - tree_min.query(l, pos_max + 1).first;
    })(0, n);

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}