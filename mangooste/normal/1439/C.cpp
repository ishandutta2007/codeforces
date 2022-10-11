#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

template<typename A, typename B> ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type> ostream& operator<<(ostream &out, A v) { out << '{'; string sep; for (const B &x : v) out << sep << x, sep = ", "; return out << '}'; }

void dbgPrint() { cerr << endl; }
template<typename A, typename... B> void dbgPrint(A a, B... b) { cerr << ' ' << a; dbgPrint(b...); }

#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int(a.size())
#define all(a) (a).begin(), (a).end()

struct SegmentTree {
    struct Node {
        ll sum;
        int mn;
        int mod;

        Node(ll sum = 0, int mn = INT_MAX, int mod = 0) :
            sum(sum), mn(mn), mod(mod)
        {}

        Node operator + (Node nd) const {
            Node res;
            res.sum = nd.sum + sum;
            res.mn = min(mn, nd.mn);
            return res;
        }
    };

    int n;
    vector<Node> tree;

    SegmentTree(vector<int> a) : n(sz(a)), tree(vector<Node>(4 * n)) {
        build(1, 0, n, a);
//        for (int i = 0; i < 4 * n; i++) {
//            cout << "tree[" << i << "].mn = " << tree[i].mn << endl;
//        }
//        dbg();
    }

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vr - vl == 1) {
            tree[v] = Node(a[vl], a[vl], 0);
            return;
        }
        int vm = (vl + vr) / 2;
        build(2 * v, vl, vm, a);
        build(2 * v + 1, vm, vr, a);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    inline void push(int v, int vl, int vr) {
        if (tree[v].mod == 0) return;

        tree[v].sum = (ll) (vr - vl) * tree[v].mod;
        tree[v].mn = tree[v].mod;
        if (vr - vl > 1) {
            tree[2 * v].mod = tree[v].mod;
            tree[2 * v + 1].mod = tree[v].mod;
        }
        tree[v].mod = 0;
    }

    inline int getFirstLess(int val) {
        return getFirstLess(1, 0, n, val);
    }

    int getFirstLess(int v, int vl, int vr, int val) {
        push(v, vl, vr);
        if (tree[v].mn > val) return n;
        if (vr - vl == 1) return vl;

        int vm = (vl + vr) / 2;
        int res = getFirstLess(2 * v, vl, vm, val);
        if (res == n) res = getFirstLess(2 * v + 1, vm, vr, val);
        return res;
    }

    inline void update(int l, int r, int newValue) {
        update(1, 0, n, l, r, newValue);
    }

    void update(int v, int vl, int vr, int l, int r, int newValue) {
        push(v, vl, vr);
        if (r <= vl || vr <= l) return;
        if (l <= vl && vr <= r) {
            tree[v].mod = newValue;
            return;
        }

        int vm = (vl + vr) / 2;
        update(2 * v, vl, vm, l, r, newValue);
        update(2 * v + 1, vm, vr, l, r, newValue);

        push(2 * v, vl, vm);
        push(2 * v + 1, vm, vr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    pair<int, ll> goRight(int v, int vl, int vr, int pos, int sumHave) {
        assert(vr > pos);
        push(v, vl, vr);
        if (vl >= pos && tree[v].sum <= sumHave) {
            return { vr - 1, tree[v].sum };
        }
        if (vr - vl == 1) return { -1, 0 };

        int vm = (vl + vr) / 2;
        if (vm <= pos) return goRight(2 * v + 1, vm, vr, pos, sumHave);

        pair<int, ll> leftSon = goRight(2 * v, vl, vm, pos, sumHave);
        if (leftSon.first == vm - 1) {
            pair<int, ll> rightSon = goRight(2 * v + 1, vm, vr, pos, sumHave - leftSon.second);
            if (rightSon.first != -1) return { rightSon.first, leftSon.second + rightSon.second };
        }
        return leftSon;
    }

    inline pair<int, ll> goRight(int pos, int sumHave) {
        return goRight(1, 0, n, pos, sumHave);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree tree(a);
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        x--;

        if (t == 1) {
            int pos = tree.getFirstLess(y);
            if (pos <= x) tree.update(pos, x + 1, y);
        } else {
            x = max(x, tree.getFirstLess(y));
            int ans = 0;
            while (x != n) {
                auto [to, sum] = tree.goRight(x, y);
//                dbg(x, to, sum);
                assert(sum <= y);
                assert(to >= x);

                ans += to - x + 1;
                y -= sum;
                x = max(to + 1, tree.getFirstLess(y));
            }
            cout << ans << '\n';
        }
    }
}