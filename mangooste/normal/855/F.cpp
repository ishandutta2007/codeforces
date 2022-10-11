#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

#define data __data__

struct segtree {
    struct node {
        int max, cnt, second, mod;
        ll sum;

        node() {}
        node(int x) : max(x), cnt(1), second(INT_MIN), mod(INT_MAX), sum(x) {}
    };

    int n;
    vec<node> tree;

    segtree(int n, int val) : n(n), tree(4 * n) {
        build(1, 0, n, val);
    }

    inline node merge(node a, node b) const {
        assert(a.mod == INT_MAX && b.mod == INT_MAX);
        if (a.max < b.max)
            swap(a, b);

        node res;
        res.mod = INT_MAX;
        res.sum = a.sum + b.sum;

        res.max = a.max;
        res.cnt = a.cnt;
        if (b.max == a.max) {
            res.cnt += b.cnt;
            res.second = max(a.second, b.second);
        } else {
            res.second = max(a.second, b.max);
        }

        return res;
    }

    void build(int v, int vl, int vr, int val) {
        if (vr - vl == 1) {
            tree[v] = node(val);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, val);
        build(v << 1 | 1, vm, vr, val);

        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    inline void push(int v, int vl, int vr) {
        if (tree[v].mod == INT_MAX)
            return;

        if (vr - vl > 1) {
            tree[v << 1].mod = min(tree[v << 1].mod, tree[v].mod);
            tree[v << 1 | 1].mod = min(tree[v << 1 | 1].mod, tree[v].mod);
        }

        assert(tree[v].mod > tree[v].second);
        if (tree[v].mod < tree[v].max) {
            tree[v].sum -= 1ll * tree[v].cnt * tree[v].max;
            tree[v].max = tree[v].mod;
            tree[v].sum += 1ll * tree[v].cnt * tree[v].max;
        }

        tree[v].mod = INT_MAX;
    }

    inline void setmin(int l, int r, int val) {
        setmin(1, 0, n, l, r, val);
    }

    void setmin(int v, int vl, int vr, int l, int r, int val) {
        push(v, vl, vr);
        if (r <= vl || vr <= l || val >= tree[v].max)
            return;

        if (l <= vl && vr <= r && val > tree[v].second) {
            tree[v].mod = min(tree[v].mod, val);
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        setmin(v << 1, vl, vm, l, r, val);
        setmin(v << 1 | 1, vm, vr, l, r, val);

        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    inline void set(int pos, int val) {
        set(1, 0, n, pos, val);
    }

    void set(int v, int vl, int vr, int pos, int val) {
        push(v, vl, vr);
        if (pos < vl || vr <= pos)
            return;

        if (vr - vl == 1) {
            tree[v] = node(val);
            return;
        }

        int vm = (vl + vr) >> 1;
        set(v << 1, vl, vm, pos, val);
        set(v << 1 | 1, vm, vr, pos, val);

        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    inline ll get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    ll get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return 0;

        if (l <= vl && vr <= r)
            return tree[v].sum;

        int vm = (vl + vr) >> 1;
        return get(v << 1, vl, vm, l, r) + get(v << 1 | 1, vm, vr, l, r);
    }
};

struct data {
    segtree tot;
    segtree sum;
    set<int> free;

    data(int n) : tot(n, INT_MAX), sum(n, 0) {
        for (int i = 0; i < n; i++)
            free.insert(i);
    }

    inline void update(int l, int r, int val, data &d) {
        while (true) {
            auto it = free.lower_bound(l);
            if (it == free.end() || *it >= r)
                break;

            int pos = *it;
            free.erase(it);

            if (!d.free.count(pos)) {
                sum.set(pos, val);
                d.sum.set(pos, d.tot.get(pos, pos + 1));
            }
        }

        tot.setmin(l, r, val);
        sum.setmin(l, r, val);
    }

    inline ll get(int l, int r) {
        return sum.get(l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    const int N = 1e5 + 4;
    data up(N);
    data down(N);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            assert(k != 0);

            if (k > 0)
                up.update(l, r, k, down);
            else
                down.update(l, r, -k, up);
        } else {
            int l, r;
            cin >> l >> r;
            cout << up.get(l, r) + down.get(l, r) << '\n';
        }
    }
}