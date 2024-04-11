/*
    author:  Maksim1744
    created: 03.01.2022 19:26:48
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
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

namespace mint_ns {
template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(long long k = 0) : value(norm(k)) {}

    friend Modular<P>& operator += (      Modular<P>& n, const Modular<P>& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend Modular<P>  operator +  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r += m; }

    friend Modular<P>& operator -= (      Modular<P>& n, const Modular<P>& m) { n.value -= m.value; if (n.value < 0)  n.value += P; return n; }
    friend Modular<P>  operator -  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r -= m; }
    friend Modular<P>  operator -  (const Modular<P>& n)                      { return Modular<P>(-n.value); }

    friend Modular<P>& operator *= (      Modular<P>& n, const Modular<P>& m) { n.value = n.value * 1ll * m.value % P; return n; }
    friend Modular<P>  operator *  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r *= m; }

    friend Modular<P>& operator /= (      Modular<P>& n, const Modular<P>& m) { return n *= m.inv(); }
    friend Modular<P>  operator /  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r /= m; }

    Modular<P>& operator ++ (   ) { return *this += 1; }
    Modular<P>& operator -- (   ) { return *this -= 1; }
    Modular<P>  operator ++ (int) { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator -- (int) { Modular<P> r = *this; *this -= 1; return r; }

    friend bool operator == (const Modular<P>& n, const Modular<P>& m) { return n.value == m.value; }
    friend bool operator != (const Modular<P>& n, const Modular<P>& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    constexpr static value_type mod()      { return     P; }

    value_type norm(long long k) {
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
template<auto P> Modular<P> pow(Modular<P> m, long long p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> ostream& operator << (ostream& o, const Modular<P>& m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P>& m) { long long k; i >> k; m.value = m.norm(k); return i; }
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

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;

    vector<pair<int, T>> mem;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
    }

    void add(int i, T k, bool save = true) {
        if (save)
            mem.eb(i, k);
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

    void undo() {
        auto [i, k] = mem.back();
        add(i, -k, false);
        mem.pop_back();
    }
};

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    {
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = {a[i], -i};
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i) {
            a[-b[i].second] = i;
        }
    }

    vector<int> sufmaxi;
    int curmax = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] > curmax) {
            curmax = a[i];
            sufmaxi.pb(i);
        }
    }

    vector<int> sufmax;
    for (int k : sufmaxi)
        sufmax.pb(a[k]);

    auto calc_inc = [&](vector<int> a) -> vector<Mint> {
        if (a.empty()) {
            return {};
        }
        vector<int> x = a;
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        for (int i = 0; i < a.size(); ++i) {
            a[i] = lowb(x, a[i]);
        }
        fenwick<Mint> tree(a.size());
        vector<Mint> ans;
        for (int k : a) {
            Mint cur = tree.ask(k - 1) + 1;
            ans.pb(cur);
            tree.add(k, cur);
        }
        return ans;
    };

    auto calc_incr = [&](const vector<int>& a) {
        auto b = a;
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); ++i) {
            b[i] = -b[i];
        }
        auto res = calc_inc(b);
        reverse(res.begin(), res.end());
        return res;
    };

    vector<Mint> incl = calc_inc(a);
    vector<Mint> incr = calc_incr(a);

    vector<int> imax(n, -1);
    for (int i = 0; i < sufmaxi.size(); ++i) {
        imax[sufmaxi[i]] = i;
    }

    vector<vector<int>> withmax(sufmaxi.size());
    for (int i = 0; i < n; ++i) {
        int ind = lowb(sufmax, a[i]);
        if (imax[i] != -1) continue;
        assert(ind != sufmax.size());
        withmax[ind].pb(i);
    }

    vector<Mint> badr(n, 0);

    fenwick<Mint> tree(n);
    for (int i = n - 1; i >= 0; --i) {
        Mint cur = tree.ask(a[i], n - 1) + 1;
        tree.add(a[i], cur);

        if (imax[i] != -1) {
            int ind = imax[i];
            int ops = 0;
            for (int j = (int)withmax[ind].size() - 1; j >= 0; --j) {
                int k = withmax[ind][j];
                Mint cur = tree.ask(a[k], n - 1);
                badr[k] = cur;
                tree.add(a[k], cur);
                ++ops;
            }
            for (int i = 0; i < ops; ++i) {
                tree.undo();
            }
        }
    }

    show(a);
    show(sufmaxi);
    show(incl);
    show(incr);
    show(badr);

    Mint ans = 0;
    for (int i = 0; i < n; ++i) {
        if (imax[i] != -1) continue;
        ans += incl[i] * (incr[i] - badr[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}