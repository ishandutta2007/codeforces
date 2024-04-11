/*
    23.03.2019 17:18:39
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

const long long inf = 1e9l * 1e9l;

struct query {
    int u, v;
    int i;

    void read(int i_) {
        i = i_;
        cin >> u >> v;
        --u; --v;
    }
};

int n;
vector<vector<pair<int, pair<long long, long long>>>> g;
vector<long long> wh;
vector<long long> ans;
vector<query> queries;
vector<bool> forbidden;
vector<int> u;
int step = 0;
vector<int> sz;
vector<pair<pair<long long, long long>, pair<long long, long long>>> dist;

void set_sizes(int v) {
    u[v] = step;
    sz[v] = 1;
    for (auto k : g[v]) {
        if (!forbidden[k.first] && u[k.first] < step) {
            set_sizes(k.first);
            sz[v] += sz[k.first];
        }
    }
}

int find_centroid(int v, int root = -1, int p = -1) {
    if (root == -1)
        root = v;
    for (auto k : g[v]) {
        if (!forbidden[k.first] && k.first != p && sz[k.first] * 2 >= sz[root])
            return find_centroid(k.first, root, v);
    }
    return v;
}

void set_colors(int v) {
    u[v] = step;
    for (auto k : g[v]) {
        if (!forbidden[k.first] && u[k.first] < step)
            set_colors(k.first);
    }
}

void set_distances(int v, pair<pair<long long, long long>, pair<long long, long long>> d, int p = -1) {
    dist[v] = d;
    for (auto k : g[v]) {
        if (!forbidden[k.first] && k.first != p) {
            auto dd = d;
            dd.first.first = d.first.first + k.second.first;
            dd.first.second = d.first.second + k.second.second;
            dd.second.first = d.second.first + k.second.first;
            dd.second.second = d.second.second + k.second.second;
            dd.first.first = min(dd.first.first, dd.first.second + wh[k.first]);
            dd.first.second = min(dd.first.second, dd.first.first + wh[k.first]);
            dd.second.first = min(dd.second.first, dd.second.second + wh[k.first]);
            dd.second.second = min(dd.second.second, dd.second.first + wh[k.first]);
            set_distances(k.first, dd, v);
        }
    }
}

void do_it(int v, vector<query>& qs) {
    ++step;
    set_sizes(v);
    int c = find_centroid(v);
    // show(c);
    forbidden[c] = true;
    int base_color = step + 1;
    for (auto k : g[c]) {
        if (!forbidden[k.first]) {
            ++step;
            set_colors(k.first);
        }
    }
    set_distances(c, {make_pair(0ll, wh[c]), make_pair(wh[c], 0ll)});
    vector<query> qs_now;
    vector<vector<query>> qs_next(step - base_color + 1);
    for (auto q : qs) {
        showt(c, u, q.u/2, q.v/2, base_color);
        if (q.u / 2 == c && q.v / 2 == c) {
            qs_now.push_back(q);
        } else if (u[q.u / 2] == u[q.v / 2]) {
            qs_next[u[q.u / 2] - base_color].push_back(q);
            // long long d11, d12, d21, d22;
            // if (q.u % 2 == 0) {
            //     d11 = dist[q.u / 2].first.first;
            //     d21 = dist[q.u / 2].second.first;
            // } else {
            //     d11 = dist[q.u / 2].first.second;
            //     d21 = dist[q.u / 2].second.second;
            // }
            // if (q.v % 2 == 0) {
            //     d12 = dist[q.v / 2].first.first;
            //     d22 = dist[q.v / 2].second.first;
            // } else {
            //     d12 = dist[q.v / 2].first.second;
            //     d22 = dist[q.v / 2].second.second;
            // }
            // ans[q.i] = min({ans[q.i], d11 + d12, d21 + d22});
        } else {
            qs_now.push_back(q);
        }
    }
    // show(qs_now.size());
    // showt(c, dist);
    for (auto q : qs_now) {
        long long d11, d12, d21, d22;
        if (q.u % 2 == 0) {
            d11 = dist[q.u / 2].first.first;
            d21 = dist[q.u / 2].second.first;
        } else {
            d11 = dist[q.u / 2].first.second;
            d21 = dist[q.u / 2].second.second;
        }
        if (q.v % 2 == 0) {
            d12 = dist[q.v / 2].first.first;
            d22 = dist[q.v / 2].second.first;
        } else {
            d12 = dist[q.v / 2].first.second;
            d22 = dist[q.v / 2].second.second;
        }
        ans[q.i] = min({ans[q.i], d11 + d12, d21 + d22});
        // showt(c, dist, d11, d12, d21, d22, q.i, q.u, q.v);
    }
    int ind = 0;
    for (auto k : g[c]) {
        if (!forbidden[k.first]) {
            do_it(k.first, qs_next[ind]);
            ++ind;
        }
    }
}

struct item {
    long long mx = 0;
    long long ind = 0;  // index of maximum
    long long sm = 0;

    item() {}
    item(long long mx, long long ind = 0): mx(mx), ind(ind), sm(0) {}

    auto ask() {
        return mx + sm;
    }

    auto update(item& a, item& b) {
        if (a.ask() <= b.ask()) {  // return left maximum
            mx = a.ask();
            ind = a.ind;
        } else {
            mx = b.ask();
            ind = b.ind;
        }
        return *this;
    }
};

item operator + (item a, item b) {
    return item().update(a, b);
}

item operator + (item a, int b) {
    item c = a;
    c.mx += b;
    return c;
}

struct segtree {
    vector< item > tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, item()) {}
    template< typename InType >
    segtree(vector< InType >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    template< typename InType >
    void build(vector< InType >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = item(v[l], l);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    template< typename InType >
    void set(int ind, InType k, int i, int vl, int vr) {
        if (vl == vr) {
            tree[i].mx = k - tree[i].sm;
            return;
        }
        int m = (vl + vr) / 2;
        if (ind <= m) set(ind, k - tree[i].sm, 2 * i + 1, vl, m);
        else set(ind, k - tree[i].sm, 2 * i + 2, m + 1, vr);
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template< typename InType >
    void set(int ind, InType k) {
        set(ind, k, 0, 0, n - 1);
    }

    template< typename InType >
    void add(int l, int r, InType k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, k, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, k, 2 * i + 2, m + 1, vr);
        else {
            add(    l, m, k, 2 * i + 1,    vl,  m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].update(tree[2 * i + 1], tree[2 * i + 2]);
    }

    template< typename InType >
    void add(int l, int r, InType k) {
        add(l, r, k, 0, 0, n - 1);
    }

    auto ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i].ask();
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return min(ask(l, m, 2 * i + 1, vl, m), ask(m + 1, r, 2 * i + 2, m + 1, vr)) + tree[i].sm;
    }

    auto ask(int l, int r) {
        return ask(l, r, 0, 0, n - 1);
    }

    auto ask_item(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return item(tree[i].ask(), tree[i].ind);
        }
        int m = (vl + vr) / 2;
        if (r <= m)
            return ask_item(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        if (l > m)
            return ask_item(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        return ask_item(l, m, 2 * i + 1, vl, m) + ask_item(m + 1, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
    }

    auto ask_item(int l, int r) {
        return ask_item(l, r, 0, 0, n - 1);
    }
};

int main() {
    cin >> n;
    g.resize(n);
    wh.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> wh[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        pair<long long, long long> w;
        cin >> w.first >> w.second;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int q;
    cin >> q;
    ans.assign(q, inf);
    queries.resize(q);
    for (int i = 0; i < q; ++i) {
        queries[i].read(i);
    }
    forbidden.assign(n, false);
    u.assign(n, -1);
    sz.assign(n, 0);
    dist.resize(n);

    vector<long long> d1(n), d2(n);
    vector<int> num(n);
    vector<int> rt(n);
    vector<int> order;
    int counter = -1;
    vector<bool> tmpu(n, false);
    function<void(int, long long, long long)> tmpdfs = [&](int v, long long dd1, long long dd2) -> void {
        tmpu[v] = true;
        num[v] = ++counter;
        order.push_back(v);
        rt[v] = num[v];
        d1[v] = dd1;
        d2[v] = dd2 + wh[v];
        for (auto k : g[v]) {
            if (!tmpu[k.first]) {
                tmpdfs(k.first, dd1 + k.second.first, dd2 + k.second.second);
                rt[v] = max(rt[v], rt[k.first]);
            }
        }
    };
    tmpdfs(0, 0, 0);
    vector<long long> rd1(n), rd2(n);
    for (int i = 0; i < n; ++i) {
        rd1[i] = d1[order[i]] + d2[order[i]];
        rd2[i] = d2[order[i]];
    }
    show(d1, d2, rd1, rd2);
    segtree t1(rd1), t2(rd2);
    tmpu.assign(n, false);
    vector<long long> wh_new(n, inf);
    function<void(int)> dfs2 = [&](int v) {
        tmpu[v] = true;
        show(v, num[v]);
        wh_new[v] = min(wh_new[v], t1.ask(0, n - 1));// + t2.ask(0, n - 1));
        for (auto k : g[v]) {
            if (!tmpu[k.first]) {
                t1.add(0, n - 1, k.second.first + k.second.second);
                t1.add(num[k.first], rt[k.first], -2ll * k.second.first - 2ll * k.second.second);
                // t2.add(0, n - 1, k.second.second);
                // t2.add(num[k.first], rt[k.first], -2ll * k.second.second);
                dfs2(k.first);
                t1.add(0, n - 1, -k.second.first - k.second.second);
                t1.add(num[k.first], rt[k.first], 2ll * k.second.first + 2ll * k.second.second);
                // t2.add(num[k.first], rt[k.first], 2ll * k.second.second);
                // t2.add(0, n - 1, -k.second.second);
            }
        }
    };
    dfs2(0);

    show(wh, wh_new);

    for (int i = 0; i < n; ++i) {
        wh[i] = min(wh[i], wh_new[i]);
    }

    do_it(0, queries);
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}