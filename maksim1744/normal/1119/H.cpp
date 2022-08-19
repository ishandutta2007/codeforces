/*
    author:  Maksim1744
    created: 14.06.2021 21:33:36
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

// usage: auto c = fwht::fwht(a, b, fwht::AND);
// just transformation: fwht::fwht(a, inv, fwht::AND);
namespace fwht {

enum Type {
    XOR,
    NXOR,
    AND,
    OR,
};

template<typename T>
void fwht(vector<T> &v, bool inv = false, Type tp = XOR) {
    assert((v.size() & (v.size() - 1)) == 0);
    for (int step = 1; step < v.size(); step <<= 1) {
        for (int i = 0; i < v.size(); i += step * 2) {
            for (int j = 0; j < step; ++j) {
                T a = v[i + j], b = v[i + j + step];
                if (tp == Type::XOR) {
                    v[i + j] = a + b;
                    v[i + j + step] = a - b;
                } else if (tp == Type::NXOR) {
                    v[i + j] = -a + b;
                    v[i + j + step] = a + b;
                } else if (tp == Type::AND) {
                    v[i + j] = (inv ? b - a : b);
                    v[i + j + step] = (inv ? a : a + b);
                } else if (tp == Type::OR) {
                    v[i + j] = (inv ? b : a + b);
                    v[i + j + step] = (inv ? a - b : a);
                }
            }
        }
    }
    if (inv && (tp == Type::XOR || tp == Type::NXOR)) {
        T val = 1;
        for (int j = 1; j < v.size(); j <<= 1)
            val *= 2;
        for (int i = 0; i < v.size(); ++i) {
            v[i] /= val;
        }
    }
}

template<typename T>
vector<T> fwht(vector<T> a, vector<T> b, Type tp = XOR) {
    fwht(a, false, tp);
    fwht(b, false, tp);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= b[i];
    fwht(a, true, tp);
    return a;
}

};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    Mint x, y, z;
    cin >> x >> y >> z;

    vector<Mint> res(1 << k, 1);
    vector<int> a(n), b(n), c(n);
    // vector<uint64_t> abc(n, 0);

    vector<Mint> b8 = {
         x +y +z,
         x +y -z,
         x -y +z,
         x -y -z,
    };

    vector<pair<int, int>> al;

    int tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        tot ^= a[i];
        b[i] ^= a[i];
        c[i] ^= a[i];
        al.eb(b[i], c[i]);
        a[i] = 0;
        // for (int j = 0; j < k; ++j) {
        //     abc[i] |= (uint64_t((b[i] >> j) & 1) << (j * 2 + 1));
        //     abc[i] |= (uint64_t((c[i] >> j) & 1) << (j * 2 + 0));
        // }
    }

    sort(al.begin(), al.end());
    vector<pair<pair<int, int>, int>> al2;
    {
        for (auto p : al) {
            if (al2.empty() || al2.back().first != p)
                al2.eb(p, 0);
            al2.back().second++;
        }
    }

    const int B = 5;

    array<char, 1 << max(B, 17 - B)> popcnt;
    for (int i = 0; i < popcnt.size(); ++i)
        popcnt[i] = __builtin_popcount(i) % 2;
    array<array<array<int, 4>, 1 << B>, 1 << B> cnt;
    res.resize(max((int)res.size(), 1 << B));
    for (int j = 0; j < (1 << k); j += (1 << B)) {
        for (int k = 0; k < cnt.size(); ++k)
            for (int i = 0; i < cnt[k].size(); ++i)
                cnt[k][i].fill(0);

        for (auto [bc, x] : al2) {
            auto [b, c] = bc;
            cnt[b & ((1 << B) - 1)][c & ((1 << B) - 1)][(popcnt[(j & b) >> B] << 1) | popcnt[(j & c) >> B]] += x;
        }

        for (int j2 = 0; j2 < (1 << B); ++j2) {
            array<int, 4> c;
            c.fill(0);
            for (int ia = 0; ia < (1 << B); ++ia) {
                for (int ib = 0; ib < (1 << B); ++ib) {
                    int m = (popcnt[(j2 & ia)] << 1) | popcnt[(j2 & ib)];
                    for (int k = 0; k < 4; ++k)
                        c[k ^ m] += cnt[ia][ib][k];
                }
            }

            for (int i = 0; i < 4; ++i)
                res[j + j2] *= pow(b8[i], c[i]);
        }
    }
    res.resize(1 << k);

    // for (int j = 0; j < (1 << k); ++j) {
    //     vector<int> cnt(4);
    //     for (auto u : abc) {
    //         int msk = 0;
    //         for (int i = 0; i < k; ++i) {
    //             if ((j >> i) & 1) {
    //                 msk ^= (u >> (i * 2));
    //             }
    //         }
    //         cnt[msk & 3]++;
    //     }
    //     for (int i = 0; i < 4; ++i)
    //         res[j] *= pow(b8[i], cnt[i]);
    // }

    fwht::fwht(res, true, fwht::XOR);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i ^ tot] << ' ';
    }
    cout << '\n';

    return 0;
}