/*
    author:  Maksim1744
    created: 09.06.2021 02:49:00
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

// using Mint = Modular<1000000007>;
using Mint = Modular<998244353>;
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

    vector<vector<Mint>> dp_covered(n);
    vector<vector<Mint>> dp_uncovered(n);
    auto calc = [&](int r) -> Mint {
        dp_covered.assign(n, {});
        dp_uncovered.assign(n, {});
        y_combinator([&](auto dfs, int v, int p = -1) -> void {
            bool leaf = true;
            for (int k : g[v]) {
                if (k == p) continue;
                leaf = false;
                dfs(k, v);
                if (dp_covered[v].empty()) {
                    dp_covered[v] = dp_covered[k];
                    dp_uncovered[v] = dp_uncovered[k];
                    continue;
                }

                vector<Mint> new_covered(dp_covered[v].size() + dp_covered[k].size() - 1, 0);
                vector<Mint> new_uncovered(dp_uncovered[v].size() + dp_uncovered[k].size() - 1, 0);

                int vnot0 = 0;
                while (vnot0 < dp_covered[v].size() && dp_covered[v][vnot0] == 0) ++vnot0;
                int knot0 = 0;
                while (knot0 < dp_covered[k].size() && dp_covered[k][knot0] == 0) ++knot0;

                for (int i = vnot0; i < dp_covered[v].size(); ++i)
                    for (int j = knot0; j < dp_covered[k].size(); ++j)
                        new_covered[max(i, j)] += dp_covered[v][i] * dp_covered[k][j];

                for (int i = 0; i < dp_uncovered[v].size(); ++i)
                    for (int j = 0; j < dp_uncovered[k].size(); ++j)
                        new_uncovered[max(i, j)] += dp_uncovered[v][i] * dp_uncovered[k][j];

                for (int i = vnot0; i < dp_covered[v].size(); ++i) {
                    for (int j = 0; j < dp_uncovered[k].size(); ++j) {
                        if (i - 2 >= j)
                            new_covered[i] += dp_covered[v][i] * dp_uncovered[k][j];
                        else
                            new_uncovered[j] += dp_covered[v][i] * dp_uncovered[k][j];
                    }
                }
                for (int i = knot0; i < dp_covered[k].size(); ++i) {
                    for (int j = 0; j < dp_uncovered[v].size(); ++j) {
                        if (i - 2 >= j)
                            new_covered[i] += dp_covered[k][i] * dp_uncovered[v][j];
                        else
                            new_uncovered[j] += dp_covered[k][i] * dp_uncovered[v][j];
                    }
                }

                swap(dp_covered[v], new_covered);
                swap(dp_uncovered[v], new_uncovered);
            }

            if (leaf) {
                dp_covered[v].resize(r + 1);
                dp_covered[v][r] = 1;
                dp_uncovered[v] = {1};
                return;
            }

            vector<Mint> new_covered(dp_covered[v].size() + 1, 0);
            if (new_covered.size() <= r)
                new_covered.resize(r + 1, 0);
            vector<Mint> new_uncovered(dp_uncovered[v].size() + 1, 0);

            // take v
            {
                for (int i = 0; i <= r - 1 && i < dp_uncovered[v].size(); ++i)
                    new_covered[r] += dp_uncovered[v][i];
                for (int i = 0; i < dp_covered[v].size(); ++i)
                    new_covered[r] += dp_covered[v][i];
            }
            // don't take v
            {
                for (int i = 0; i <= r - 1 && i < dp_uncovered[v].size(); ++i)
                    new_uncovered[i + 1] += dp_uncovered[v][i];

                for (int i = 1; i < dp_covered[v].size(); ++i)
                    new_covered[i - 1] += dp_covered[v][i];
                if (!dp_covered[v].empty())
                    new_uncovered[0] += dp_covered[v][0];
            }

            swap(dp_covered[v], new_covered);
            swap(dp_uncovered[v], new_uncovered);
        })(0);
        return accumulate(dp_covered[0].begin(), dp_covered[0].end(), Mint(0));
    };

    vector<Mint> res(n + 2);
    for (int r = 0; r <= n + 1; ++r) {
        res[r] = calc(r);
        if (r != 0 && res[r] == res[r - 1]) {
            for (int i = r + 1; i < res.size(); ++i)
                res[i] = res[i - 1];
            break;
        }
    }

    Mint ans = 0;

    for (int i = 1; i + 1 < res.size(); ++i)
        ans += (res[i + 1] - res[i]) * i;

    ans--;
    ans += n;

    cout << ans / pow(Mint(2), n) << '\n';

    return 0;
}