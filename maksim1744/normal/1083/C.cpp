/*
    author:  Maksim1744
    created: 26.04.2019 22:47:40
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

vector<vector<int>> g;
vector<int> p;
vector<int> ip;
int n;

vector<int> lca_ind;
vector<vector<int>> lca_sparse;
vector<int> lca_p2;
vector<int> lca_depth;
void build_lca_sparse(vector<vector<int>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto k : g[v]) {
            if (lca_depth[k] == -1) {
                dfs(k, depth + 1);
                euler.pb(v);
            }
        }
    };
    dfs(root, 0);
    int m = euler.size();
    show(euler, lca_ind, lca_depth);
    int log = 1;
    while ((1 << log) < m)
        ++log;
    lca_sparse.resize(log);
    lca_sparse[0].resize(m);
    lca_p2.resize(m + 1);
    int pp2 = 0;
    for (int i = 1; i < lca_p2.size(); ++i) {
        if (1 << (pp2 + 1) <= i)
            ++pp2;
        lca_p2[i] = pp2;
    }
    lca_p2[0] = 0;
    for (int i = 0; i < m; ++i)
        lca_sparse[0][i] = euler[i];
    for (int i = 1; i < log; ++i) {
        lca_sparse[i].assign(m, 0);
        for (int j = 0; j < m - (1 << (i - 1)); ++j) {
            int v1 = lca_sparse[i - 1][j], v2 = lca_sparse[i - 1][j + (1 << (i - 1))];
            if (lca_depth[v1] < lca_depth[v2])
                lca_sparse[i][j] = v1;
            else
                lca_sparse[i][j] = v2;
        }
    }
    show(lca_sparse);
}
int get_lca(int u, int v) {
    if (u == v)
        return u;
    u = lca_ind[u];
    v = lca_ind[v];
    if (u > v)
        swap(u, v);
    int v1 = lca_sparse[lca_p2[v - u + 1]][u], v2 = lca_sparse[lca_p2[v - u + 1]][v - (1 << lca_p2[v - u + 1]) + 1];
    if (lca_depth[v1] < lca_depth[v2])
        return v1;
    else
        return v2;
}
int dist(int u, int v) {
    return lca_depth[u] + lca_depth[v] - 2 * lca_depth[get_lca(u, v)];
}

using T = pair<int, int>;

pair<int, int> operator + (pair<int, int>& a, pair<int, int>& b) {
    if (a.first == -1 || b.first == -1)
        return {-1, -1};
    vector<int> check = {a.first, a.second, b.first, b.second};
    // shows;
    for (int i = 0; i < check.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            bool ok = true;
            int d = dist(check[i], check[j]);
            // show(check[i], check[j], d);
            for (int k = 0; k < check.size(); ++k) {
                if (check[k] == check[i] || check[k] == check[j])
                    continue;
                if (dist(check[i], check[k]) + dist(check[k], check[j]) != d) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return {check[i], check[j]};
        }
    }
    // show(a, b);
    return {-1, -1};
}

struct segtree {
    vector<T> tree;
    int n;

    segtree(int n) : n(n), tree(n * 4) {
        build(0, 0, n - 1);
    }

    void build(int i, int l, int r) {
        if (l == r) {
            tree[i] = {ip[l], ip[l]};
            return;
        }
        int m = (l + r) / 2;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void set(int ind, int k, int i, int l, int r) {
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
        tree[i] = {k, k};
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        }
    }

    void set(int ind, int k) {
        set(ind, k, 0, 0, n - 1);
    }

    int ask(int l, int r, int i, pair<int, int> now) {
        // show(i, l, r, now);
        if (l == r) {
            return ((now + tree[i]).first != -1);
        }
        int m = (l + r) / 2;
        auto pr = now + tree[2 * i + 1];
        if (pr.first == -1) {
            return ask(l, m, 2 * i + 1, now);
        } else {
            return m + 1 - l + ask(m + 1, r, 2 * i + 2, pr);
        }
    }

    int ask() {
        if (tree[0].first != -1)
            return n;
        return ask(0, n - 1, 0, {ip[0], ip[0]});
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    p.resize(n);
    ip.resize(n);
    cin >> p;
    for (int i = 0; i < n; ++i)
        ip[p[i]] = i;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int pi;
        cin >> pi;
        --pi;
        g[pi].pb(i);
    }
    printTree(g, p);
    build_lca_sparse(g, 0);
    segtree tree(n);
    int q;
    cin >> q;
    for (int iii = 0; iii < q; ++iii) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            swap(p[u], p[v]);
            swap(ip[p[u]], ip[p[v]]);
            tree.set(p[u], u);
            tree.set(p[v], v);
            printTree(g, p);
        } else if (t == 2) {
            cout << tree.ask() << '\n';
        }
    }
    return 0;
}