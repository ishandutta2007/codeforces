/*
    author:  Maksim1744
    created: 11.05.2021 22:21:11
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

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<pair<pair<int, int>, int>> ops;
    int n;
    int comps;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        comps = n;
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
    }

    int par(int v) {
        while (v != p[v])
            v = p[v];
        return v;
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        ops.eb(mp(v, u), p[u]);
        p[u] = v;
        rk[v] += rk[u];
        --comps;
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }

    int checkpoint() {
        return ops.size();
    }

    void undo(int c) {
        while (ops.size() > c) {
            auto [vu, pu] = ops.back();
            auto [v, u] = vu;
            ops.pop_back();
            ++comps;
            rk[v] -= rk[u];
            p[u] = pu;
        }
    }
};

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

struct item {
    int mn;
    int cnt = 1;
    int mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        mn = t;
        cnt = 1;
    }

    void update(const item &first, const item &second, int l, int r) {
        mn = min(first.mn, second.mn);
        cnt = 0;
        if (first.mn == mn) cnt += first.cnt;
        if (second.mn == mn) cnt += second.cnt;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        // apply here, save for children
        mn += m;
        mod += m;
    }

    void push(item &first, item &second, int l, int r) {
        int m = (l + r) / 2;
        first.modify(mod, l, m);
        second.modify(mod, m + 1, r);
        mod = 0;
        // reset modifier
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
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
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
            if (l != r) {
                tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
            }
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

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        if (l == vl && r == vr) {
            tree[i].modify(modifier, vl, vr);
            return;
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            modify(l, r, modifier, i * 2 + 1, vl, m);
        } else if (m < l) {
            modify(l, r, modifier, i * 2 + 2, m + 1, vr);
        } else {
            modify(l, m, modifier, i * 2 + 1, vl, m);
            modify(m + 1, r, modifier, i * 2 + 2, m + 1, vr);
        }
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
    }

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n, vector<int>(m));
    cin >> f;
    --f;
    vector<pair<int, int>> where(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            where[f[i][j]] = {i, j};
        }
    }

    vector<int> dp(n * m, -1);

    show(f);

    {
        DSU d((n + 1) * (m + 1));
        auto add_cell = [&](int c) {
            int x = where[c].first * 2;
            int y = where[c].second * 2;
            ++x;
            ++y;
            int a  = (x - 1) / 2 * (m + 1) + (y - 1) / 2;
            int b  = (x - 1) / 2 * (m + 1) + (y + 1) / 2;
            int cc = (x + 1) / 2 * (m + 1) + (y + 1) / 2;
            int dd = (x + 1) / 2 * (m + 1) + (y - 1) / 2;
            d.un(a, b);
            d.un(b, cc);
            d.un(cc, dd);
            d.un(dd, a);
        };

        for (int i = 0; i < n; ++i) {
            d.un(i * (m + 1), (i + 1) * (m + 1));
            d.un(i * (m + 1) + m, (i + 1) * (m + 1) + m);
        }
        for (int i = 0; i < m; ++i) {
            d.un(i, i + 1);
            d.un(n * (m + 1) + i, n * (m + 1) + i + 1);
        }

        auto calc = y_combinator([&](auto calc, int l, int r, int vl, int vr) -> void {
            if (l > r) return;
            int m = (l + r) / 2;
            int cp1 = d.checkpoint();
            for (int i = l; i < m; ++i)
                add_cell(i);
            int last = vr;
            int cp2 = d.checkpoint();
            while (d.comps != 1) {
                add_cell(last);
                --last;
            }
            dp[m] = last;
            d.undo(cp2);
            add_cell(m);
            calc(m + 1, r, dp[m], vr);
            d.undo(cp1);
            for (int i = vr; i > dp[m]; --i)
                add_cell(i);
            calc(l, m - 1, vl, dp[m]);
            d.undo(cp1);
        });
        calc(0, n * m - 1, 0, n * m - 1);
    }

    {
        const vector<pair<int, int>> D = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<int> ans(dp.size());
        segtree tree(dp.size());
        int edges = 0;
        for (int j = 0; j < dp.size(); ++j) {
            auto [x, y] = where[j];
            for (auto [dx, dy] : D) {
                if (x + dx >= 0 && y + dy >= 0 && x + dx < n && y + dy < m && f[x + dx][y + dy] < j)
                    ++edges;
            }
            tree.set(j, j + 1 - edges);
        }
        show(dp);
        for (int i = 0; i < dp.size(); ++i) {
            auto it = tree.ask(i, dp[i]);
            debug {
                for (int j = 0; j < dp.size(); ++j) {
                    cerr << tree.ask(j, j).mn << ' ';
                }
                cerr << endl;
            }
            show(it.mn, it.cnt);
            if (it.mn == 1)
                ans[i] = it.cnt;

            tree.modify(0, dp.size() - 1, -1);
            auto [x, y] = where[i];
            for (auto [dx, dy] : D) {
                if (x + dx >= 0 && y + dy >= 0 && x + dx < n && y + dy < m && f[x + dx][y + dy] > i) {
                    tree.modify(f[x + dx][y + dy], dp.size() - 1, 1);
                }
            }
        }
        cout << sum(ans) << '\n';
    }

    return 0;
}