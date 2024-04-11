/*
    author:  Maksim1744
    created: 15.02.2021 18:18:59
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

    Modular<P>& operator += (const Modular<P>& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular<P>  operator +  (const Modular<P>& m) const { Modular<P> r = *this; return r += m; }

    Modular<P>& operator -= (const Modular<P>& m)       { value -= m.value; if (value < 0)  value += P; return *this; }
    Modular<P>  operator -  (const Modular<P>& m) const { Modular<P> r = *this; return r -= m; }
    Modular<P>  operator -                     () const { return Modular<P>(-value); }

    Modular<P>& operator *= (const Modular<P>& m)       { value = value * 1ll * m.value % P; return *this; }
    Modular<P>  operator *  (const Modular<P>& m) const { Modular<P> r = *this; return r *= m; }

    Modular<P>& operator /= (const Modular<P>& m)       { return *this *= m.inv(); }
    Modular<P>  operator /  (const Modular<P>& m) const { Modular<P> r = *this; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; *this -= 1; return r; }

    bool        operator == (const Modular<P>& m) const { return value == m.value; }
    bool        operator != (const Modular<P>& m) const { return value != m.value; }

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> c(26);
    cin >> c;

    int N = n / 2 + 5;

    vector<vector<vector<vector<Mint>>>> cntab(N, vector<vector<vector<Mint>>>(N, vector<vector<Mint>>(N, vector<Mint>(3, 0))));
    cntab[1][1][0][0] = 1;
    cntab[1][0][1][1] = 1;
    cntab[1][0][0][2] = 24;

    for (int ln = 1; ln + 1 < cntab.size(); ++ln) {
        for (int ca = 0; ca + 1 < cntab.size(); ++ca) {
            for (int cb = 0; cb + 1 < cntab.size(); ++cb) {
                cntab[ln + 1][ca + 1][cb][0] += cntab[ln][ca][cb][1];
                cntab[ln + 1][ca + 1][cb][0] += cntab[ln][ca][cb][2];

                cntab[ln + 1][ca][cb + 1][1] += cntab[ln][ca][cb][0];
                cntab[ln + 1][ca][cb + 1][1] += cntab[ln][ca][cb][2];

                cntab[ln + 1][ca][cb][2] += cntab[ln][ca][cb][0] * 24;
                cntab[ln + 1][ca][cb][2] += cntab[ln][ca][cb][1] * 24;
                cntab[ln + 1][ca][cb][2] += cntab[ln][ca][cb][2] * 23;
            }
        }
    }

    auto cntable = cntab;
    for (int n = 0; n < cntable.size(); ++n) {
        for (int a = (int)cntab.size() - 1; a >= 0; --a) {
            for (int b = (int)cntab.size() - 1; b >= 0; --b) {
                for (int k = 0; k < 3; ++k) {
                    if (a + 1 < cntab.size())
                        cntable[n][a][b][k] += cntable[n][a + 1][b][k];
                    if (b + 1 < cntab.size())
                        cntable[n][a][b][k] += cntable[n][a][b + 1][k];
                    if (a + 1 < cntab.size() && b + 1 < cntab.size())
                        cntable[n][a][b][k] -= cntable[n][a + 1][b + 1][k];
                }
            }
        }
    }

    auto get_cntab = [&](int n, int a, int b) {
        if (n < 0 || a < 0 || b < 0) return Mint(0);
        if (n >= cntab.size() || a >= cntab.size() || b >= cntab.size()) return Mint(0);
        return cntab[n][a][b][0] + cntab[n][a][b][1] + cntab[n][a][b][2];
    };
    auto get_cntable = [&](int n, int a, int b) {
        a = max(a, 0);
        b = max(b, 0);
        if (n < 0) return Mint(0);
        if (n >= cntable.size() || a >= cntable.size() || b >= cntable.size()) return Mint(0);
        return cntable[n][a][b][0] + cntable[n][a][b][1] + cntable[n][a][b][2];
    };

    Mint ans = Mint(26 * 26) * pow(Mint(25), n - 2);

    show(ans);

    for (int i = 0; i < 26; ++i) {
        for (int c1 = 0; c1 < cntab.size(); ++c1) {
            for (int c2 = 0; c2 < cntab.size(); ++c2) {
                Mint x = get_cntab(n / 2, c1, c2) * get_cntable(n - n / 2, c[i] - c1 + 1, 0);
                if (i == 25)
                    show(i, c1, c2, x);
                ans -= x;
            }
        }
    }

    show(ans);

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int c1 = 0; c1 < cntab.size(); ++c1) {
                for (int c2 = 0; c2 < cntab.size(); ++c2) {
                    ans += get_cntab(n / 2, c1, c2) * get_cntable(n - n / 2, c[i] - c1 + 1, c[j] - c2 + 1);
                }
            }
        }
    }

    show(ans);

    cout << ans << '\n';

    return 0;
}