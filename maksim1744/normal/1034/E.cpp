/*
    author:  Maksim1744
    created: 17.05.2021 12:12:43
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

using Mint = Modular<char(4)>;
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

// res[i] = sum_{j = submask(i)} a[i] * b[i ^ j]
template<typename T>
vector<T> subset_convolution(const vector<T> &a, const vector<T> &b) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    assert(a.size() == b.size());

    uint64_t msk = 0;
    uint64_t msk2 = 0;
    for (int i = 0; i <= 63; ++i) {
        if (i % 3 != 2) {
            msk ^= (uint64_t(1) << i);
        }
        if (i % 3 == 0) {
            msk2 ^= (uint64_t(1) << i);
        }
    }

    vector<uint64_t> tot_buf1(n);
    vector<uint64_t> tot_buf2(n);
    for (int i = 0; i < n; ++i) {
        int cnt = __builtin_popcount(i);
        tot_buf1[i] ^= (uint64_t(a[i]) << (cnt * 3));
        tot_buf2[i] ^= (uint64_t(b[i]) << (cnt * 3));
    }

    for (int b = 0; (1 << b) < n; ++b)
        for (int i = 0; i < n; ++i)
            if (((i >> b) & 1) == 0)
                tot_buf1[i ^ (1 << b)] = ((tot_buf1[i ^ (1 << b)] + tot_buf1[i]) & msk);
    for (int b = 0; (1 << b) < n; ++b)
        for (int i = 0; i < n; ++i)
            if (((i >> b) & 1) == 0)
                tot_buf2[i ^ (1 << b)] = ((tot_buf2[i ^ (1 << b)] + tot_buf2[i]) & msk);

    vector<T> res(n, 0);

    auto neg = [&](uint64_t x) {
        return x ^ ((x & msk2) << 1);
    };

    vector<uint64_t> buf3(n);

    for (int k = 0; k < n; ++k) {
        uint64_t v1 = tot_buf1[k];
        uint64_t v2 = tot_buf2[k];
        for (int i = 0; i < 21; ++i) {
            int v = ((v1 >> (i * 3)) & 3);
            for (int u = 0; u < v; ++u) {
                buf3[k] = ((v2 << (i * 3)) + buf3[k]) & msk;
            }
        }
    }

    for (int b = 0; (1 << b) < n; ++b)
        for (int i = 0; i < n; ++i)
            if (((i >> b) & 1) == 0)
                buf3[i ^ (1 << b)] = (buf3[i ^ (1 << b)] + neg(buf3[i])) & msk;

    for (int i = 0; i < n; ++i)
        res[i] = ((buf3[i] >> (__builtin_popcount(i) * 3)) & 3);

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    n = (1 << n);
    vector<char> a(n), b(n);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        a[i] = (s[i] - '0');
        b[i] = (t[i] - '0');
    }

    auto res = subset_convolution(a, b);

    res.back() = 0;
    for (int i = 0; i < res.size(); ++i)
        res.back() = ((res.back() + a[i] * b[i ^ (n - 1)]) & 3);

    for (auto x : res)
        cout << (int)x;
    cout << '\n';

    return 0;
}