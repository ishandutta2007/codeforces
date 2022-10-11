#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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
        tree[v].push(tree[v << 1], vl, vm);
        tree[v].push(tree[v << 1 | 1], vm, vr);
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
        tree[v].push(tree[v << 1], vl, vm);
        tree[v].push(tree[v << 1 | 1], vm, vr);
        tree[v].clear_after_push();

        if (r <= vm)
            return _query(v << 1, vl, vm, l, r);

        if (vm <= l)
            return _query(v << 1 | 1, vm, vr, l, r);

        return node::merge(_query(v << 1, vl, vm, l, r), _query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        p[x] = y;
    }

    struct node {
        int mn = 0, cnt = 1, mod = 0;

        void apply(int value, int l, int r) {
            mn += value;
            mod += value;
        }

        void push(node& child, int l, int r) {
            child.apply(mod, l, r);
        }

        void clear_after_push() {
            mod = 0;
        }

        static node merge(const node &left, const node &right) {
            node res;
            res.mn = min(left.mn, right.mn);
            res.cnt = 0;
            if (left.mn == res.mn) res.cnt += left.cnt;
            if (right.mn == res.mn) res.cnt += right.cnt;
            return res;
        }
    };

    segtree<node> tree(n);

    vector<int> st_max, st_min;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        tree.update(0, i, -1);
        while (!st_max.empty() && p[st_max.back()] < p[i]) {
            int l = len(st_max) == 1 ? 0 : st_max.end()[-2] + 1;
            tree.update(l, st_max.back() + 1, p[i] - p[st_max.back()]);
            st_max.pop_back();
        }
        st_max.push_back(i);

        while (!st_min.empty() && p[st_min.back()] > p[i]) {
            int l = len(st_min) == 1 ? 0 : st_min.end()[-2] + 1;
            tree.update(l, st_min.back() + 1, -p[i] + p[st_min.back()]);
            st_min.pop_back();
        }
        st_min.push_back(i);

        auto nd = tree.query(0, i + 1);
        assert(nd.mn >= 0);
        if (nd.mn == 0) ans += nd.cnt;
    }
    cout << ans << '\n';
}