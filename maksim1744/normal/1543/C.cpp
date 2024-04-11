/*
    author:  Maksim1744
    created: 07.07.2021 17:42:08
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

template<typename T>
struct Rational {
    T a, b;
    Rational(T a = 0, T b = 1) : a(a), b(b) { norm(); }

    T floor() const { T res = a / b; if (a < 0 && res != b * res) --res; return res; }
    T ceil()  const { T res = a / b; if (a > 0 && res != b * res) ++res; return res; }

    friend Rational<T>& operator += (      Rational<T> &n, const Rational<T> &m) { return n = Rational(n.a * m.b + n.b * m.a, n.b * m.b); }
    friend Rational<T>  operator +  (const Rational<T> &n, const Rational<T> &m) { auto res = n; return res += m; }
    friend Rational<T>& operator -= (      Rational<T> &n, const Rational<T> &m) { return n = Rational(n.a * m.b - n.b * m.a, n.b * m.b); }
    friend Rational<T>  operator -  (const Rational<T> &n, const Rational<T> &m) { auto res = n; return res -= m; }
    friend Rational<T>  operator -  (const Rational<T> &n)                       { return Rational{-n.a, n.b}; }
    friend Rational<T>& operator *= (      Rational<T> &n, const Rational<T> &m) { return n = Rational(n.a * m.a, n.b * m.b); }
    friend Rational<T>  operator *  (const Rational<T> &n, const Rational<T> &m) { auto res = n; return res *= m; }
    friend Rational<T>& operator /= (      Rational<T> &n, const Rational<T> &m) { return n = Rational(n.a * m.b, n.b * m.a); }
    friend Rational<T>  operator /  (const Rational<T> &n, const Rational<T> &m) { auto res = n; return res /= m; }

    // doesn't overflow
    // friend bool operator <  (Rational<T> n, Rational<T> m) {
    //     T a = n.floor(), b = m.floor(); if (a != b) return a < b;
    //     n -= a; m -= b;
    //     while (true) {
    //         if (n.b == m.b) return n.a < m.a;
    //         if (n.a == 0) return true; else if (m.a == 0) return false;
    //         swap(n, m); swap(n.a, n.b); swap(m.a, m.b);
    //         n.a %= n.b; m.a %= m.b;
    //     }
    //     return false;
    // }
    // maybe faster?
    friend bool operator <  (const Rational<T> &n, const Rational<T> &m) { return n.a * m.b < n.b * m.a; }
    friend bool operator <= (const Rational<T> &n, const Rational<T> &m) { return !(m < n); }
    friend bool operator >  (const Rational<T> &n, const Rational<T> &m) { return   m < n ; }
    friend bool operator >= (const Rational<T> &n, const Rational<T> &m) { return !(n < m); }

    friend bool operator == (const Rational<T> &n, const Rational<T> &m) { return n.a == m.a && n.b == m.b; }
    friend bool operator != (const Rational<T> &n, const Rational<T> &m) { return n.a != m.a || n.b != m.b; }

    operator long double () const {
        return (ld) a / b;
    }

    static T gcd(T a, T b) {
        while (b != 0) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void norm() {
        if (b < 0) {
            a = -a;
            b = -b;
        }
        T d = gcd((a < 0 ? -a : a), b);
        a /= d;
        b /= d;
    }
};

template<typename T>
Rational<T> pow(Rational<T> a, ll p) {
    Rational<T> res = 1;
    while (p) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

template<typename T> ostream& operator << (ostream &o, const Rational<T> &m) { return o << m.a << '/' << m.b; }
template<typename T> istream& operator >> (istream &i,       Rational<T> &m) { T a, b = 1; i >> a; if (i.peek() == '/') i.get(), i >> b; m = Rational<T>(a, b); return i; }

using Rat = Rational<ll>;

void test_case(int test) {
    vector<double> v1(4);
    cin >> v1;
    v1.back() /= 2;
    vector<Rat> v2(4);
    const int N = 20000;
    for (int i = 0; i < 4; ++i) {
        v2[i] = llround(v1[i] * N);
    }
    Rat a = v2[0] / Rat(N);
    Rat b = v2[1] / Rat(N);
    Rat c = v2[2] / Rat(N);
    Rat v = v2[3] / Rat(N);
    show(a, b, c, v);

    map<array<pair<Rat, ll>, 3>, ld> mem;

    auto calc = y_combinator([&](auto calc, pair<Rat, ll> a, pair<Rat, ll> b, pair<Rat, ll> c) -> ld {
        if (mem.count({a, b, c})) return mem[{a, b, c}];
        ld ans = c.first + v * Rat(c.second);

        if (a.first + v * Rat(a.second) == Rat(0)) {
            if (b.first + v * Rat(b.second) == Rat(0)) {
                return 1;
            } else {
                if (b.first + v * Rat(b.second) >= v * Rat(2)) {
                    ans += (1 + calc(a, mp(b.first, b.second - 2), mp(c.first, c.second + 2))) * (ld)(b.first + v * Rat(b.second));
                } else {
                    Rat d = b.first + v * Rat(b.second);
                    if (abs(d) > 0)
                        ans += (1 + calc(a, mp(0, 0), mp(c.first + d, c.second))) * (ld)(b.first + v * Rat(b.second));
                }
                return ans;
            }
        } else if (b.first + v * Rat(b.second) == Rat(0)) {
            if (a.first + v * Rat(a.second) >= v * Rat(2)) {
                ans += (1 + calc(mp(a.first, a.second - 2), b, mp(c.first, c.second + 2))) * (ld)(a.first + v * Rat(a.second));
            } else {
                Rat d = a.first + v * Rat(a.second);
                if (abs(d) > 0)
                    ans += (1 + calc(mp(0, 0), b, mp(c.first + d, c.second))) * (ld)(a.first + v * Rat(a.second));
            }
            return ans;
        }

        if (a.first + v * Rat(a.second) >= v * Rat(2)) {
            ans += (1 + calc(mp(a.first, a.second - 2), mp(b.first, b.second + 1), mp(c.first, c.second + 1))) * (ld)(a.first + v * Rat(a.second));
        } else {
            Rat d = a.first + v * Rat(a.second);
            if (abs(d) > 0)
                ans += (1 + calc(mp(0, 0), mp(b.first + d / Rat(2), b.second), mp(c.first + d / Rat(2), c.second))) * (ld)(a.first + v * Rat(a.second));
        }

        if (b.first + v * Rat(b.second) >= v * Rat(2)) {
            ans += (1 + calc(mp(a.first, a.second + 1), mp(b.first, b.second - 2), mp(c.first, c.second + 1))) * (ld)(b.first + v * Rat(b.second));
        } else {
            Rat d = b.first + v * Rat(b.second);
            if (abs(d) > 0)
                ans += (1 + calc(mp(a.first + d / Rat(2), a.second), mp(0, 0), mp(c.first + d / Rat(2), c.second))) * (ld)(b.first + v * Rat(b.second));
        }

        return mem[{a, b, c}] = ans;
    });
    cout << fixed << setprecision(20) << calc(mp(a, 0), mp(b, 0), mp(c, 0)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}