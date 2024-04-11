/*
    author:  Maksim1744
    created: 28.11.2021 18:49:49
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct item {
    pair<ll, ll> mod = {0, 0};
    ll sm = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        sm = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        sm = first.sm + second.sm;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        // apply here, save for children
        sm += (ll)m.first * (r - l + 1) * (r - l) / 2 + (ll)m.second * (r - l + 1) + ((ll)m.first * l) * (r - l + 1);
        mod.first += m.first;
        mod.second += m.second;
    }

    void push(item &first, item &second, int l, int r) {
        int m = (l + r) / 2;
        first.modify(mod, l, m);
        second.modify(mod, m + 1, r);
        // reset modifier
        mod = {0, 0};
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
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
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
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
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

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }
};

array<ll, 101> a, da;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<ll> b(m);
    cin >> b;

    for (int i = 0; i < n - 1; ++i)
        da[i] = a[i + 1] - a[i];

    segtree treeb(m);
    treeb.build(b);

    // fenwick<ll> treedb(m);
    // for (int i = 0; i < m - 1; ++i) {
    //     treedb.add(i, b[i + 1] - b[i] - (i == 0 ? 0 : (b[i] - b[i - 1])));
    // }
    vector<ll> db(m - 1);
    for (int i = 0; i < m - 1; ++i) {
        db[i] = b[i + 1] - b[i];
    }
    const int B = 300;
    vector<ll> block(m / B + 2, 0);

    while (q--) {
        int tp;
        ll k, d;
        cin >> tp >> k >> d;
        if (tp == 1) {
            for (int i = 0; i < k; ++i)
                a[n - k + i] += (i + 1) * d;
            for (int i = max(0ll, n - k - 1); i < n - 1; ++i)
                da[i] += d;
        } else {
            treeb.modify(m - k, m - 1, mp(d, d * (k - m + 1)));
            // treedb.add(max(0ll, m - k - 1), d);
            int is = max(0ll, m - k - 1);
            while (is < m - 1 && is % B != 0) {
                db[is] += d;
                ++is;
            }
            if (is != m - 1)
                for (int i = is / B; i < block.size(); ++i)
                    block[i] += d;
        }
        debug {
            show(db);
            show(block);
            for (int i = 0; i < m; ++i)
                cerr << treeb.ask(i, i).sm << " \n"[i + 1 == m];
            for (int i = 0; i < m - 1; ++i)
                cerr << db[i] + block[i / B] << " \n"[i + 1 == m - 1];
        }

        ll ans = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            int cur;
            if (i + 1 < n) {
                int L = prev - 1, R = m - 1;
                while (R - L > 1) {
                    int C = (L + R) / 2;
                    ll val = db[C] + block[C / B] - da[i];
                    if (val < 0)
                        L = C;
                    else
                        R = C;
                }
                cur = R;
            } else {
                cur = m - 1;
            }
            ans += a[i] * (cur - prev + 1);
            ans += treeb.ask(prev, cur).sm;
            prev = cur;
        }
        cout << ans << '\n';
    }

    return 0;
}