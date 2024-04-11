/*
    17.03.2019 18:08:52
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

vector< long long > x, t, l;
vector< vector< int > > g;
vector< bool > u;
vector< long long > tv;
vector< long long > mx;
int n;
long long T;

auto compress(vector< long long >& v, int from = 0) {
    set< long long > s;
    for (auto k : v) {
        s.insert(k);
    }
    vector< long long > vs(s.begin(), s.end());
    return vs;
    for (auto& k : v) {
        k = from + distance(vs.begin(), lower_bound(vs.begin(), vs.end(), k));
    }
}

struct item {
    long long cnt = 0;
    long long t = 0;
    // long long value;

    // item(long long value = 0, long long cnt = 0): value(value), cnt(cnt), t(cnt * value) {}

    void update(item& a, item& b) {
        cnt = a.cnt + b.cnt;
        t = a.t + b.t;
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

    segtree(int size = 1) : n(size), tree(size * 4) {}
    // segtree(vector< T >& v) : n(v.size()), tree(v.size() * 4) {
    //     build(v, 0, 0, n - 1);
    // }

    // void build(vector< T >& v, int i, int l, int r) {
    //     if (l == r) {
    //         tree[i] = v[l];
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     build(v, i * 2 + 1, l, m);
    //     build(v, i * 2 + 2, m + 1, r);
    //     tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    // }

    void add(int ind, long long k, int i, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i = 2 * i + 1;
            } else {
                l = m + 1;
                i = 2 * i + 2;
            }
        }
        // show(l, k, tv);
        tree[i].cnt += k;
        tree[i].t = tv[l] * tree[i].cnt;
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void add(int ind, long long k) {
        add(ind, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return ask(l, r, 2 * i + 1, vl, m);
        }
        if (l > m) {
            return ask(l, r, 2 * i + 2, m + 1, vr);
        }
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr);
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }

    long long get_cnt(long long t, int i, int vl, int vr) {
        if (vl == vr) {
            // showt(i, t, vl, tv);
            // show(tv[vl]);
            // show(t/tv[vl]);
            return t / tv[vl];
        }
        int m = (vl + vr) / 2;
        if (tree[2 * i + 1].t >= t) return get_cnt(t, 2 * i + 1, vl, m);
        else return tree[2 * i + 1].cnt + get_cnt(t - tree[2 * i + 1].t, 2 * i + 2, m + 1, vr);
    }

    long long get_cnt(long long t) {
        // show(t, tree[0].t);
        if (tree[0].t <= t) return tree[0].cnt;
        return get_cnt(t, 0, 0, n - 1);
    }
};

segtree tr;

void dfs(int v, long long tt = 0) {
    tt += l[v] * 2;
    u[v] = true;
    int ind = lower_bound(tv.begin(), tv.end(), t[v]) - tv.begin();
    tr.add(ind, x[v]);
    if (T < tt) {
        mx[v] = 0;
        tr.add(ind, -x[v]);
        return;
    }
    mx[v] = tr.get_cnt(T - tt);
    // showt(v, tt, mx[v]);
    // for (int i = 0; i < n; ++i) {
    //     shows;
    //     auto it = tr.ask(i, i);
    //     show(i, it.cnt, it.t);
    // }
    // show(ind, x[v]);
    long long mx1 = 0, mx2 = 0;
    for (auto k : g[v]) {
        if (!u[k]) {
            dfs(k, tt);
            if (mx[k] >= mx1) {
                mx2 = mx1;
                mx1 = mx[k];
            } else if (mx[k] > mx2) {
                mx2 = mx[k];
            }
        }
    }
    if (v == 0) mx[v] = max(mx[v], mx1);
    else mx[v] = max(mx[v], mx2);
    tr.add(ind, -x[v]);
}

int main() {
    cin >> n;
    tr = segtree(n + 5);
    cin >> T;
    x.resize(n);
    t.resize(n);
    l.resize(n);
    mx.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    g.resize(n);
    u.assign(n, false);
    l[0] = 0;
    for (int i = 1; i < n; ++i) {
        int p, s;
        cin >> p >> s;
        --p;
        g[p].push_back(i);
        l[i] = s;
    }
    tv = compress(t);
    // show(tv);
    dfs(0);
    // printTree(g, 0, x);
    cout << mx[0] << '\n';
    // for (int i = 0; i < n; ++i) {
    //     cout << mx[i] << ' ';
    // }
    // cout << '\n';
    // show(mx);
    return 0;
}