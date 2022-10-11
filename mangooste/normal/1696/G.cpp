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

struct node {
    static ll x, y;
    static array<ll, 3> coeffs;
    static bool can[3][3];

    array<array<ll, 3>, 3> dp;

    node() {}
    node(int val) {
        dp.fill({ll(-1e18), ll(-1e18), ll(-1e18)});
        for (int i : {0, 1, 2}) dp[i][i] = val * node::coeffs[i];
    }

    void apply(int val, int vl, int vr) {
        assert(vr - vl == 1);
        *this = node(val);
    }

    void push(node &child, int vl, int vr, int cl, int cr) {}
    void clear_after_push() {}

    static node merge(const node &left, const node &right) {
        node res;
        res.dp.fill({ll(-1e18), ll(-1e18), ll(-1e18)});
        for (int f : {0, 1, 2}) {
            for (int m1 : {0, 1, 2}) {
                for (int m2 : {0, 1, 2}) {
                    for (int s : {0, 1, 2}) {
                        if (can[m1][m2]) {
                            res.dp[f][s] = max(res.dp[f][s], left.dp[f][m1] + right.dp[m2][s]);
                        }
                    }
                }
            }
        }
        return res;
    }
};

ll node::x = 0;
ll node::y = 0;
array<ll, 3> node::coeffs = {};
bool node::can[3][3] = {};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n, q;
    cin >> n >> q >> node::x >> node::y;
    if (node::x > node::y) swap(node::x, node::y);
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    node::coeffs[0] = 0;
    node::coeffs[1] = node::y;
    node::coeffs[2] = node::x + node::y;
    for (int m1 : {0, 1, 2}) {
        for (int m2 : {0, 1, 2}) {
            node::can[m1][m2] = (node::x * node::coeffs[m1] + node::y * node::coeffs[m2] <= node::y * (node::x + node::y));
        }
    }
    segtree<node> tree(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, new_value;
            cin >> pos >> new_value, pos--;
            tree.update(pos, pos + 1, new_value);
        } else {
            int l, r;
            cin >> l >> r, l--;

            auto res = tree.query(l, r);
            ll ans = -1e18;
            for (int from : {0, 1, 2}) {
                for (int to : {0, 1, 2}) {
                    ans = max(ans, res.dp[from][to]);
                }
            }
            cout << ld(ans) / node::y / (node::x + node::y) << '\n';
        }
    }
}