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

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    constexpr int INF = 1e9;

    struct node {
        array<int, 2> cnt;
        array<array<int, 2>, 2> dp;

        void build_dp() {
            for (int from : {0, 1}) {
                dp[from][from] = cnt[from] > 0;
                dp[from][from ^ 1] = INF;
                if (cnt[from]) dp[from][from ^ 1] = 1;
            }
        }

        node() {
            cnt.fill(0);
            build_dp();
        }

        void apply(int pos, int delta, int l, int r) {
            cnt[pos] += delta;
            build_dp();
        }

        void push(node &child, int vl, int vr, int cl, int cr) {}
        void clear_after_push() {}

        static node merge(const node &left, const node &right) {
            node res;
            for (int from : {0, 1}) {
                for (int to : {0, 1}) {
                    res.dp[from][to] = INF;
                    for (int mid : {0, 1}) {
                        res.dp[from][to] = min(res.dp[from][to], right.dp[from][mid] + left.dp[mid][to]);
                    }
                }
            }
            return res;
        }
    };

    segtree<node> tree(n + 1);
    tree.update(0, 1, 0, 1);
    tree.update(0, 1, 1, 1);
    for (int i = 0; i < n; i++) {
        tree.update(a[i], a[i] + 1, 1, 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        tree.update(a[i], a[i] + 1, 1, -1);
        tree.update(a[i], a[i] + 1, 0, 1);
        if (!a[i]) continue;

        auto res = tree.query(0, a[i]);
        int cur = INF;
        for (int from : {0, 1}) {
            for (int to : {0, 1}) {
                cur = min(cur, res.dp[from][to]);
            }
        }
        ans += cur;
    }
    cout << ans << '\n';
}