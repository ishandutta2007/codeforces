/*
    author:  Maksim1744
    created: 11.05.2021 23:32:05
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

struct VarModular {
    using value_type = int;
    static value_type mod;
    value_type value;

    VarModular(ll k = 0) : value(norm(k)) {}

    friend VarModular& operator += (      VarModular &n, const VarModular& m) { n.value += m.value; if (n.value >= mod) n.value -= mod; return n; }
    friend VarModular  operator +  (const VarModular &n, const VarModular& m) { VarModular r = n; return r += m; }

    friend VarModular& operator -= (      VarModular &n, const VarModular& m) { n.value -= m.value; if (n.value < 0)    n.value += mod; return n; }
    friend VarModular  operator -  (const VarModular &n, const VarModular& m) { VarModular r = n; return r -= m; }
    friend VarModular  operator -  (const VarModular &n)                      { return VarModular(-n.value); }

    friend VarModular& operator *= (      VarModular &n, const VarModular& m) { n.value = reduce(n.value * 1ll * m.value); return n; }
    friend VarModular  operator *  (const VarModular &n, const VarModular& m) { VarModular r = n; return r *= m; }

    friend VarModular& operator /= (      VarModular &n, const VarModular& m) { return n *= m.inv(); }
    friend VarModular  operator /  (const VarModular &n, const VarModular& m) { VarModular r = n; return r /= m; }

    VarModular& operator ++                    ()       { return *this += 1; }
    VarModular& operator --                    ()       { return *this -= 1; }
    VarModular  operator ++                 (int)       { VarModular r = *this; *this += 1; return r; }
    VarModular  operator --                 (int)       { VarModular r = *this; *this -= 1; return r; }

    friend bool operator == (const VarModular &n, const VarModular& m) { return n.value == m.value; }
    friend bool operator != (const VarModular &n, const VarModular& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    value_type norm(ll k) {
        if (!(-mod <= k && k < mod)) k %= mod;
        if (k < 0) k += mod;
        return k;
    }

    VarModular inv() const {
        value_type a = value, b = mod, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return VarModular(x);
    }

    static value_type reduce(uint64_t a) {
        static uint64_t m = (__uint128_t(1) << 64) / mod;
        uint64_t q = ((__uint128_t(m) * a) >> 64);
        a -= q * mod;
        if (a >= mod)
            a -= mod;
        return a;
    }
};
VarModular pow(VarModular m, ll p) {
    VarModular r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}
VarModular::value_type VarModular::mod = 1'000'000'007;
// use "VarModular::mod = [your value]" later

ostream& operator << (ostream& o, const VarModular &m) { return o << m.value; }
istream& operator >> (istream& i,       VarModular &m) { ll k; i >> k; m.value = m.norm(k); return i; }
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

    int n, k;
    cin >> n >> k;
    cin >> VarModular::mod;
    map<int, int> szs;
    {
        auto calc = y_combinator([&](auto calc, int n, int h) -> void {
            if (n == 1 || h == 1) {
                szs[n]++;
                return;
            }
            calc(n / 2, h - 1);
            calc((n + 1) / 2, h - 1);
        });
        calc(n, k);
    }

    show(szs);

    Mint ans = 0;

    init_C(n + 3);

    for (auto [sza, csza] : szs) {
        for (auto [szb, cszb] : szs) {
            Mint prob = Mint(sza) * csza * szb * cszb / (Mint(n) * (n - 1));
            if (sza == szb) prob = Mint(csza) * (csza - 1) * sza * sza / (Mint(n) * (n - 1));
            Mint cur = 0;

            for (int s = 0; s <= sza + szb - 2; ++s) {
                Mint L = max(0, s - szb + 1);
                Mint R = min(sza - 1, s);
                Mint x = R * (R + 1) / 2 - L * (L - 1) / 2;
                cur -= C(n, s + 2) * (s + 1) / C(n - 3, s - 1) * x;
                cur += C(n - 2, s) / C(n - 3, s - 1) * x * n * (n - 1) / 2;
            }

            cur /= sza;
            cur /= szb;
            cur /= n - 2;

            ans += prob * cur;
        }
    }
    for (auto [sza, csza] : szs) {
        Mint prob = Mint(sza) * csza * (sza - 1) / (Mint(n) * (n - 1));
        Mint cur = Mint(1) / 2;
        ans += prob * cur * n * (n - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}