/*
    author:  Maksim1744
    created: 17.05.2021 20:22:45
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

namespace segtree1 {
struct item {
    int s = 0;
    int ind = -1;

    template<typename T>
    void init(const T &t, int l, int) {
        s = t;
        ind = l;
    }

    void update(const item &first, const item &second, int, int) {
        s = first.s + second.s;
        if (first.s) ind = first.ind;
        else ind = second.ind;
        if (s == 0) ind = -1;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};

string to_string(const item &) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}
ostream& operator << (ostream &o, const item &i) {
    return o << to_string(i);
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};
}

namespace segtree2 {
struct item {
    int sm = 0;
    int mx = 0;
    int ln = 1;

    template<typename T>
    void init(const T &t, int, int) {
        sm = mx = t;
        ln = 1;
    }

    void update(const item &first, const item &second, int, int) {
        sm = first.sm + second.sm;
        ln = first.ln + second.ln;
        mx = max(first.mx, first.sm + second.mx);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}
ostream& operator << (ostream &o, const item &i) {
    return o << to_string(i);
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(n - 1) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(tree[i].sm + t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> p(n - 1);
    cin >> p;
    p.insert(p.begin(), 0);
    --p;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i)
        g[p[i]].pb(i);

    vector<int> L(n), R(n);
    vector<int> ord;
    vector<int> pos(n);
    vector<int> lvl(n);
    int ind = 0;
    y_combinator([&](auto dfs, int v) -> void {
        ord.pb(v);
        L[v] = R[v] = pos[v] = ind++;
        for (int k : g[v]) {
            lvl[k] = lvl[v] + 1;
            dfs(k);
            L[v] = min(L[v], L[k]);
            R[v] = max(R[v], R[k]);
        }
    })(0);

    show(lvl);

    vector<int> val(n, 0);
    segtree1::segtree tree1(n);

    vector<segtree2::segtree> trees;
    vector<int> tree_ind(n, -1);
    vector<int> tree_pos(n, -1);
    vector<vector<int>> tree_verts;

    {
        vector<int> sz(n);
        y_combinator([&](auto dfs, int v) -> void {
            sz[v] = 1;
            for (int k : g[v]) {
                dfs(k);
                sz[v] += sz[k];
            }
        })(0);

        y_combinator([&](auto dfs, int v, int tree = -1) -> void {
            show(v, tree);
            if (tree == -1) {
                tree = tree_verts.size();
                tree_verts.eb();
            }
            tree_ind[v] = tree;
            tree_pos[v] = tree_verts[tree].size();
            tree_verts[tree].pb(v);

            for (int k : g[v]) {
                dfs(k, sz[k] * 2 >= sz[v] ? tree : -1);
            }
        })(0);

        for (int i = 0; i < tree_verts.size(); ++i)
            trees.emplace_back(tree_verts[i].size());

        for (int i = 0; i < tree_verts.size(); ++i) {
            reverse(tree_verts[i].begin(), tree_verts[i].end());
            for (int j = 0; j < tree_verts[i].size(); ++j) {
                tree_pos[tree_verts[i][j]] = j;
            }
        }
    }

    auto ch_val = [&](int v, int k) {
        trees[tree_ind[v]].set(tree_pos[v], k);
    };

    for (int i = 0; i < n; ++i)
        ch_val(i, -1);

    show(tree_verts);
    show(tree_ind);
    show(tree_pos);

    auto get_balance = [&](int v) {
        int v0 = v;
        {
            int ans = -1e9;
            int b = 0;
            while (v != -1) {
                int root = tree_verts[tree_ind[v]].back();
                auto it = trees[tree_ind[v]].ask(tree_pos[v], tree_pos[root]);
                show(v, root, b, it.sm, it.mx, it.ln);
                it.mx += lvl[v] + 1;
                ans = max(ans, it.mx + b);
                b += it.sm + it.ln;
                v = p[root];
            }
            show(v0, ans);
            return ans - lvl[v0];
        }
        {
            int ans = val[v] + lvl[v];
            int b = val[v];
            while (true) {
                v = p[v];
                if (v == -1) break;
                b += val[v];
                ans = max(ans, b + lvl[v]);
            }
            return ans - lvl[v0];
        }
    };

    while (q--) {
        shows;
        int tp;
        cin >> tp;
        int v;
        cin >> v;
        --v;
        debug {
            for (auto t : trees) {
                for (int i = 0; i < t.n; ++i)
                    cerr << t.ask(i, i).sm << ' ';
                cerr << endl;
            }
        }
        if (tp == 1) {
            ++val[v];
            ch_val(v, 1);
            tree1.set(pos[v], 1);
        } else if (tp == 2) {
            while (true) {
                auto it = tree1.ask(L[v], R[v]);
                show(it.s, it.ind);
                if (it.s == 0) break;
                tree1.set(it.ind, 0);

                ch_val(ord[it.ind], -val[ord[it.ind]]);
                val[ord[it.ind]] = 0;
            }
            tree1.set(pos[v], 1);
            int bal = -get_balance(v);
            ch_val(v, bal);
            val[v] += bal;
        } else if (tp == 3) {
            cout << (get_balance(v) <= 0 ? "white" : "black") << '\n';
        }
    }

    return 0;
}