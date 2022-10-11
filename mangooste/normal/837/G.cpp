#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

#define data data_dosent_compile

struct data {
    int l, r, left, right, a, b;

    data() {}

    friend istream& operator>>(istream &in, data &d) {
        in >> d.l >> d.r >> d.left >> d.a >> d.b >> d.right;
        d.l++;
        return in;
    }
};

struct segtree {
    struct node {
        ar<ll, 4> sum;
        int left, right;

        node() : sum({0, 0, 0, 0}), left(-1), right(-1) {}
    };

    int n;
    bool left;
    vec<node> tree;
    vec<int> vers;
    static const int N = 2e5 + 5;

    segtree(vec<data> &a, bool left) : n(len(a)), left(left) {
        int root = build(0, N);
        vers.push_back(root);
        for (auto x : a) {
            root = update(root, 0, N, (left ? x.l : x.r), x);
            vers.push_back(root);
        }
    }

    inline int new_node() {
        tree.push_back(node());
        return len(tree) - 1;
    }

    int build(int vl, int vr) {
        int cur = new_node();
        if (vr - vl == 1) {
            return cur;
        }
        int vm = (vl + vr) / 2;
        tree[cur].left = build(vl, vm);
        tree[cur].right = build(vm, vr);
        return cur;
    }

    inline ar<ll, 4> merge(ar<ll, 4> left, ar<ll, 4> right) {
        ar<ll, 4> tot;
        for (int i = 0; i < 4; i++) {
            tot[i] = left[i] + right[i];
        }
        return tot;
    }

    inline void relax(int v) {
        tree[v].sum = merge(tree[tree[v].left].sum, tree[tree[v].right].sum);
    }

    int update(int v, int vl, int vr, int pos, const data &d) {
        if (pos < vl || vr <= pos) {
            return v;
        }
        if (vr - vl == 1) {
            int u = new_node();
            tree[u].sum = merge(tree[v].sum, {d.a, d.b, d.left, d.right});
            return u;
        }
        int u = new_node();
        tree[u] = tree[v];
        int vm = (vl + vr) / 2;
        tree[u].left = update(tree[u].left, vl, vm, pos, d);
        tree[u].right = update(tree[u].right, vm, vr, pos, d);
        relax(u);
        return u;
    }

    inline ar<ll, 4> get(int v, int l, int r) {
        return get(v, 0, N, l, r);
    }

    ar<ll, 4> get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) {
            return {0, 0, 0, 0};
        }
        if (l <= vl && vr <= r) {
            return tree[v].sum;
        }
        int vm = (vl + vr) / 2;
        return merge(get(tree[v].left, vl, vm, l, r), get(tree[v].right, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<data> a(n);
    for (auto &d : a) {
        cin >> d;
    }
    segtree treer(a, false);
    segtree treel(a, true);
    int q;
    cin >> q;
    ll ans = 0;
    auto solve = [&](int r, int x) -> ll {
        if (r == 0) {
            return 0;
        }
        ll ans = 0;
        {
            auto cur = treel.get(treel.vers[r], 0, segtree::N);
            ans += cur[0] * x + cur[1];
        }
        {
            auto cur = treer.get(treer.vers[r], 0, x);
            ans -= cur[0] * x + cur[1];
            ans += cur[3];
        }
        {
            auto cur = treel.get(treel.vers[r], x + 1, segtree::N);
            ans -= cur[0] * x + cur[1];
            ans += cur[2];
        }
        return ans;
    };
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        x = (x + ans) % int(1e9);
        ans = solve(r, x) - solve(l, x);
        cout << ans << '\n';
    }
}