/*
    author:  Maksim1744
    created: 30.09.2021 13:34:34
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

namespace var_mint_ns {
struct VarModular {
    using value_type = int;
  private:
    static value_type P;
  public:
    value_type value;

    VarModular(long long k = 0) : value(norm(k)) {}

    friend VarModular& operator += (      VarModular& n, const VarModular& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend VarModular  operator +  (const VarModular& n, const VarModular& m) { VarModular r = n; return r += m; }

    friend VarModular& operator -= (      VarModular& n, const VarModular& m) { n.value -= m.value; if (n.value < 0)    n.value += P; return n; }
    friend VarModular  operator -  (const VarModular& n, const VarModular& m) { VarModular r = n; return r -= m; }
    friend VarModular  operator -  (const VarModular& n)                      { return VarModular(-n.value); }

    friend VarModular& operator *= (      VarModular& n, const VarModular& m) { n.value = reduce(n.value * 1ll * m.value); return n; }
    friend VarModular  operator *  (const VarModular& n, const VarModular& m) { VarModular r = n; return r *= m; }

    friend VarModular& operator /= (      VarModular& n, const VarModular& m) { return n *= m.inv(); }
    friend VarModular  operator /  (const VarModular& n, const VarModular& m) { VarModular r = n; return r /= m; }

    VarModular& operator ++ (   ) { return *this += 1; }
    VarModular& operator -- (   ) { return *this -= 1; }
    VarModular  operator ++ (int) { VarModular r = *this; *this += 1; return r; }
    VarModular  operator -- (int) { VarModular r = *this; *this -= 1; return r; }

    friend bool operator == (const VarModular& n, const VarModular& m) { return n.value == m.value; }
    friend bool operator != (const VarModular& n, const VarModular& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    static value_type           mod()      { return     P; }

    value_type norm(long long k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    VarModular inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return VarModular(x);
    }

  private:
    static uint64_t m;
  public:
    static void set_mod(value_type mod) {
        m = (__uint128_t(1) << 64) / mod;
        P = mod;
    }

    static value_type reduce(uint64_t a) {
        uint64_t q = ((__uint128_t(m) * a) >> 64);
        a -= q * P;
        if (a >= P)
            a -= P;
        return a;
    }
};
uint64_t VarModular::m = 0;
VarModular pow(VarModular m, long long p) {
    VarModular r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}
VarModular::value_type VarModular::P;
// use "VarModular::set_mod([your value])" later

ostream& operator << (ostream& o, const VarModular& m) { return o << m.value; }
istream& operator >> (istream& i,       VarModular& m) { long long k; i >> k; m.value = m.norm(k); return i; }
string   to_string(const VarModular& m) { return to_string(m.value); }

using Mint = VarModular;
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
using namespace var_mint_ns;

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    {
        int p;
        cin >> p;
        VarModular::set_mod(p);
    }

    // vector<vector<vector<Mint>>> dp(n + 1, vector<vector<Mint>>(n + 1, vector<Mint>(n + 1, 0)));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    int N = n;

    vector<vector<Mint>> C(N + 10, vector<Mint>(N + 10));
    for (int i = 0; i < C.size(); ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (int i = 1; i < C.size(); ++i)
        for (int j = 1; j < C.size(); ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

    for (int m = 0; m <= N; ++m)
        dp[m][0][0] = 1;
    init_C(N + 20);
    // for (int m = 1; m <= N; ++m) {
    //     for (int n = 1; n <= N; ++n) {
    //         for (int k = 0; k <= N; ++k) {
    //             if (m > n) {
    //                 if (k == 0) {
    //                     dp[m][n][k] = f[n];
    //                 } else {
    //                     dp[m][n][k] = 0;
    //                 }
    //                 continue;
    //             }
    //             if (k > n) {
    //                 dp[m][n][k] = 0;
    //                 continue;
    //             }
    //             if (m == 1) {
    //                 if (k == 1) {
    //                     dp[m][n][k] = f[n];
    //                 } else {
    //                     dp[m][n][k] = 0;
    //                 }
    //                 continue;
    //             }
    //             for (int p = 0; p < n; ++p) {
    //                 for (int c1 = 0; c1 <= k; ++c1) {
    //                     dp[m][n][k] += dp[m - 1][p][c1] * dp[m - 1][n - p - 1][k - c1] * C[n - 1][p];
    //                 }
    //             }
    //         }
    //     }
    // }

    array<char, 1 << 12> rndm;
    for (int i = 0; i < rndm.size(); ++i) {
        rndm[i] = rnd(2);
    }
    int t = 0;

    auto calc = y_combinator([&](auto calc, int m, int n, int k) -> Mint {
        if (dp[m][n][k] != -1) return dp[m][n][k];
        if (m > n) {
            if (k == 0) {
                dp[m][n][k] = (int)f[n];
                return f[n];
            } else {
                dp[m][n][k] = 0;
                return 0;
            }
        }
        if (k > n) {
            dp[m][n][k] = 0;
            return 0;
        }
        if (m == 1) {
            if (k == 1) {
                dp[m][n][k] = (int)f[n];
                return f[n];
            } else {
                dp[m][n][k] = 0;
                return 0;
            }
        }
        Mint ans = 0;
        for (int p = 0; p < n; ++p) {
            for (int c1 = max(0, k - (n - 1 - p)); c1 <= k && c1 <= p; ++c1) {
                Mint val1, val2;
                if (rndm[(t++) & (rndm.size() - 1)]) {
                    val1 = calc(m - 1, p, c1);
                    if (val1 == 0) continue;
                    val2 = calc(m - 1, n - p - 1, k - c1);
                } else {
                    val2 = calc(m - 1, n - p - 1, k - c1);
                    if (val2 == 0) continue;
                    val1 = calc(m - 1, p, c1);
                }
                ans += val1 * val2 * C[n - 1][p];
            }
        }
        dp[m][n][k] = (int)ans;
        return ans;
    });

    show(dp);

    // cout << dp[m][n][k] << '\n';
    cout << calc(m, n, k) << '\n';

    return 0;
}