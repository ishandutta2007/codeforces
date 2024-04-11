/*
    author:  Maksim1744
    created: 18.03.2021 18:14:09
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

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    static value_type mod()                { return     P; }

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

    string xx, yy;
    cin >> xx >> yy;
    vector<int> x(xx.size()), y(yy.size());
    for (int i = 0; i < xx.size(); ++i) {
        x[i] = (xx[i] - 'a');
    }
    for (int i = 0; i < yy.size(); ++i) {
        y[i] = (yy[i] - 'a');
    }

    show(x, y);

    vector<vector<vector<Mint>>> dp(x.size() + 1, vector<vector<Mint>>(y.size() + 1, vector<Mint>(26, 0)));
    vector<vector<Mint>> tot(x.size() + 1, vector<Mint>(y.size() + 1, 0));
    for (int i = 1; i <= x.size(); ++i) {
        dp[i][0][x[i - 1]] = 1;
        tot[i][0]++;
        for (int j = i - 1; j >= 1; --j) {
            if (x[j - 1] == x[j]) break;
            dp[i][0][x[i - 1]]++;
            tot[i][0]++;
        }
    }
    for (int i = 1; i <= y.size(); ++i) {
        dp[0][i][y[i - 1]] = 1;
        tot[0][i]++;
        for (int j = i - 1; j >= 1; --j) {
            if (y[j - 1] == y[j]) break;
            dp[0][i][y[i - 1]]++;
            tot[0][i]++;
        }
    }

    show(x, y);

    for (int i = 1; i <= x.size(); ++i) {
        for (int j = 1; j <= y.size(); ++j) {
            dp[i][j][x[i - 1]] += tot[i - 1][j] - dp[i - 1][j][x[i - 1]];
            dp[i][j][y[j - 1]] += tot[i][j - 1] - dp[i][j - 1][y[j - 1]];
            if (i != 1)
                dp[i][j][x[i - 1]] += tot[0][j] - dp[0][j][x[i - 1]];
            if (j != 1)
                dp[i][j][y[j - 1]] += tot[i][0] - dp[i][0][y[j - 1]];
            tot[i][j] += dp[i][j][x[i - 1]];
            if (y[j - 1] != x[i - 1])
                tot[i][j] += dp[i][j][y[j - 1]];
        }
    }

    show(tot);

    show(dp);

    Mint ans = 0;
    for (int i = 1; i <= x.size(); ++i)
        for (int j = 1; j <= y.size(); ++j)
            for (int k = 0; k < 26; ++k)
                ans += dp[i][j][k];
    cout << ans << '\n';

    return 0;
}