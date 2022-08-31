/*
    author:  Maksim1744
    created: 12.05.2021 14:29:28
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    map<Rat, int> nums;
    auto get_num = [&](const Rat &r) {
        if (!nums.count(r)) {
            int s = nums.size();
            nums[r] = s;
        }
        return nums[r];
    };
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Rat x(a, b);
        Rat y(c, d);
        edges.eb(mp(get_num((x + 1) / y), get_num(x / (y + 1))), i);
    }

    vector<vector<pair<int, int>>> g(nums.size());
    for (auto [uv, i] : edges) {
        auto [u, v] = uv;
        g[u].eb(v, i);
        if (u != v)
            g[v].eb(u, i);
    }

    show(edges);
    show(g);

    n = g.size();
    vector<pair<int, int>> ans;
    vector<bool> u(n, false);
    set<int> dead = {-1};
    auto dfs = y_combinator([&](auto dfs, int v, int p = -1) -> void {
        u[v] = true;
        vector<int> cands;
        int pcand = -1;
        for (auto [k, i] : g[v]) {
            if (i == p) {
                pcand = i;
                continue;
            }
            cands.pb(i);
            if (!u[k]) {
                dfs(k, i);
            }
        }
        cands.pb(pcand);
        {
            vector<int> tmp;
            for (int k : cands)
                if (!dead.count(k))
                    tmp.pb(k);
            swap(tmp, cands);
        }
        for (int i = 0; i + 1 < cands.size(); i += 2) {
            ans.eb(cands[i], cands[i + 1]);
            dead.insert(cands[i]);
            dead.insert(cands[i + 1]);
        }
    });
    for (int i = 0; i < n; ++i)
        if (!u[i])
            dfs(i);

    cout << ans.size() << '\n';
    for (auto [a, b] : ans)
        cout << a + 1 << ' ' << b + 1 << '\n';

    return 0;
}