/*
    author:  Maksim1744
    created: 08.04.2021 00:35:55
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int m;
    cin >> m;
    vector<vector<int>> t(m);
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        t[u].push_back(v);
        t[v].push_back(u);
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        for (int j : t[i]) {
            edges.eb(i, j);
        }
    }
    sort(edges.begin(), edges.end());
    vector<vector<int>> children(edges.size());
    for (int i = 0; i < edges.size(); ++i) {
        auto [k, v] = edges[i];
        for (int j : t[v]) {
            if (j != k) {
                children[i].pb(lowb(edges, mp(v, j)));
            }
        }
    }

    auto geth = [&](int k, int v) {
        vector<bool> u(t.size(), false);
        if (k != -1)
            u[k] = true;
        function<string(int, int)> dfs = [&](int v, int lvl) {
            u[v] = true;
            string tag = "<" + to_string(lvl) + ">";
            string res = tag;
            vector<string> ss;
            for (int k : t[v]) {
                if (!u[k]) {
                    ss.pb(dfs(k, lvl + 1));
                }
            }
            sort(ss.begin(), ss.end());
            for (auto s : ss)
                res += s + tag;
            return res;
        };
        auto res = dfs(v, 0);
        show(k, v, res);
        return res;
    };

    vector<vector<int>> finishes;
    vector<int> finishesv;
    for (int i = 0; i < m; ++i) {
        bool need = true;
        for (int j = 0; j < i; ++j) {
            if (geth(-1, i) == geth(-1, j)) {
                need = false;
                break;
            }
        }
        if (!need) continue;
        show(i);
        finishes.eb();
        finishesv.eb(i);
        for (int j : t[i])
            finishes.back().eb(lowb(edges, mp(i, j)));
    }

    show(children);
    show(finishes);
    show(edges);

    init_C(n + m + 20);

    auto get_coef = [&](int v, vector<int> ind) {
        map<string, int> cnt;
        show(v, ind);
        for (int k : ind)
            cnt[geth(v, edges[k].second)]++;
        Mint ans = 1;
        for (auto [a, b] : cnt)
            ans *= f[b];
        return ans;
    };

    vector<Mint> finish_coefs(finishes.size());
    for (int i = 0; i < finishes.size(); ++i) {
        finish_coefs[i] = get_coef(finishesv[i], finishes[i]);
    }
    show("done");
    vector<Mint> children_coefs(children.size());
    for (int i = 0; i < children.size(); ++i) {
        children_coefs[i] = get_coef(edges[i].first, children[i]);
    }

    vector<vector<Mint>> dp(n, vector<Mint>(edges.size(), 0));
    vector<bool> u(n, false);
    Mint ans = 0;
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        vector<int> ch;
        for (int k : g[v]) {
            if (!u[k]) {
                dfs(k);
                ch.pb(k);
            }
        }
        auto calcv = [&](const vector<int> &ind) {
            vector<Mint> dd(1 << ind.size(), 0);
            dd[0] = 1;
            for (int k : ch) {
                for (int i = (int)dd.size() - 1; i >= 0; --i) {
                    for (int j = 0; j < ind.size(); ++j) {
                        if ((i >> j) & 1) continue;
                        dd[i | (1 << j)] += dd[i] * dp[k][ind[j]];
                    }
                }
            }
            return dd.back();
        };
        for (int i = 0; i < finishes.size(); ++i) {
            ans += calcv(finishes[i]) / finish_coefs[i];
        }
        show(v, ans);
        for (int i = 0; i < edges.size(); ++i)
            dp[v][i] = calcv(children[i]) / children_coefs[i];
    };
    dfs(0);
    show(dp);
    cout << ans << '\n';

    return 0;
}