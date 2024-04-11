/*
    author:  Maksim1744
    created: 25.05.2021 00:28:46
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

namespace ntt {
// TODO: square

Mint g = 0;  // set to something, or leave at 0 to calculate at runtime, g^(max power of 2 in mod-1) == 1
int maxn = -1;

vector<Mint> buf1;
vector<Mint> buf2;

vector<int> reversed = {0};

void init_g() {
    int phi = (int)Mint(-1);  // mod - 1
    maxn = 1;
    while ((phi & 1) == 0) {
        maxn <<= 1;
        phi >>= 1;
    }

    if (g == 0) {
        while (true) {
            Mint v = pow(g, maxn / 2);
            if (v != 1 && v * v == 1)
                break;
            ++g;
        }
    }

    assert(pow(g, maxn) == 1 && pow(g, maxn / 2) != 1);
}

void update_n(int n) {
    if (maxn == -1)
        init_g();
    assert(n <= maxn);
    assert((n & (n - 1)) == 0);
    int cur = reversed.size();
    if (n <= cur) return;
    reversed.resize(n);
    while (cur < n) {
        for (int i = 0; i < cur; ++i)
            reversed[i] <<= 1;
        for (int i = cur; i < (cur << 1); ++i)
            reversed[i] = reversed[i - cur] ^ 1;
        cur *= 2;
    }
}

void ntt_internal(vector<Mint> &v, int from, int n, bool inv) {
    update_n(n);
    int N = reversed.size();

    int d = __lg(N) - __lg(n);

    for (int i = 1; i < n; ++i)
        if (i < (reversed[i] >> d))
            swap(v[from + i], v[from + (reversed[i] >> d)]);

    for (int ln = 1; ln < n; ln <<= 1) {
        Mint ww;
        ww = pow(g, maxn / (ln * 2));
        if (inv)
            ww = Mint(1) / ww;
        for (int i = 0; i < n; i += (ln << 1)) {
            Mint w = 1;
            for (int j = 0; j < ln; ++j) {
                Mint y = v[from + i + j + ln] * w;
                w *= ww;
                v[from + i + j + ln] = v[from + i + j] - y;
                v[from + i + j]      = v[from + i + j] + y;
            }
        }
    }

    if (inv) {
        Mint ni = Mint(1) / n;
        for (int i = 0; i < n; ++i)
            v[from + i] *= ni;
    }
}

vector<Mint> ntt(const vector<Mint> &v, int n = -1) {
    if (n == -1) {
        n = 1;
        while (n < v.size()) n <<= 1;
    }
    assert(v.size() <= n);
    buf1.assign(n, 0);
    for (int i = 0; i < v.size(); ++i)
        buf1[i] = v[i];
    ntt_internal(buf1, 0, n, false);
    return buf1;
}

vector<Mint> ntti(const vector<Mint> &v) {
    assert(!v.empty() && (v.size() & (v.size() - 1)) == 0);
    buf1.resize(v.size());
    for (int i = 0; i < v.size(); ++i)
        buf1[i] = v[i];
    ntt_internal(buf1, 0, buf1.size(), true);
    return buf1;
}

vector<Mint> multiply(const vector<Mint> &a, const vector<Mint> &b) {
    if (a.empty() || b.empty()) return {};
    int n = 2;
    while (n < a.size() + b.size() - 1) n <<= 1;

    buf1.assign(n, 0);
    for (int i = 0; i < a.size(); ++i)
        buf1[i] = a[i];

    buf2.assign(n, 0);
    for (int i = 0; i < b.size(); ++i)
        buf2[i] = b[i];

    ntt_internal(buf1, 0, n, false);
    ntt_internal(buf2, 0, n, false);

    for (int i = 0; i < n; ++i)
        buf1[i] *= buf2[i];

    ntt_internal(buf1, 0, n, true);

    buf1.resize(a.size() + b.size() - 1);
    return buf1;
}

} // ntt

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    init_C(k + 5);

    vector<Mint> a(k + 1);
    vector<Mint> b(k + 1);
    for (int i = 0; i < a.size(); ++i)
        a[i] = Mint(i % 2 == 0 ? 1 : -1) / f[i];
    for (int i = 0; i < b.size(); ++i)
        b[i] = pow(Mint(i), k) / f[i];

    auto ab = ntt::multiply(a, b);

    auto S = [&](int n, int k) {
        return ab[k];
    };

    Mint ans = 0;
    Mint c = n;
    for (int i = 1; i <= k; ++i) {
        ans += S(k, i) * f[i] * c * (n >= i ? pow(Mint(n + 1), n - i) : Mint(1) / pow(Mint(n + 1), i - n));
        c /= (i + 1);
        c *= (n - i);
    }
    cout << ans << '\n';

    return 0;
}