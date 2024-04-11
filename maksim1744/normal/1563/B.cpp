/*
    author:  Maksim1744
    created: 22.08.2021 15:13:25
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

struct Sieve {
    vector<char> isp;
    vector<int> primes;
    vector<int> mn;

    Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
        isp.assign(n + 1, true); isp[0] = isp[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isp[i])
                for (int j = i * i; j <= n; j += i)
                    isp[j] = false;

        if (gen_primes)
            for (int i = 2; i <= n; ++i)
                if (isp[i])
                    primes.push_back(i);

        if (gen_mn) {
            mn.resize(n + 1);
            for (int i = 2; i * i <= n; ++i)
                if (isp[i])
                    for (int j = i * i; j <= n; j += i)
                        mn[j] = i;
        }
    }

    bool is_prime(int k) const {
        return isp[k];
    }

    bool operator[](int k) const {
        return isp[k];
    }

    vector<pair<int, int>> get_prime_divs(int k) const {
        static vector<int> v;
        v.clear();
        while (k != 1 && !isp[k]) {
            v.pb(mn[k]);
            k /= mn[k];
        }
        if (k != 1)
            v.pb(k);
        sort(v.begin(), v.end());
        vector<pair<int, int>> res;
        for (int k : v) {
            if (res.empty() || k != res.back().first)
                res.eb(k, 0);
            res.back().second++;
        }
        return res;
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};

struct VarModular {
    using value_type = int;
  private:
    static value_type P;
  public:
    value_type value;

    VarModular(ll k = 0) : value(norm(k)) {}

    friend VarModular& operator += (      VarModular &n, const VarModular& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend VarModular  operator +  (const VarModular &n, const VarModular& m) { VarModular r = n; return r += m; }

    friend VarModular& operator -= (      VarModular &n, const VarModular& m) { n.value -= m.value; if (n.value < 0)    n.value += P; return n; }
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

    static value_type           mod()      { return     P; }

    value_type norm(ll k) {
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
VarModular pow(VarModular m, ll p) {
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Sieve s(4e6 + 20, false, true);

    int n, m;
    cin >> n >> m;
    VarModular::set_mod(m);
    vector<Mint> ans(n + 1, 0);
    vector<Mint> pref(n + 1, 0);
    vector<Mint> cur2(n + 1, 0);
    ans[1] = 1;
    pref[1] = 1;
    vector<int> divs;
    for (int i = 2; i <= n; ++i) {
        auto v = s.get_prime_divs(i);
        divs.clear();
        divs.pb(1);
        for (auto [p, c] : v) {
            int sz = divs.size();
            for (int i = 0; i < sz; ++i) {
                int cur = divs[i];
                for (int j = 0; j < c; ++j) {
                    cur *= p;
                    divs.pb(cur);
                }
            }
        }
        show(i, divs);
        cur2[i] = cur2[i - 1];
        for (int k : divs)
            if (k != 1)
                cur2[i] += ans[i / k] - ans[(i - 1) / k];
        ans[i] += cur2[i];
        ans[i] += pref[i - 1];

        pref[i] = ans[i] + pref[i - 1];
    }

    show(ans);
    show(cur2);
    show(pref);

    cout << ans[n] << '\n';

    return 0;
}