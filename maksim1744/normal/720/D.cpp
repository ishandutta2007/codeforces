/*
    author:  Maksim1744
    created: 09.05.2021 01:55:22
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

namespace mint_ns {
template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    friend Modular<P>& operator += (      Modular<P> &n, const Modular<P>& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend Modular<P>  operator +  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r += m; }

    friend Modular<P>& operator -= (      Modular<P> &n, const Modular<P>& m) { n.value -= m.value; if (n.value < 0)  n.value += P; return n; }
    friend Modular<P>  operator -  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r -= m; }
    friend Modular<P>  operator -  (const Modular<P> &n)                      { return Modular<P>(-n.value); }

    friend Modular<P>& operator *= (      Modular<P> &n, const Modular<P>& m) { n.value = n.value * 1ll * m.value % P; return n; }
    friend Modular<P>  operator *  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r *= m; }

    friend Modular<P>& operator /= (      Modular<P> &n, const Modular<P>& m) { return n *= m.inv(); }
    friend Modular<P>  operator /  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; *this -= 1; return r; }

    friend bool operator == (const Modular<P> &n, const Modular<P>& m) { return n.value == m.value; }
    friend bool operator != (const Modular<P> &n, const Modular<P>& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    constexpr static value_type mod()      { return     P; }

    value_type norm(ll k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    Modular<P> inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return Modular<P>(x);
    }
};
template<auto P> Modular<P> pow(Modular<P> m, ll p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> ostream& operator << (ostream& o, const Modular<P> &m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> &m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
// using Mint = long double;

vector<Mint> f, fi;
void init_C(int n) {
    f.assign(n, 1); fi.assign(n, 1);
    for (int i = 2; i < n; ++i) f[i] = f[i - 1] * i;
    fi.back() = Mint(1) / f.back();
    for (int i = n - 2; i >= 0; --i) fi[i] = fi[i + 1] * (i + 1);
}
Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    else return f[n] * fi[k] * fi[n - k];
}
}
using namespace mint_ns;

struct mod_lr {
    int l, r;
};

struct mod_val {
    Mint v;
};

namespace segtree1 {
struct item {
    int l = -1, r = -1;
    Mint val = 0;
    mod_lr modlr;
    bool is_mod_lr = false;
    Mint mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
    }

    void update(const item &first, const item &second, int l, int r) {
        val = first.val;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    void modify(const mod_lr &m, int, int) {
        modlr = m;
        l = m.l;
        r = m.r;
        is_mod_lr = true;
        // apply here, save for children
    }

    void modify(const mod_val &m, int, int) {
        mod += m.v;
        val += m.v;
        // apply here, save for children
    }

    void push(item &first, item &second, int l, int r) {
        if (is_mod_lr) {
            int m = (l + r) / 2;
            first.modify(modlr, l, m);
            second.modify(modlr, m + 1, r);
            is_mod_lr = false;
            // reset modifier
        }
        int m = (l + r) / 2;
        first.modify({mod}, l, m);
        second.modify({mod}, m + 1, r);
        mod = 0;
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
}

namespace segtree2 {
struct item {
    int sm = 0;
    int mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
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
        mod += m;
        sm += m * (r - l + 1);
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

    int first_zero(int ind, int i, int l, int r) {
        if (l != r) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
        }
        if (tree[i].sm == r - l + 1) return n;
        if (l == r) return l;
        int m = (l + r) / 2;
        if (ind > m)
            return first_zero(ind, i * 2 + 2, m + 1, r);
        int res = first_zero(ind, i * 2 + 1, l, m);
        if (res == n) return first_zero(m + 1, i * 2 + 2, m + 1, r);
        else return res;
    }

    int first_zero(int ind) {
        return first_zero(ind, 0, 0, n - 1);
    }
};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> ad(n), del(n);

    ofstream draw("draw");
    draw << "size (" << n << "," << m << ")\n";
    draw << "rect c=(" << (double)(n)/2 << "," << (double)(m)/2 << ") s=(" << n << "," << m << ") f=0 col=(255,255,255)\n";

    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        ad[x1].eb(y1, y2);
        del[x2].eb(y1, y2);
        draw << "rect c=(" << (double)(x1+x2+1)/2 << "," << (double)(y1+y2+1)/2 << ") s=(" << (x2-x1+1)-0.2 << "," << (y2-y1+1)-0.2 << ") f=1 col=(255,255,255,120)\n";
    }
    draw.flush();

    set<pair<int, int>> s;
    show(ad);
    show(del);
    segtree1::segtree tree1(m);
    segtree2::segtree tree2(m);

    auto ad_seg = [&](int l, int r, Mint v) {
        show(l, r);
        assert(tree2.ask(l, r).sm == 0);
        tree2.modify(l, r, 1);
        tree1.modify(l, r, mod_lr{l, r});
        tree1.modify(l, r, mod_val{v});
    };

    auto del_seg = [&](int l, int r, Mint v) {
        assert(tree2.ask(l, r).sm == r - l + 1);
        tree2.modify(l, r, -1);
        tree1.modify(l, r, mod_lr{-1, -1});
        tree1.modify(l, r, mod_val{-v});
    };

    auto get_val = [&](int ind) {
        return tree1.ask(ind, ind).val;
    };
    sort(ad[0].begin(), ad[0].end());

    for (int i = 0; i + 1 < ad[0].size(); ++i) {
        if (ad[0][i].second + 1 < ad[0][i + 1].first) {
            s.emplace(ad[0][i].second + 1, ad[0][i + 1].first - 1);
            ad_seg(ad[0][i].second + 1, ad[0][i + 1].first - 1, 0);
        }
    }
    if (ad[0].empty()) {
        s.emplace(0, m - 1);
        ad_seg(0, m - 1, 1);
    } else {
        s.emplace(0, ad[0][0].first - 1);
        ad_seg(0, ad[0][0].first - 1, 1);
        if (ad[0].back().second != m - 1) {
            s.emplace(ad[0].back().second + 1, m - 1);
            ad_seg(ad[0].back().second + 1, m - 1, 0);
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        shows;
        show(i);
        show(s);
        show(ad[i + 1]);
        show(del[i]);
        sort(ad[i + 1].begin(), ad[i + 1].end());
        debug {
            for (int i = 0; i < m; ++i) {
                auto it = tree1.ask(i, i);
                cerr << "(" << it.l << ", " << it.r << ", " << it.val << ") ";
            }
            cerr << endl;
            for (int i = 0; i < m; ++i) {
                auto it = tree2.ask(i, i);
                cerr << it.sm << " ";
            }
            cerr << endl;
        }
        for (auto [l, r] : ad[i + 1]) {
            auto it = s.lower_bound(mp(l, -1));
            while (it != s.end() && it->second <= r) {
                auto it1 = next(it);
                del_seg(it->first, it->second, get_val(it->first));
                s.erase(it);
                it = it1;
            }
            if (it != s.end() && it->first <= r) {
                auto p = *it;
                Mint val = get_val(it->first);
                del_seg(it->first, it->second, val);
                s.erase(it);
                s.emplace(r + 1, p.second);
                ad_seg(r + 1, p.second, val);
            }
            it = s.lower_bound(mp(l, -1));
            if (it != s.begin()) {
                --it;
                if (it->second >= l) {
                    if (it->second <= r) {
                        auto p = *it;
                        Mint val = get_val(it->first);
                        del_seg(it->first, it->second, val);
                        s.erase(it);
                        s.emplace(p.first, l - 1);
                        ad_seg(p.first, l - 1, val);
                    } else {
                        auto p = *it;
                        Mint val = get_val(it->first);
                        del_seg(it->first, it->second, val);
                        s.erase(it);
                        s.emplace(p.first, l - 1);
                        s.emplace(r + 1, p.second);
                        ad_seg(p.first, l - 1, val);
                        ad_seg(r + 1, p.second, val);
                    }
                }
            }
        }
        show(s);
        debug {
            for (int i = 0; i < m; ++i) {
                auto it = tree1.ask(i, i);
                cerr << "(" << it.l << ", " << it.r << ", " << it.val << ") ";
            }
            cerr << endl;
            for (int i = 0; i < m; ++i) {
                auto it = tree2.ask(i, i);
                cerr << it.sm << " ";
            }
            cerr << endl;
        }
        sort(del[i].begin(), del[i].end());
        for (auto [l, r] : del[i]) {
            int iind = lowb(ad[i + 1], mp(l, -1));
            if (iind != 0 && ad[i + 1][iind - 1].second >= l) l = ad[i + 1][iind - 1].second + 1;
            int r0 = r;
            while (l <= r0) {
                show(l, r, iind);
                int rr = r0;
                if (iind != ad[i + 1].size() && ad[i + 1][iind].first <= r0) rr = ad[i + 1][iind].first - 1;
                r = rr;
                show(l, r, iind);
                if (l <= r) {
                    auto it = s.lower_bound(mp(l, -1));
                    assert(it == s.end() || it->first > r);
                    assert(it == s.begin() || prev(it)->second < l);
                    if (it != s.begin()) {
                        --it;
                        if (it->second == l - 1) {
                            auto p = *it;
                            Mint val = get_val(it->first);
                            del_seg(it->first, it->second, val);
                            s.erase(it);
                            s.emplace(p.first, r);
                            ad_seg(p.first, r, val);
                            int ind = tree2.first_zero(r + 1);
                            show(l, r, ind);
                            if (ind != r + 1) {
                                tree1.modify(r + 1, ind - 1, mod_val{val});
                            }
                        }
                    }
                    int ind = tree2.first_zero(l);
                    if (ind <= r) {
                        auto it = s.lower_bound(mp(ind, -1));
                        int R = r;
                        if (it != s.end() && it->first <= r)
                            R = it->first - 1;
                        ad_seg(ind, R, 0);
                        s.emplace(ind, R);
                    }
                }
                if (iind == ad[i + 1].size()) break;
                l = ad[i + 1][iind].second + 1;
                ++iind;
            }
        }
    }
    Mint ans = 0;
    for (auto [l, r] : s) {
        if (r == m - 1) ans = get_val(r);
    }
    cout << ans << '\n';

    return 0;
}