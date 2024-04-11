/*
    author:  Maksim1744
    created: 30.09.2020 20:09:31
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

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
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

const int N = 1505;

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<int> e;
    vector<bitset<N>> bs;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
        e.assign(n, 0);
        bs.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            bs[i][i] = 1;
        }
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) {
            e[u]++;
            return false;
        }
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        bs[v] |= bs[u];
        e[v] += e[u] + 1;
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    Modular<P>& operator += (const Modular<P>& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular<P>  operator +  (const Modular<P>& m) const { Modular<P> r = *this; return r += m; }

    Modular<P>& operator -= (const Modular<P>& m)       { value -= m.value; if (value <  0) value += P; return *this; }
    Modular<P>  operator -  (const Modular<P>& m) const { Modular<P> r = *this; return r -= m; }
    Modular<P>  operator -                     () const { return Modular<P>(-value); }

    Modular<P>& operator *= (const Modular<P> &m)       { value = value * 1ll * m.value % P; return *this; }
    Modular<P>  operator *  (const Modular<P>& m) const { Modular<P> r = *this; return r *= m; }

    Modular<P>& operator /= (const Modular<P> &m)       { return *this *= m.inv(); }
    Modular<P>  operator /  (const Modular<P>& m) const { Modular<P> r = *this; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; r += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; r -= 1; return r; }

    bool        operator == (const Modular<P>& m) const { return value == m.value; }
    bool        operator != (const Modular<P>& m) const { return value != m.value; }

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

// using Mint = Modular<1000000007>;
using Mint = Modular<998244353>;
// using Mint = long double;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    cin >> a;

    map<int, vector<pair<int, int>>> es;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            es[a[i][j]].eb(i, j);
        }
    }
    DSU d(n);
    int idd = 0;
    vector<pair<pair<int, int>, bitset<N>>> good;
    for (int i = 0; i < n; ++i) {
        good.eb(mp(1, idd++), d.bs[i]);
    }
    show(es);
    for (auto [x, e] : es) {
        vector<int> check;
        for (auto [u, v] : e) {
            d.un(u, v);
            check.pb(d.par(u));
        }
        sort(check.begin(), check.end());
        check.erase(unique(check.begin(), check.end()), check.end());
        for (auto u : check) {
            if (d.e[u] == d.rk[u] * (d.rk[u] - 1) / 2) {
                good.eb(mp(d.bs[u].count(), idd), d.bs[u]);
                ++idd;
            }
        }
    }
    vector<vector<int>> g(good.size());
    sort(good.begin(), good.end(), [&](const pair<pair<int, int>, bitset<N>>& a, const pair<pair<int, int>, bitset<N>>& b) {
        return a.first > b.first;
    });
    int last = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < good.size(); ++j) {
            if (good[j].second[i]) {
                if (last != -1) {
                    g[last].pb(j);
                }
                last = j;
            }
        }
    }

    for (int i = 0; i < g.size(); ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }

    // show(good);

    // show(g);
    // printTree(g);

    vector<Mint> next(n + 1, 0);
    vector<vector<Mint>> dp(good.size(), vector<Mint>(n + 1, 0));
    vector<bool> u(good.size(), false);
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        dp[v][0] = 1;
        int ts = 0;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
                // show(dp[v], dp[k]);
                int ks = good[k].first.first;
                for (int i = 0; i < ts + ks + 1; ++i) {
                    next[i] = 0;
                }
                for (int s1 = 0; s1 <= ts; ++s1) {
                    for (int s2 = 0; s2 <= ks; ++s2) {
                        next[s1 + s2] += dp[v][s1] * dp[k][s2];
                    }
                }
                ts += ks;
                for (int i = 0; i <= ts; ++i)
                    dp[v][i] = next[i];
                // show(next)
                // swap(dp[v], next);
            }
        }
        dp[v][0] = 0;
        dp[v][1] += 1;
    };
    dfs(0);
    // for (int i = 0; i < dp.size(); ++i) {
    //     show(i, dp[i]);
    // }
    for (int i = 1; i <= n; ++i)
        cout << dp[0][i] << ' ';
    cout << '\n';


    return 0;
}