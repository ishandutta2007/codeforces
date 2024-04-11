/*
    author:  Maksim1744
    created: 28.05.2021 15:52:45
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

auto start_time = clock();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, M;
    cin >> n >> M;
    init_C(M * 2 + 5);
    auto bigc = [&](int n, int k) -> Mint {
        if (k < 0 || k > n) return 0;
        if (n < f.size()) return C(n, k);
        if (k * 2 > n) k = n - k;
        Mint a = 1;
        n %= Mint::mod();
        for (int i = n - k + 1; i <= n; ++i)
            a *= i;
        return a * fi[k];
    };

    vector<Mint> inv1(M + 3);
    {
        vector<Mint> tmp(M + 3);
        tmp[0] = 1;
        for (int i = 1; i < tmp.size(); ++i)
            tmp[i] = tmp[i - 1] * i;
        vector<Mint> tmpi(M + 3);
        tmpi.back() = 1 / tmp.back();
        for (int i = tmp.size() - 2; i >= 0; --i)
            tmpi[i] = tmpi[i + 1] * (i + 1);
        inv1[0] = 1;
        for (int i = 1; i < inv1.size(); ++i)
            inv1[i] = tmpi[i] * tmp[i - 1];
    }
    vector<Mint> inv2(M + 2);
    {
        vector<Mint> tmp(min(n, M + 2));
        tmp[0] = n;
        for (int i = 1; i < tmp.size(); ++i)
            tmp[i] = tmp[i - 1] * (n - i);
        vector<Mint> tmpi(tmp.size());
        tmpi.back() = 1 / tmp.back();
        for (int i = tmp.size() - 2; i >= 0; --i)
            tmpi[i] = tmpi[i + 1] * (n - (i + 1));
        inv2.assign(inv2.size(), 0);
        inv2[0] = tmpi[0];
        for (int i = 1; i < tmp.size(); ++i)
            inv2[i] = tmpi[i] * tmp[i - 1];
    }

    for (int a = 0; a <= M; ++a)
        inv2[a] *= inv1[a + 1];


    Mint cur0 = bigc(n, 1);
    int rem = n % Mint::mod();
    for (int m = 1; m <= M; ++m) {
        ll ans = 0;
        if (rem < m) {
            cout << 0 << ' ';
            continue;
        }
        Mint cur = cur0;
        for (int a = 0; a <= m; ++a) {
            ans += cur.value;
            cur *= inv2[a];
            cur *= ll(n - a - m) * (m - a);
        }
        cur0 = cur0 * inv1[m + 1] * (n - m);
        cout << ans % Mint::mod() << ' ';
        // if ((double)(clock() - start_time) / CLOCKS_PER_SEC > 5.9) {
        //     cerr << "done " << m << endl;
        //     break;
        // }
        // if (m % 1000 == 0) {
        //     cerr << m << ' ' << endl;
        //     mclock;
        // }
    }
    cout << '\n';

    return 0;
}