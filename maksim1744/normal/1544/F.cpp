/*
    author:  Maksim1744
    created: 17.07.2021 18:28:06
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

    friend Modular<P>& operator *= (      Modular<P> &n, const Modular<P>& m) { n.value = n.value * m.value % P; return n; }
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

    value_type norm(int k) {
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

using Mint = Modular<31607>;
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

const int MOD = 31607;
const int MOD2 = MOD * MOD;
const ll MOD3 = (ll)MOD * MOD * MOD;

array<array<uint16_t, 1 << 21>, 2> dp = {};
array<int, 1 << 21> res;
array<uint16_t, 1 << 21> tmp;
array<uint16_t, 1 << 21> tmp2;
array<int, 1 << 21> anybit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<Mint>> a(n, vector<Mint>(n));
    cin >> a;
    {
        Mint iv = 1 / Mint(10000);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = 1 - a[i][j] * iv;
            }
        }
    }

    for (int i = 0; i < anybit.size(); ++i) {
        for (int j = 0; j < 21; ++j) {
            if ((i >> j) & 1)
                anybit[i] = j;
        }
    }

    auto calc = [&](const vector<vector<Mint>> &a) {
        res.fill(1);
        auto a1 = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a1[i][j] = 1 - a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int i = 0; i < (1 << n); ++i) {
                tmp[i] = 0;
            }
            tmp[0] = 1;
            for (int j = 1; j < (1 << n); ++j) {
                int b = anybit[j];
                tmp[j] = (ll)tmp[j ^ (1 << b)] * (ll)a1[i][b].value % MOD;
            }
            for (int msk = 0; msk < (1 << n); ++msk) {
                uint64_t mul = 1;
                uint64_t cur = 1;
                // for (int j = 0; j < n; ++j) {
                //     if ((msk >> j) & 1) {
                //         // mul *= a1[i][j].value;
                //         // if (mul >= MOD3) mul %= MOD;
                //     } else {
                //         cur *= a1[i][j].value;
                //         if (cur >= MOD3) cur %= MOD;
                //     }
                // }
                mul = tmp[msk];
                cur = tmp[((1 << n) - 1) ^ msk];
                mul = mul % MOD * (1 - Mint(cur % MOD)).value % MOD;
                res[msk] = mul * res[msk] % MOD;
            }
        }

        for (int b = 0; b < n; ++b)
            for (int i = 0; i < (1 << n); ++i)
                if (((i >> b) & 1) == 0)
                    if ((res[i] -= res[i | (1 << b)]) < 0) res[i] += MOD;

        return res[0];
    };

    Mint val1 = calc(a);
    auto b = a;
    for (int i = 0; i < n; ++i) {
        b[i][i] = 0;
    }
    Mint val2 = calc(b);
    for (int i = 0; i < n; ++i) {
        val2 *= 1 - a[i][i];
    }
    b = a;
    for (int i = 0; i < n; ++i) {
        b[i][n - 1 - i] = 0;
    }
    Mint val3 = calc(b);
    for (int i = 0; i < n; ++i) {
        val3 *= 1 - a[i][n - 1 - i];
    }
    b = a;
    for (int i = 0; i < n; ++i) {
        b[i][i] = 0;
        b[i][n - 1 - i] = 0;
    }
    Mint val4 = calc(b);
    for (int i = 0; i < n; ++i) {
        val4 *= 1 - a[i][i];
        if (i != n - 1 - i)
            val4 *= 1 - a[i][n - 1 - i];
    }

    Mint ans = val1 - val2 - val3 + val4;
    cout << 1 - ans << '\n';

    return 0;
}