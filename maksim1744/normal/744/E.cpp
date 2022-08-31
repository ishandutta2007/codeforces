/*
    author:  Maksim1744
    created: 10.05.2021 02:02:43
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

const Mint p = 1234;

const int N = 1e5 + 20;
array<Mint, N> dp, dpi;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;

    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i)
        dp[i] = dp[i - 1] * p;
    dpi.back() = 1 / dp.back();
    for (int i = (int)dpi.size() - 2; i >= 0; --i)
        dpi[i] = dpi[i + 1] * p;

    vector<vector<Mint>> preh(n);
    for (int i = 0; i < n; ++i) {
        vector<Mint> h = {0};
        for (char c : v[i]) {
            h.pb((c - 'a' + 1) + h.back() * p);
        }
        swap(preh[i], h);
    }

    auto geth = [&](int i, int l, int r) {
        if (l > r) return Mint(0);
        Mint hr = preh[i][r + 1];
        Mint hl = preh[i][l];
        Mint res = hr - hl * dp[r - l + 1];
        // show(i, l, r, res);
        return res;
    };

    vector<vector<int>> inds1(n);
    vector<vector<int>> inds2(n);
    vector<vector<int>> g;

    auto check_sub = [&](int l, int r, bool reuse) {
        if (l > r) return true;
        if (!reuse || true) {
            g.clear();

            int last = 2;

            for (int i = l; i <= r; ++i) {
                inds1[i].clear();
                inds2[i].clear();
                inds1[i].pb(0);
                inds2[i].pb(1);
                for (int j = 1; j < v[i].size(); ++j) {
                    inds1[i].pb(last);
                    ++last;
                    inds2[i].pb(last);
                    ++last;
                }
            }
            g.resize(last);

            for (int i = l; i <= r; ++i) {
                for (int j = 0; j < v[i].size(); ++j) {
                    for (int k = l; k <= r; ++k) {
                        int ln = v[k].size();
                        int mn = min((int)v[i].size() - j, (int)v[k].size());
                        if (geth(i, j, j + mn - 1) == geth(k, 0, mn - 1)) {
                            if (j + ln < v[i].size()) {
                                g[inds1[i][j]].pb(inds1[i][j + ln]);
                                g[inds2[i][j]].pb(inds2[i][j + ln]);
                            } else if (j + ln == v[i].size()) {
                                g[inds1[i][j]].pb(0);
                                g[inds2[i][j]].pb(1);
                            } else {
                                g[inds1[i][j]].pb(inds2[k][(v[i].size() - j)]);
                                g[inds2[i][j]].pb(inds1[k][(v[i].size() - j)]);
                            }
                        }
                    }
                }
            }
        } else {
            int last = 2;

            for (int i = l; i < r; ++i)
                last += (v[i].size() - 1) * 2;

            {
                int i = r;
                inds1[i].clear();
                inds2[i].clear();
                inds1[i].pb(0);
                inds2[i].pb(1);
                for (int j = 1; j < v[i].size(); ++j) {
                    inds1[i].pb(last);
                    ++last;
                    inds2[i].pb(last);
                    ++last;
                }
            }

            g.resize(last);

            for (int i = l; i <= r; ++i) {
                for (int j = 0; j < v[i].size(); ++j) {
                    int L = l, R = r;
                    if (i != r) L = R = r;
                    for (int k = L; k <= R; ++k) {
                        int ln = v[k].size();
                        int mn = min((int)v[i].size() - j, (int)v[k].size());
                        if (geth(i, j, j + mn - 1) == geth(k, 0, mn - 1)) {
                            if (j + ln < v[i].size()) {
                                g[inds1[i][j]].pb(inds1[i][j + ln]);
                                g[inds2[i][j]].pb(inds2[i][j + ln]);
                            } else if (j + ln == v[i].size()) {
                                g[inds1[i][j]].pb(0);
                                g[inds2[i][j]].pb(1);
                            } else {
                                g[inds1[i][j]].pb(inds2[k][(v[i].size() - j)]);
                                g[inds2[i][j]].pb(inds1[k][(v[i].size() - j)]);
                            }
                        }
                    }
                }
            }
        }

        auto col = scc(g);
        vector<int> sz(maxe(col) + 1, 0);
        for (int k : col)
            sz[k]++;

        for (int i = l; i <= r; ++i) {
            for (int j = 1; j < v[i].size(); ++j) {
                if (sz[col[inds1[i][j]]] != 1)
                    return false;
                if (sz[col[inds2[i][j]]] != 1)
                    return false;
            }
        }

        return true;
    };

    int ans = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        bool reuse = false;
        while (r < n && check_sub(l, r, reuse && l != r)) {
            ++r;
            reuse = true;
        }
        ans += r - l;
    }

    cout << ans << '\n';

    return 0;
}