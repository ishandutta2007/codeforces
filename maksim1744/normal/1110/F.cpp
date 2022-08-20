/*
    07.02.2019 21:52:03
*/

#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000ll * 1000000000ll;

struct str {
    long long mn = inf;
    long long sm = 0;
};

#ifdef HOME
string to_string(str s);
#include "C:/C++ libs/print.h"
string to_string(str s) {
    return "(" + to_string(s.mn) + ", + " + to_string(s.sm) + ")";
}
#define show(x) cout << "     " << #x << " = " << to_string(x) << endl;
#else
#define show(x) 42;
#define print(x) 42;
#define printTree(x) 42;
#define printMatrix(x) 42;
#endif

struct query {
    int l, r, i;

    query(int l, int r, int i) : l(l), r(r), i(i) {}
};

const int mxn = 500005;

int n;
array< vector< pair< int, long long > >, mxn > children;
array< vector< int >, mxn > p;
array< long long, mxn > d;
array< bool, mxn > u;
array< pair< int, int >, mxn > ch;
array< vector< query >, mxn > qu;
array< long long, mxn > ans;
array< int, mxn > lt, rt, indl;

str operator + (str a, str b) {
    str c;
    c.mn = min(a.mn + a.sm, b.mn + b.sm);
    c.sm = 0;
    return c;
}

using T = str;

struct segtree {
    array< T, mxn * 3 > tree;
    int n;

    segtree() {}
    segtree(vector< long long >& v) : n(v.size()) {
        build(v, 0, 0, n - 1);
    }

    void build(vector< long long >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = {v[l], 0};
            // show(l);
            // show(indl);
            // show(d);
            // show(tree[i]);
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void add(int l, int r, long long k, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].sm += k;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            add(l, r, k, 2 * i + 1, vl, m);
        } else if (l > m) {
            add(l, r, k, 2 * i + 2, m + 1, vr);
        } else {
            add(l, m, k, 2 * i + 1, vl, m);
            add(m + 1, r, k, 2 * i + 2, m + 1, vr);
        }
        tree[i].mn = min(tree[2 * i + 1].mn + tree[2 * i + 1].sm,
                         tree[2 * i + 2].mn + tree[2 * i + 2].sm);
    }

    void add(int l, int r, long long k) {
        add(indl[rt[l]], indl[lt[r]], k, 0, 0, n - 1);
    }

    long long ask(int l, int r, int i, int vl, int vr) {
        // show(l);
        // show(r);
        // show(i);
        // show(vl);
        // show(vr);
        if (l == vl && r == vr) {
            return tree[i].mn + tree[i].sm;
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return ask(l, r, 2 * i + 1, vl, m) + tree[i].sm;
        }
        if (l > m) {
            return ask(l, r, 2 * i + 2, m + 1, vr) + tree[i].sm;
        }
        return min(ask(l, m, 2 * i + 1, vl, m), ask(m + 1, r, 2 * i + 2, m + 1, vr)) + tree[i].sm;
    }

    long long ask(int l, int r) {
        if (r < l) {
            return inf;
        }
        return ask(indl[rt[l]], indl[lt[r]], 0, 0, n - 1);
    }
};

segtree t;

void dfs(int v, long long h = 0, int lvl = 0) {
    u[v] = true;
    d[v] = h;
    // level[v] = lvl;
    ch[v] = {mxn, -1};
    bool leaf = true;
    for (auto child : children[v]) {
        if (!u[child.first]) {
            dfs(child.first, h + child.second, lvl + 1);
            ch[v].first = min(ch[v].first, ch[child.first].first);
            ch[v].second = max(ch[v].second, ch[child.first].second);
            leaf = false;
        }
    }
    if (leaf) {
        ch[v] = {v, v};
    }
}

void dfs2(int v) {
    u[v] = true;
    int vl = ch[v].first, vr = ch[v].second;
    for (auto q : qu[v]) {
        ans[q.i] = t.ask(q.l, q.r);
    }
    for (auto c : children[v]) {
        if (!u[c.first]) {
            t.add(0, n - 1, c.second);
            t.add(ch[c.first].first, ch[c.first].second, -c.second * 2);
            dfs2(c.first);
            t.add(ch[c.first].first, ch[c.first].second, c.second * 2);
            t.add(0, n - 1, -c.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        u[i] = false;
    }
    for (int i = 0; i < n - 1; ++i) {
        int pp, w;
        cin >> pp >> w;
        --pp;
        p[i + 1].push_back(pp);
        children[pp].emplace_back(i + 1, w);
    }
    int ln = -1;
    for (int i = 0; i < n; ++i) {
        if (children[i].size() == 0) {
            ln = i;
        }
        lt[i] = ln;
    }
    int rn = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (children[i].size() == 0) {
            rn = i;
        }
        rt[i] = rn;
    }
    dfs(0);
    vector< long long > leafs;
    for (int i = 0; i < n; ++i) {
        if (children[i].size() == 0) {
            // indl[leafs.size()] = i;
            indl[i] = leafs.size();
            leafs.push_back(d[i]);
        }
    }
    // show(leafs);
    // show(lt);
    // show(rt);
    // show(indl);
    // show(d);
    t = segtree(leafs);
    // t.add(2, 3, 6);
    // show(t.tree);
    // show(t.ask(2, 4));
    for (int test = 0; test < q; ++test) {
        int v, l, r;
        cin >> v >> l >> r;
        --v; --l; --r;
        l = rt[l];
        r = lt[r];
        qu[v].emplace_back(l, r, test);
    }
    for (int i = 0; i < n; ++i) {
        u[i] = false;
    }
    // show(ch);
    dfs2(0);
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}