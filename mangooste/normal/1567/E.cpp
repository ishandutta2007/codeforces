#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct segtree {
    struct node {
        ll answer;
        int left;
        int right;
        int up_left;
        int down_right;
        int length;

        node(int x = 0) : answer(1), left(x), right(x), up_left(1), down_right(1), length(1) {}
    };

    node merge(const node &left, const node &right) {
        node res;
        res.left = left.left;
        res.right = right.right;
        res.length = left.length + right.length;

        res.answer = left.answer + right.answer;
        if (left.right <= right.left)
            res.answer += 1ll * left.down_right * right.up_left;

        res.down_right = right.down_right;
        if (right.down_right == right.length && left.right <= right.left)
            res.down_right += left.down_right;

        res.up_left = left.up_left;
        if (left.up_left == left.length && left.right <= right.left)
            res.up_left += right.up_left;

        return res;
    }

    int n;
    vector<node> tree;

    segtree(const vector<int> &a) : n(len(a)), tree(4 * n) {
        build(1, 0, n, a);
    }

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vr - vl == 1) {
            tree[v] = node(a[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, a);
        build(v << 1 | 1, vm, vr, a);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void update(int pos, int value) {
        update(1, 0, n, pos, value);
    }

    void update(int v, int vl, int vr, int pos, int value) {
        if (vr - vl == 1) {
            tree[v] = node(value);
            return;
        }

        int vm = (vl + vr) >> 1;
        pos < vm ? update(v << 1, vl, vm, pos, value) : update(v << 1 | 1, vm, vr, pos, value);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    node get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    node get(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return tree[v];

        int vm = (vl + vr) >> 1;
        if (l < vm && vm < r)
            return merge(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r));

        return l < vm ? get(v << 1, vl, vm, l, r) : get(v << 1 | 1, vm, vr, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    segtree tree(a);
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--;

        if (type == 1)
            tree.update(a, b);
        else
            cout << tree.get(a, b).answer << '\n';
    }
}