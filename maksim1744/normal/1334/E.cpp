/*
    author:  Maksim1744
    created: 10.04.2020 18:29:40
*/

#include <bits/stdc++.h>

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
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    Modular<P>& operator += (const Modular<P>& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular<P>  operator +  (const Modular<P>& m) const { Modular<P> r = *this; return r += m; }

    Modular<P>& operator -= (const Modular<P>& m)       { value -= m.value; if (value <  0) value += P; return *this; }
    Modular<P>  operator -  (const Modular<P>& m) const { Modular<P> r = *this; return r -= m; }
    Modular<P>  operator -                     () const { return Modular<P>(-value); }

    Modular<P>& operator *= (const Modular<P> &m)       { value = value * 1ll * m.value % P; return *this; }
    Modular<P>  operator *  (const Modular<P>& m) const { Modular<P> r = *this; return r *= m; }

    Modular<P>& operator /= (const Modular<P> &m)       { return *this *= m.inv(); }
    Modular<P>  operator /  (const Modular<P>& m) const { Modular<P> r = *this; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; r += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; r -= 1; return r; }

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

template<auto P> ostream& operator << (ostream& o, const Modular<P> m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

// using Mint = Modular<1000000007>;
using Mint = Modular<998244353>;
// using Mint = long double;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<Mint> f(100);
    f[0] = 1;
    for (int i = 1; i < f.size(); ++i)
        f[i] = f[i - 1] * Mint(i);
    auto C = [&](ll n, ll k) {
        if (k < 0 || k > n) return Mint(0);
        return f[n] / f[k] / f[n - k];
    };

    ll D;
    cin >> D;
    vector<ll> primes;
    ll k = 2;
    while (D % 2 == 0) {
        primes.pb(2);
        D /= 2;
    }
    k = 3;
    while (k * k <= D) {
        while (D % k == 0) {
            primes.pb(k);
            D /= k;
        }
        k += 2;
    }
    if (D != 1) primes.pb(D);
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    auto gn = [&](ll x) {
        vector<ll> v(primes.size(), 0);
        int i = 0;
        for (auto k : primes) {
            while (x % k == 0) {
                x /= k;
                v[i]++;
            }
            ++i;
        }
        return v;
    };
    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        auto v1 = gn(a);
        auto v2 = gn(b);
        show(v1, v2);
        vector<int> inc, dec;
        for (int i = 0; i < primes.size(); ++i) {
            if (v1[i] < v2[i]) {
                inc.pb(v2[i] - v1[i]);
            } else if (v1[i] > v2[i]) {
                dec.pb(v1[i] - v2[i]);
            }
        }
        show(inc, dec);
        int sinc = 0, sdec = 0;
        for (auto k : inc) {
            sinc += k;
        }
        
        
        for (auto k : dec) {
            sdec += k;
        }
        Mint ans = 1;
        for (auto k : dec) {
            ans *= C(sdec, k);
            sdec -= k;
        }
        for (auto k : inc) {
            ans *= C(sinc, k);
            sinc -= k;
        }
        
        
        cout << ans << '\n';
    }

    return 0;
}