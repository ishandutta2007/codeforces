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

    int n, q;
    cin >> n >> q;
    vector<int> p(n), where(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        where[p[i]] = i;
    }

    vector<vector<pair<int, int>>> divisors(n + 1);
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n && x > y / x; y += x) {
            divisors[y].emplace_back(x, y / x);
        }
    }

    vector<int> left(n), right(n);
    for (int rot = 0; rot < 2; rot++, reverse(all(p))) {
        auto &cur = rot == 0 ? left : right;
        vector<int> st{-1};
        for (int i = 0; i < n; i++) {
            while (len(st) > 1 && p[st.back()] < p[i]) {
                st.pop_back();
            }
            cur[i] = st.back() + 1;
            st.push_back(i);
        }
    }
    reverse(all(right));
    for (auto &x : right) x = n - 1 - x;

    vector<vector<pair<int, int>>> to_add(n), to_sub(n);
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> segs;
        segs.reserve(len(divisors[p[i]]));
        for (auto [x, y] : divisors[p[i]]) {
            segs.emplace_back(min({where[x], where[y], i}), max({where[x], where[y], i}));
            if (segs.back().first < left[i] || segs.back().second > right[i]) {
                segs.pop_back();
            }
        }
        
        if (segs.empty()) continue;
        sort(all(segs), [&](const auto &a, const auto &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        vector<pair<int, int>> good_segs;
        good_segs.reserve(len(segs));
        for (int i = len(segs) - 1, min_r = n; i >= 0; i--) {
            if (segs[i].second < min_r) {
                min_r = segs[i].second;
                good_segs.push_back(segs[i]);
            }
        }
        reverse(all(good_segs));

        int last = left[i];
        for (auto [l, r] : good_segs) {
            assert(last <= l);
            to_add[r].emplace_back(last, l + 1);
            last = l + 1;
        }
        if (right[i] != n) to_sub[right[i]].emplace_back(left[i], good_segs.back().first + 1);
    }

    vector<vector<pair<int, int>>> queries(n);
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r - 1].emplace_back(l - 1, i);
    }

    struct node {
        ll to_sub = 0, mod_sub = 0;
        int tot = 0, mod_tot = 0;

        void apply(const pair<ll, int> &mod, int vl, int vr) {
            to_sub += mod.first * (vr - vl);
            mod_sub += mod.first;
            tot += mod.second * (vr - vl);
            mod_tot += mod.second;
        }

        void push(node &child, int vl, int vr) {
            child.apply({mod_sub, mod_tot}, vl, vr);
        }

        void clear_after_push() {
            mod_sub = 0;
            mod_tot = 0;
        }

        static node merge(const node &left, const node &right) {
            return node{left.to_sub + right.to_sub, 0, left.tot + right.tot, 0};
        }
    };

    segtree<node> tree(n);
    for (int i = 0; i < n; i++) {
        for (auto [l, r] : to_add[i]) {
            tree.update(l, r, pair{i - 1, 1});
        }

        for (auto [l, id] : queries[i]) {
            auto nd = tree.query(l, i + 1);
            ans[id] = 1ll * i * nd.tot - nd.to_sub;
        }

        for (auto [l, r] : to_sub[i]) {
            tree.update(l, r, pair{-i, -1});
        }
    }

    for (auto x : ans) cout << x << '\n';
}