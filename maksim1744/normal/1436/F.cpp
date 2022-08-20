/*
    author:  Maksim1744
    created: 28.10.2020 14:32:13
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

template<auto P> Modular<P>
pow(Modular<P> m, ll p) {
    if (p < 0) return Modular<P>(1) / pow(m, -p);
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> Modular<P>
pow(Modular<P> m, Modular<P> p) {
    return pow(m, p.value);
}

template<auto P> ostream& operator << (ostream& o, const Modular<P> &m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> &m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

// using Mint = Modular<1000000007>;
using Mint = Modular<998244353>;
// using Mint = long double;

const int N = 100050;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> freqs(N);
    for (int i = 0; i < n; ++i) {
        int a;
        int f;
        cin >> a >> f;
        for (int j = 1; j * j <= a; ++j) {
            if (a % j == 0) {
                freqs[j].eb(a, f);
                if (j * j != a) freqs[a / j].eb(a, f);
            }
        }
    }

    vector<int> divs(N, 0);
    vector<bool> ok(N, true); ok[0] = false;
    vector<bool> isp(N, true); isp[0] = isp[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isp[i]) {
            divs[i]++;
            for (int j = i * 2; j < N; j += i) {
                divs[j]++;
                isp[j] = false;
            }
            for (ll j = (ll)i * i; j < N; j += (ll)i * i)
                ok[j] = false;
        }
    }

    Mint ans = 0;

    Mint i2 = Mint(1) / 2;
    Mint i4 = Mint(1) / 4;
    Mint i8 = Mint(1) / 8;

    vector<Mint> calced(N, 0);

    for (int i = 0; i < N; ++i) {
        if (!ok[i]) continue;

        Mint cnt = 1, cnt0;
        Mint mod = 0, mod0;
        Mint sm = 0, sm0;
        Mint mod_sm = 0, mod_sm0;
        Mint sm2 = 0, sm20;
        Mint need = 0, need0;

        for (auto [aa, ff] : freqs[i]) {
            swap(cnt, cnt0);
            swap(mod, mod0);
            swap(sm, sm0);
            swap(mod_sm, mod_sm0);
            swap(sm2, sm20);
            swap(need, need0);

            Mint a = aa;
            Mint f = ff;

            if (calced[aa] == 0) calced[aa] = pow(Mint(2), ff);
            Mint p2 = calced[aa];

            Mint cntf = p2;
            Mint sumf = f * p2 * i2;
            Mint sumf2 = sumf + f * (f - 1) * p2 * i4;
            Mint sumf3 = f * (f - 1) * (f - 2) * p2 * i8 + sumf2 * 3 - sumf * 2;

            cnt = cnt0 * cntf;
            mod = cntf * mod0 + sumf * cnt0;
            sm = sm0 * cntf + sumf * a * cnt0;
            mod_sm = mod_sm0 * cntf + sm0 * sumf + mod0 * sumf * a + sumf2 * a * cnt0;
            sm2 = sm20 * cntf + sm0 * sumf * a * 2 + cnt0 * a * a * sumf2;
            need = (sumf3 * a * a - sumf2 * a * a) * cnt0 + sumf2 * a * a * mod0 + a * 2 * (sumf2 - sumf) * sm0 + a * sumf * 2 * mod_sm0 + sumf * sm20 + need0 * cntf;
        }

        if (divs[i] % 2 == 0)
            ans += need;
        else
            ans -= need;
    }
    cout << ans << '\n';

    return 0;
}