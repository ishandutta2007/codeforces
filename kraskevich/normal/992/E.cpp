#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

struct Bit {
    vector<ll> f;
    int sz;

    Bit(int n): f(n), sz(n) {}

    ll get(int i) const {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }

    void add(int i, ll d) {
        for (; i < sz; i = (i | (i + 1)))
            f[i] += d;
    }
};

struct Tree {
    vector<pll> val;
    int sz;

    Tree(int n): val(4 * n + 10), sz(n) {}

    void put(int i, int tl, int tr, int pos, ll v) {
        if (tl == tr) {
            val[i] = {v, pos};
            return;
        }
        int m = (tl + tr) / 2;
        if (pos <= m)
            put(2 * i + 1, tl, m, pos, v);
        else
            put(2 * i + 2, m + 1, tr, pos, v);
        val[i] = max(val[2 * i + 1], val[2 * i + 2]);
    }

    void put(int pos, ll v) {
        put(0, 0, sz - 1, pos, v);
    }

    int get_pos(pll v) const {
        return get_pos(0, 0, sz - 1, v);
    }

    int get_pos(int i, int tl, int tr, pll v) const {
        if (tl == tr)
            return tl;
        if (val[i] <= v)
            return -1;
        int m = (tl + tr) / 2;
        if (val[2 * i + 1] > v)
            return get_pos(2 * i + 1, tl, m, v);
        return get_pos(2 * i + 2, m + 1, tr, v);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Tree tree(n);
    Bit bit(n);
    for (int i = 0; i < n; i++) {
        tree.put(i, a[i]);
        bit.add(i, a[i]);
    }
    for (int qq = 0; qq < q; qq++) {
        int ans = -2;
        int pos, val;
        cin >> pos >> val;
        --pos;
        tree.put(pos, val);
        bit.add(pos, val - a[pos]);
        a[pos] = val;
        ll s = 0;
        int i = -1;
        for (;;) {
            i = tree.get_pos({s, i});
            if (i == -1)
                break; 
            ll prev = bit.get(i - 1);
            if (a[i] == prev) {
                ans = i;
                break;
            }
            s = prev + a[i];
        }
        cout << ans + 1 << "\n";
    }
}