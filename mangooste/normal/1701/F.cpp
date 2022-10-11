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

template<typename node>
struct segtree {
    int n;
    std::vector<node> tree;
 
    segtree(int n) : n(n), tree(4 * n, node()) {
        build(1, 0, n);
    }
 
    void build(int v, int vl, int vr) {
        if (vr - vl <= 1)
            return;
 
        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }
 
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
        tree[v].push(tree[v << 1], vl, vr, vl, vm);
        tree[v].push(tree[v << 1 | 1], vl, vr, vm, vr);
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
        tree[v].push(tree[v << 1], vl, vr, vl, vm);
        tree[v].push(tree[v << 1 | 1], vl, vr, vm, vr);
        tree[v].clear_after_push();
 
        if (r <= vm)
            return _query(v << 1, vl, vm, l, r);
 
        if (vm <= l)
            return _query(v << 1 | 1, vm, vr, l, r);
 
        return node::merge(_query(v << 1, vl, vm, l, r), _query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int q, d;
    cin >> q >> d;
    vector<int> a(q);
    for (auto &x : a) cin >> x;
    const int MAX = *max_element(all(a)) + 1;

    struct node {
        int in_set = 0, mod = 0;
        ll ans = 0, sum_good_cnt = 0, sum_cnt = 0;

        void apply(bool, int vl, int vr) {
            assert(vr - vl == 1);
            if (in_set) {
                in_set = ans = sum_good_cnt = 0;
            } else {
                in_set = 1;
                ans = sum_cnt * sum_cnt;
                sum_good_cnt = sum_cnt;
            }
        }

        void apply(int to_add, int vl, int vr) {
            if (to_add == 0) return;

            auto sum_first_n_odd = [&](int n) {
                // 1 + 3 + 5 + ... + (2 * n - 1)
                return 1ll * n * n;
            };         

            if (to_add > 0) {
                // 2 * x + 1
                // 2 * x + 3
                // ...
                // 2 * x + (2 * to_add - 1)
                ans += 2ll * to_add * sum_good_cnt + sum_first_n_odd(to_add) * in_set;
            } else {
                // 2 * x - 1
                // 2 * x - 3
                // ...
                // 2 * x - (2 * (-to_add) - 1)
                ans -= -2ll * to_add * sum_good_cnt - sum_first_n_odd(-to_add) * in_set;
            }
            sum_good_cnt += to_add * in_set;
            sum_cnt += to_add * (vr - vl);
            mod += to_add;
        }

        void push(node &child, int vl, int vr, int cl, int cr) {
            child.apply(mod, cl, cr);
        }

        void clear_after_push() {
            mod = 0;
        }

        static node merge(const node &left, const node &right) {
            node res;
            res.in_set = left.in_set + right.in_set;
            res.ans = left.ans + right.ans;
            res.sum_good_cnt = left.sum_good_cnt + right.sum_good_cnt;
            res.sum_cnt = left.sum_cnt + right.sum_cnt;
            return res;
        }
    };

    segtree<node> tree(MAX);
    vector<bool> in_set(MAX);
    for (auto &x : a) {
        int to_add = in_set[x] ? -1 : 1;
        in_set[x] = !in_set[x];
        tree.update(x, x + 1, true);
        tree.update(max(1, x - d), x, to_add);

        auto nd = tree.query(0, len(tree));
        dbg(nd.in_set, nd.ans, nd.sum_good_cnt, nd.sum_cnt);
        ll ans = nd.ans - nd.sum_good_cnt;
        assert(ans % 2 == 0);
        cout << ans / 2 << '\n';
    }
}