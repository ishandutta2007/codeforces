/*
    13.03.2019 22:07:18
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long inf = 1e18l + 100;

struct item {
    bool is_equal = false;
    long long equal = 0;
    long long mx;
    long long sm = 0;
    int l = 0, r = 0;

    item(long long value = -inf, int l = -1, int r = -1): mx(value), l(l), r(r), sm(value) {}

    auto ask_mx() {
        return is_equal ? equal : mx;
    }

    auto ask_sm() {
        return is_equal ? equal * (r - l + 1) : sm;
    }

    auto update(item& a, item& b) {
        if (a.ask_mx() >= b.ask_mx()) {  // return left maximum
            mx = a.ask_mx();
        } else {
            mx = b.ask_mx();
        }
        sm = a.ask_sm() + b.ask_sm();
        l = a.l; r = b.r;
    }
};

item operator + (item a, item b) {
    item c;
    c.update(a, b);
    return c;
}

struct segtree {
    vector< item > tree;
    int n;

    segtree(int size) : n(size), tree(size * 4) {}
    template< typename InType >
    segtree(vector< InType >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template< typename InType >
    void build(vector< InType >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l, l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template< typename InType >
    void set(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].is_equal = true;
            tree[i].equal = k;
            return;
        }
        int m = (vl + vr) / 2;
        if (tree[i].is_equal) {
            tree[i].is_equal = false;
            tree[2 * i + 1].is_equal = true;
            tree[2 * i + 1].equal = tree[i].equal;
            tree[2 * i + 2].is_equal = true;
            tree[2 * i + 2].equal = tree[i].equal;
        }
        if (r <= m) set(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) set(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            set(    l, m, k, 2 * i + 1,    vl,  m);
            set(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template< typename InType >
    void set(int l, int r, InType k) {
        set(l, r, k, 0, 0, n - 1);
    }

    auto ask_mx(int l, int r, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal;
        }
        if (l == vl && r == vr) {
            return tree[i].ask_mx();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_mx(l, r, 2 * i + 1, vl, m);
        if (l > m)
            return ask_mx(l, r, 2 * i + 2, m + 1, vr);
        return max(ask_mx(l, m, 2 * i + 1, vl, m), ask_mx(m + 1, r, 2 * i + 2, m + 1, vr));
    }

    auto ask_mx(int l, int r) {
        return ask_mx(l, r, 0, 0, n - 1);
    }

    auto ask_sm(int l, int r, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal * (r - l + 1);
        }
        if (l == vl && r == vr) {
            return tree[i].ask_sm();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_sm(l, r, 2 * i + 1, vl, m);
        if (l > m)
            return ask_sm(l, r, 2 * i + 2, m + 1, vr);
        return ask_sm(l, m, 2 * i + 1, vl, m) + ask_sm(m + 1, r, 2 * i + 2, m + 1, vr);
    }

    auto ask_sm(int l, int r) {
        return ask_sm(l, r, 0, 0, n - 1);
    }

    template< typename InType >
    auto get_first_bigger_than(int l, int r, InType k, int i, int vl, int vr) {
        if (tree[i].is_equal) {
            return tree[i].equal >= k ? l : n;
        }
        if (vl == vr) {
            return tree[i].ask_mx() >= k ? vl : n;
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return get_first_bigger_than(l, r, k, 2 * i + 1, vl, m);
        } else if (l > m) {
            return get_first_bigger_than(l, r, k, 2 * i + 2, m + 1, vr);
        } else {
            auto ans = get_first_bigger_than(l, m, k, 2 * i + 1, vl, m);
            if (ans < n)
                return ans;
            return get_first_bigger_than(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
    }

    template< typename InType >
    auto get_first_bigger_than(int l, int r, InType k) {
        if (l > r) return n;
        return get_first_bigger_than(l, r, k, 0, 0, n - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector< long long > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector< long long > sk(n);
    vector< long long > ssk(n);
    vector< long long > b(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        int k;
        cin >> k;
        if (i == 0)
            sk[i] = k;
        else
            sk[i] = sk[i - 1] + k;
    }
    ssk[0] = sk[0];
    for (int i = 1; i < n; ++i) {
        b[i] -= sk[i - 1];
        ssk[i] = ssk[i - 1] + sk[i];
    }
    auto ssk_sum = [&](int l, int r) {
        long long ans = 0;
        if (r >= 0) ans += ssk[r];
        if (l >= 1) ans -= ssk[l - 1];
        return ans;
    };
    segtree t(b);
    int q;
    cin >> q;
    show(sk, b);
    for (int i = 0; i < q; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            int ind, x;
            cin >> ind >> x;
            --ind;
            long long bi = t.ask_mx(ind, ind) + x;
            show(bi);
            show(ind+1, n-1, bi);
            int j = t.get_first_bigger_than(ind + 1, n - 1, bi);
            show(j);
            t.set(ind, j - 1, bi);
        }
        if (c == 's') {
            int l, r;
            cin >> l >> r;
            --l; --r;
            long long ans = t.ask_sm(l, r);
            ans += ssk_sum(l - 1, r - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}