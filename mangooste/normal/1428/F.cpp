#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

//struct SegmentTree {
//    struct Node {
//        int mx;
//        ll sum;
//
//        Node() : mx(INT_MIN), sum(0) {}
//        Node(pair<int, int> val) : mx(val.first), sum(val.first + val.second) {}
//
//        Node operator + (Node nd) {
//            Node res;
//            res.mx = max(mx, nd.mx);
//            res.sum = sum + nd.sum;
//            return res;
//        }
//    };
//
//    int n;
//    vector<Node> tree;
//
//    SegmentTree(vector<pair<int, int>> st) : n(len(st)) {
//        tree.resize(4 * n);
//        build(1, 0, n, st);
//    }
//
//    void build(int v, int vl, int vr, vector<pair<int, int>> &st) {
//        if (vr - vl == 1) {
//            tree[v] = Node(st[vl]);
//            return;
//        }
//        int vm = (vl + vr) / 2;
//        build(2 * v, vl, vm, st);
//        build(2 * v + 1, vm, vr, st);
//        tree[v] = tree[2 * v] + tree[2 * v + 1];
//    }
//
//    Node get(int l, int r) {
//        return get(1, 0, n, l, r);
//    }
//
//    Node get(int v, int vl, int vr, int l, int r) {
//        if (r <= vl || vr <= l) return Node();
//        if (l <= vl && vr <= r) return tree[v];
//        int vm = (vl + vr) / 2;
//        return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm, vr, l, r);
//    }
//
//    int getPos(int pos, int value) {
//        return getPos(1, 0, n, pos, value);
//    }
//
//    int getPos(int v, int vl, int vr, int pos, int value) {
//        if (vr <= pos) return n;
//        if (tree[v].mx < value) return n;
//        if (vr - vl == 1) return vl;
//
//        int vm = (vl + vr) / 2;
//        int res = getPos(2 * v, vl, vm, pos, value);
//        if (res == n) res = getPos(2 * v + 1, vm, vr, pos, value);
//        return res;
//    }
//};

struct SegmentTree {
    struct Node {
        int sum = 0;
        int mx = INT_MIN;

        inline void apply(int vl, int vr, pair<int, int> val) {
            mx = max(mx, val.first);
            sum += val.first + val.second;
        }
    };

    inline Node unite(const Node &left, const Node &right) {
        Node res;
        res.mx = max(left.mx, right.mx);
        res.sum = left.sum + right.sum;
        return res;
    }

    inline void push(int v, int vl, int vr) {
    }

    int n;
    vector<Node> tree;

    SegmentTree() : n(0) {}
    explicit SegmentTree(int n) : n(n), tree(vector<Node>(4 * n)) {}
    template<class T>
    explicit SegmentTree(vector<T> a) : n(int(a.size())), tree(vector<Node>(4 * n)) {
        build(1, 0, n, a);
    }

    template<class T>
    void build(int v, int vl, int vr, const vector<T> &a) {
        if (vr <= vl) return;
        if (vr - vl == 1) {
            tree[v].apply(vl, vr, a[vl]);
            return;
        }
        int vm = (vl + vr ) / 2;
        build(2 * v, vl, vm, a);
        build(2 * v + 1, vm, vr, a);
        tree[v] = unite(tree[2 * v], tree[2 * v + 1]);
    }

    inline Node get(int l, int r) {                                                       // [l, r)
        return get(1, 0, n, l, r);
    }

    Node get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (r <= vl || vr <= l) return Node();
        if (l <= vl && vr <= r) return tree[v];

        int vm = (vl + vr) / 2;
        return unite(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }

    template<class... T>
    inline void update(int l, int r, T... del) {                                          // [l, r)
        update(1, 0, n, l, r, del...);
    }

    template<class... T>
    void update(int v, int vl, int vr, int l, int r, T... del) {
        push(v, vl, vr);
        if (r <= vl || vr <= l) return;
        if (l <= vl && vr <= r) {
            tree[v].apply(vl, vr, del...);
            return;
        }

        int vm = (vl + vr) / 2;
        update(2 * v, vl, vm, l, r, del...);
        update(2 * v + 1, vm, vr, l, r, del...);

        push(2 * v, vl, vm);
        push(2 * v + 1, vm, vr);
        tree[v] = unite(tree[2 * v], tree[2 * v + 1]);
    }

    inline int findFirst(int st, const function<bool(const Node&)> &f) {                  // [st, n)
        return findFirst(1, 0, n, st, f);
    }

    int findFirst(int v, int vl, int vr, int st, const function<bool(const Node&)> &f) {
        push(v, vl, vr);
        if (vr <= st || !f(tree[v])) return n;
        if (vr - vl == 1) return vl;

        int vm = (vl + vr) / 2;
        int res = findFirst(2 * v, vl, vm, st, f);
        if (res == n) res = findFirst(2 * v + 1, vm, vr, st, f);
        return res;
    }

    inline int findLast(int fn, const function<bool(const Node&)> &f) {                   // [0, fn)
        return findLast(1, 0, n, fn, f);
    }

    int findLast(int v, int vl, int vr, int fn, const function<bool(const Node&)> &f) {
        push(v, vl, vr);
        if (vl >= fn || !f(tree[v])) return -1;
        if (vr - vl == 1) return vl;

        int vm = (vl + vr) / 2;
        int res = findFirst(2 * v + 1, vm, vr, fn, f);
        if (res == -1) res = findFirst(2 * v, vm, vr, fn, f);
        return res;
    }
};

#define Node SegmentTree::Node

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> st;
    for (int i = 0; i < n;) {
        st.emplace_back();
        int j = i;
        while (j < n && s[j] == '1') j++;
        st.back().first = j  - i;
        i = j;
        while (j < n && s[j] == '0') j++;
        st.back().second = j - i;
        i = j;
    }

    SegmentTree tree(st);
    ll cur = 0;
    for (int i = 0; i < len(st); i++) {
        int mx = tree.get(0, i).mx;
        for (int j = 1; j <= st[i].first; j++) {
            cur += max(j, mx);
        }
        cur += ll(st[i].second) * max(st[i].first, mx);
    }

    ll ans = 0;
    for (int i = 0; i < len(st); i++) {
        for (int j = st[i].first; j; j--) {
            ans += cur;
            int pos = tree.findFirst(i + 1, [&](const Node &nd){
                return nd.mx >= j;
            });
            cur -= tree.get(i + 1, pos).sum;
            cur -= st[i].second;
            cur -= j;
            if (pos != len(st)) cur -= j - 1;
        }
        ans += cur * st[i].second;
    }
    cout << ans << '\n';
}