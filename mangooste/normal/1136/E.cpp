#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

struct segtree {
    struct node {
        ll sum, mx, mod;
    };

    node merge(const node &left, const node &right) {
        return {left.sum + right.sum, max(left.mx, right.mx), LLONG_MIN};
    }

    int n;
    vector<node> tree;

    segtree(const vector<ll> &a) : n(len(a)), tree(4 * n) {
        build(1, 0, n, a);
    }

    void build(int v, int vl, int vr, const vector<ll> &a) {
        if (vr - vl == 1) {
            tree[v] = {a[vl], a[vl], LLONG_MIN};
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, a);
        build(v << 1 | 1, vm, vr, a);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    void apply(int v, int vl, int vr, ll value) {
        tree[v].sum = (vr - vl) * value;
        tree[v].mx = value;
        tree[v].mod = value;
    }

    void push(int v, int vl, int vr) {
        if (tree[v].mod == LLONG_MIN)
            return;

        int vm = (vl + vr) >> 1;
        apply(v << 1, vl, vm, tree[v].mod);
        apply(v << 1 | 1, vm, vr, tree[v].mod);
        tree[v].mod = LLONG_MIN;
    }

    ll add(int pos, ll value) {
        return add(1, 0, n, pos, value);
    }

    ll add(int v, int vl, int vr, int pos, ll value) {
        if (vr - vl == 1) {
            tree[v].sum += value;
            tree[v].mx += value;
            return tree[v].sum;
        }

        int vm = (vl + vr) >> 1;
        push(v, vl, vr);
        ll res = pos < vm ? add(v << 1, vl, vm, pos, value) : add(v << 1 | 1, vm, vr, pos, value);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
        return res;
    }

    void set(int l, int r, ll value) {
        set(1, 0, n, l, r, value);
    }

    void set(int v, int vl, int vr, int l, int r, ll value) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            apply(v, vl, vr, value);
            return;
        }

        int vm = (vl + vr) >> 1;
        push(v, vl, vr);
        set(v << 1, vl, vm, l, r, value);
        set(v << 1 | 1, vm, vr, l, r, value);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int find(int pos, ll value) {
        return find(1, 0, n, pos, value);
    }

    int find(int v, int vl, int vr, int pos, ll value) {
        if (vr <= pos || tree[v].mx <= value)
            return n;

        if (vr - vl == 1)
            return vl;

        int vm = (vl + vr) >> 1;
        push(v, vl, vr);
        int res = find(v << 1, vl, vm, pos, value);
        return res == n ? find(v << 1 | 1, vm, vr, pos, value) : res;
    }

    ll query(int l, int r) {
        return query(1, 0, n, l, r);
    }

    ll query(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l)
            return 0;

        if (l <= vl && vr <= r)
            return tree[v].sum;

        int vm = (vl + vr) >> 1;
        push(v, vl, vr);
        return query(v << 1, vl, vm, l, r) + query(v << 1 | 1, vm, vr, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> k(n), pref(n);
    for (int i = 1; i < n; i++) {
        cin >> k[i];
        k[i] += k[i - 1];
        a[i] -= k[i];
        pref[i] = pref[i - 1] + k[i];
    }

    assert(is_sorted(all(a)));
    segtree tree(a);

    int q;
    cin >> q;
    while (q--) {
        char type;
        cin >> type;

        if (type == '+') {
            int pos, x;
            cin >> pos >> x;
            pos--;

            ll value = tree.add(pos, x);
            tree.set(pos, tree.find(pos, value), value);
        } else if (type == 's') {
            int l, r;
            cin >> l >> r;
            l--;
            cout << tree.query(l, r) + pref[r - 1] - (l == 0 ? 0 : pref[l - 1]) << '\n';
        } else {
            assert(false);
        }
    }
}