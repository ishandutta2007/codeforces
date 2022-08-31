/*
    author:  Maksim1744
    created: 13.06.2021 19:33:23
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

vector<int> scc(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> topsort; topsort.reserve(n);
    vector<bool> u(n, false);
    function<void(int)> scc_dfs1 = [&](int v) {
        u[v] = true;
        for (auto k : g[v])
            if (!u[k])
                scc_dfs1(k);
        topsort.push_back(v);
    };
    for (int i = 0; i < n; ++i)
        if (!u[i])
            scc_dfs1(i);
    vector<vector<int>> gi(n);
    for (int i = 0; i < n; ++i)
        for (auto j : g[i])
            gi[j].push_back(i);
    int color = 0;
    vector<int> comp(n, -1);
    reverse(topsort.begin(), topsort.end());
    function<void(int, int)> scc_dfs2 = [&](int v, int color) {
        comp[v] = color;
        for (auto k : gi[v])
            if (comp[k] == -1)
                scc_dfs2(k, color);
    };
    for (auto v : topsort)
        if (comp[v] == -1)
            scc_dfs2(v, color++);
    return comp;
}

struct item {
    int mn = 1e9;

    template<typename T>
    void init(const T &t, int l, int r) {
        mn = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        mn = min(first.mn, second.mn);
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
        tree[i].init(min(tree[i].mn, t), l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    vector<vector<int>> ind(n, vector<int>(m, -1));
    int last = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '#')
                ind[i][j] = last++;
        }
    }
    vector<int> a(m);
    cin >> a;
    if (maxe(a) == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> up(n, vector<int>(m));
    {
        vector<vector<int>> ind(n, vector<int>(m, -1));
        int last = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '#')
                    ind[i][j] = last++;
            }
        }
        vector<vector<int>> g(last);

        for (int j = 0; j < m; ++j) {
            int il = -1, im = -1, ir = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (j != 0 && v[i][j - 1] == '#')
                    il = i;
                if (j != m - 1 && v[i][j + 1] == '#')
                    ir = i;

                if (v[i][j] == '#') {
                    if (il != -1)
                        g[ind[i][j]].pb(ind[il][j - 1]);
                    if (ir != -1)
                        g[ind[i][j]].pb(ind[ir][j + 1]);
                    if (im != -1)
                        g[ind[i][j]].pb(ind[im][j]);
                    if (i != 0 && v[i - 1][j] == '#')
                        g[ind[i][j]].pb(ind[i - 1][j]);
                }

                if (v[i][j] == '#')
                    im = i;
            }
        }
        auto col = scc(g);
        for (int j = 0; j < m; ++j) {
            map<int, int> last;
            for (int i = 0; i < n; ++i) {
                if (v[i][j] != '#') continue;
                if (!last.count(col[ind[i][j]])) {
                    last[col[ind[i][j]]] = i;
                }
                up[i][j] = last[col[ind[i][j]]];
            }
        }
    }
    vector<int> ah(m);
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        int ind = n;
        while (cnt != a[i]) {
            ind--;
            cnt += (v[ind][i] == '#');
        }
        ah[i] = ind;
    }

    vector<vector<int>> left(n, vector<int>(m, m));
    {
        for (int j = 0; j < m; ++j) {
            int il = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (j != 0 && v[i][j - 1] == '#')
                    il = i;
                if (il != -1)
                    il = up[il][j - 1];

                if (v[i][j] == '#') {
                    if (up[i][j] > ah[j]) {
                        left[i][j] = m;
                    } else {
                        left[i][j] = j;
                        if (il != -1) {
                            if (il <= ah[j - 1]) {
                                left[i][j] = left[il][j - 1];
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> right(n, vector<int>(m, m));
    {
        for (int i = 0; i < n; ++i) {
            reverse(up[i].begin(), up[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        reverse(a.begin(), a.end());
        reverse(ah.begin(), ah.end());

        for (int j = 0; j < m; ++j) {
            int il = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (j != 0 && v[i][j - 1] == '#')
                    il = i;
                if (il != -1)
                    il = up[il][j - 1];

                if (v[i][j] == '#') {
                    if (up[i][j] > ah[j]) {
                        right[i][j] = m;
                    } else {
                        right[i][j] = j;
                        if (il != -1) {
                            if (il <= ah[j - 1]) {
                                right[i][j] = right[il][j - 1];
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            reverse(up[i].begin(), up[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        reverse(a.begin(), a.end());
        reverse(ah.begin(), ah.end());

        for (int i = 0; i < n; ++i) {
            reverse(right[i].begin(), right[i].end());
            for (auto &j : right[i])
                j = m - 1 - j;
        }
    }

    show(v);
    show(ah);
    show(up);
    show(left);
    show(right);

    vector<pair<int, int>> segs;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (v[i][j] == '#') {
                int l = left[i][j];
                int r = right[i][j];
                assert(l >= 0);
                assert(r < m);
                assert(l <= r);
                segs.eb(l, r);
                break;
            }
        }
    }

    show(segs);
    show(a);

    segtree tree(m + 1);
    tree.set(0, 0);
    const int inf = 1e9;
    vector<int> ls(m, inf);
    for (auto [l, r] : segs) {
        umin(ls[r], l);
    }

    for (int i = 0; i < m; ++i) {
        tree.set(i + 1, tree.ask(i, i).mn + (a[i] != 0));
        if (ls[i] != inf)
            tree.set(i + 1, tree.ask(ls[i], i).mn + 1);
    }
    cout << tree.ask(m, m).mn << '\n';

    return 0;
}