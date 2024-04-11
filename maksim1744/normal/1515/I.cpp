/*
    author:  Maksim1744
    created: 24.05.2021 22:37:32
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

struct item {
    ll smalsw = 0;
    ll smalsv = 0;
    ll prefix_min = 2e18;

    template<typename T>
    void init(const T &t, int l, int r) {
        auto [w, val, cnt, b] = t;
        smalsv = smalsw = 0;
        prefix_min = 2e18;
        if (b == -1 || w < (1ll << b) / 2) {
            smalsv = val * cnt;
            smalsw = w * cnt;
        } else {
            if (cnt) {
                prefix_min = w;
            }
        }
    }

    void update(const item &first, const item &second, int l, int r) {
        smalsw = first.smalsw + second.smalsw;
        smalsv = first.smalsv + second.smalsv;
        prefix_min = min(first.prefix_min, first.smalsw + second.prefix_min);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[smalsw=" << i.smalsw << ", smalsv=" << i.smalsv << ", prefix_min=" << i.prefix_min << "]";
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

    pair<int, ll> ask_smallsw(int l, ll c, int i, int vl, int vr) {
        // show(l, c, vl, vr);
        if (l == vl) {
            if (tree[i].smalsw <= c)
                return {vr + 1, tree[i].smalsw};
        }
        if (vl == vr) {
            return {vr, tree[i].smalsw};
        }
        int m = (vl + vr) / 2;
        if (l >= m + 1)
            return ask_smallsw(l, c, i * 2 + 2, m + 1, vr);
        auto res = ask_smallsw(l, c, i * 2 + 1, vl, m);
        if (res.second > c) return res;
        c -= res.second;
        auto res2 = ask_smallsw(m + 1, c, i * 2 + 2, m + 1, vr);
        res2.second += res.second;
        return res2;
    }

    int ask_smallsw(int l, ll c) {
        if (l >= n) return n - 1;
        return ask_smallsw(l, c, 0, 0, n - 1).first - 1;
    }

    pair<int, ll> ask_prefix_min(int l, ll c, int i, int vl, int vr) {
        if (l == vl) {
            if (tree[i].prefix_min > c)
                return {-1, tree[i].smalsw};
        }
        if (vl == vr) {
            return {vl, tree[i].smalsw};
        }
        int m = (vl + vr) / 2;
        if (l >= m + 1) return ask_prefix_min(l, c, i * 2 + 2, m + 1, vr);
        auto res = ask_prefix_min(l, c, i * 2 + 1, vl, m);
        if (res.first != -1) return res;
        auto res2 = ask_prefix_min(m + 1, c - res.second, i * 2 + 2, m + 1, vr);
        res2.second += res.second;
        return res2;
    }

    int ask_prefix_min(int l, ll c) {
        if (l >= n) assert(false);
        return ask_prefix_min(l, c, 0, 0, n - 1).first;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<ll> cnt(n);
    vector<int> perm(n);
    vector<int> val(n);
    vector<int> w(n);
    {
        struct item {
            int a, w, v;
            int i;
        };
        vector<item> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].a >> v[i].w >> v[i].v;
            v[i].i = i;
        }
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
            if (a.v != b.v) return a.v > b.v;
            return a.w < b.w;
        });
        for (int i = 0; i < n; ++i) {
            perm[v[i].i] = i;
            cnt[i] = v[i].a;
            w[i] = v[i].w;
            val[i] = v[i].v;
        }
    }

    show(w);
    show(val);
    show(cnt);

    const int B = 21;
    vector<segtree> trees(B, n);
    segtree tree0(n);

    auto set_val = [&](int i) {
        for (int b = 0; b < B; ++b) {
            if (w[i] <= (1ll << b)) {
                trees[b].set(i, make_tuple(w[i], val[i], cnt[i], b));
            }
        }
        tree0.set(i, make_tuple(w[i], val[i], cnt[i], -1));
    };
    for (int i = 0; i < n; ++i) {
        set_val(i);
    }
    debug {
        for (int i = 0; i < B; ++i) {
            for (int j = 0; j < n; ++j) {
                cerr << trees[i].ask(j, j) << ' ';
            }
            cerr << endl;
        }
        for (int j = 0; j < n; ++j) {
            cerr << tree0.ask(j, j) << ' ';
        }
        cerr << endl;
    }

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int k, d;
            cin >> k >> d;
            --d;
            d = perm[d];
            cnt[d] += k;
            set_val(d);
        } else if (tp == 2) {
            int k, d;
            cin >> k >> d;
            --d;
            d = perm[d];
            cnt[d] -= k;
            set_val(d);
        } else if (tp == 3) {
            ll c;
            cin >> c;
            ll ans = 0;
            int ind = 0;

            int ir = tree0.ask_smallsw(ind, c);
            auto it = tree0.ask(ind, ir);
            ind = ir + 1;
            ans += it.smalsv;
            c -= it.smalsw;

            if (ind < n) {
                ll can = c / w[ind];
                ans += can * val[ind];
                c -= can * w[ind];
                ++ind;
            }

            show(ans, c, ind);

            for (int b = B - 1; b >= 0; --b) {
                int r = n;
                show(trees[b].ask(ind, n - 1).prefix_min);
                if (trees[b].ask(ind, n - 1).prefix_min <= c) {
                    r = trees[b].ask_prefix_min(ind, c);
                } else {
                    r = n;
                }
                int ir = trees[b].ask_smallsw(ind, c);
                ir = min(ir, r - 1);
                auto it = trees[b].ask(ind, ir);
                c -= it.smalsw;
                ans += it.smalsv;
                show(r, ind);
                show(ind, ans, c);
                ind = ir + 1;
                if (r == n && ind < n) {
                    ll can = min(cnt[ind], c / w[ind]);
                    c -= can * w[ind];
                    ans += can * val[ind];
                    ++ind;
                }
                show(ind, ans, c);
                if (r != n) {
                    c -= w[r];
                    ans += val[r];
                    ind = r + 1;
                }
                show(ind, ans, c);
            }
            cout << ans << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}