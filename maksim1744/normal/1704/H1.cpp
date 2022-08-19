/*
    author:  Maksim1744
    created: 31.07.2022 18:40:07
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    int N = n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    {int p; cin >> p; VarModular::set_mod(p);}
    init_C(n * 2 + 20);

    // vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1, 0));
    // dp[0][0] = 1;
    // for (int n = 1; n < dp.size(); ++n) {
    //     for (int k = 1; k <= n; ++k) {
    //         for (int sz = 2; sz <= n; ++sz) {
    //             dp[n][k] += dp[n - sz][k - 1] * f[sz] * C(n - 1, sz - 1);
    //         }
    //     }
    // }
    vector<vector<Mint>> dp2(n + 1, vector<Mint>(n + 1, 0));
    dp2[0][0] = 1;
    for (int n = 1; n < dp2.size(); ++n) {
        for (int k = 1; k <= n; ++k) {
            dp2[n][k] = f[n] * C(n - 1, k - 1) * fi[k];
        }
    }
    vector<vector<Mint>> dp3(n + 1, vector<Mint>(n + 1, 0));
    dp3[0][0] = 1;
    for (int n = 1; n < dp2.size(); ++n) {
        for (int k = 1; k <= n; ++k) {
            dp3[n][k] = C(n, k) * dp2[n - k][k] * f[k];
        }
    }
    auto& dp = dp3;

    vector<vector<Mint>> pows(n + 5, vector<Mint>(n + 5));
    for (int i = 0; i < pows.size(); ++i) {
        pows[i][0] = 1;
    }
    for (int i = 0; i < pows.size(); ++i)
        for (int j = 1; j < pows[i].size(); ++j)
            pows[i][j] = pows[i][j - 1] * i;

    show(dp3);
    // assert(dp == dp2);

    Mint ans = 0;
    for (int n = 1; n < dp.size(); ++n) {
        for (int k = 1; k <= n; ++k) {
            int ones = N - n;
            Mint cur = dp[n][k] * C(N, n) * pows[n - k][ones] * pows[N - 1][k];
            show(n, k, cur);
            ans += cur;
        }
    }
    cout << ans << '\n';

    return 0;
}