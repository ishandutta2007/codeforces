/*
    author:  Maksim1744
    created: 23.04.2021 18:06:46
*/

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void test_case(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    Mint ans = 0;

    {
        ll ins = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                ins += a[i];
            else
                ins -= a[i];
        }


        vector<pair<ll, ll>> deltal(n);
        deltal[0] = {0ll, -a[0] * 2};
        for (int i = 1; i < n; ++i) {
            deltal[i] = deltal[i - 1];
            if (i % 2 == 0) {
                deltal[i].first -= a[i] * 2;
                deltal[i].second -= a[i] * 2;
            }
        }

        vector<pair<ll, ll>> deltar(n);
        deltar.back() = {0ll, a.back() * 2 * ((n - 1) % 2 == 1 ? 1 : -1)};
        for (int i = n - 2; i >= 0; --i) {
            deltar[i] = deltar[i + 1];
            if (i % 2 == 1) {
                deltar[i].first += a[i] * 2;
                deltar[i].second += a[i] * 2;
            }
        }

        show(deltal);
        show(deltar);

        show(ins);

        ordered_set<pair<ll, int>> ss;

        int id = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1) {
                ss.insert(mp(ins + deltal[i].first, id++));
                ss.insert(mp(ins + deltal[i].second, id++));
            } else {
                int j = i;
                ans += ss.size() - ss.order_of_key(mp(-deltar[j].first + 1, -1));
                if (j + 1 != n)
                    ans += ss.size() - ss.order_of_key(mp(-deltar[j].second + 1, -1));
            }
        }

        // #warning faster
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (i % 2 == 1 && j % 2 == 0) {
        //             if (ins + deltal[i].first + deltar[j].first > 0) ++ans;
        //             if (ins + deltal[i].second + deltar[j].first > 0) ++ans;
        //             if (j + 1 != n) {
        //                 if (ins + deltal[i].first + deltar[j].second > 0) ++ans;
        //                 if (ins + deltal[i].second + deltar[j].second > 0) ++ans;
        //             }
        //             show(i, j, ans);
        //         }
        //     }
        // }
    }
    {
        ll ins = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 1)
                ins += a[i];
            else
                ins -= a[i];
        }


        vector<pair<ll, ll>> deltal(n);
        deltal[0] = {0ll, a[0] * 2};
        for (int i = 1; i < n; ++i) {
            deltal[i] = deltal[i - 1];
            if (i % 2 == 1) {
                deltal[i].first -= a[i] * 2;
                deltal[i].second -= a[i] * 2;
            }
        }

        vector<pair<ll, ll>> deltar(n);
        deltar.back() = {0ll, a.back() * 2 * ((n - 1) % 2 == 1 ? -1 : 1)};
        for (int i = n - 2; i >= 0; --i) {
            deltar[i] = deltar[i + 1];
            if (i % 2 == 0) {
                deltar[i].first += a[i] * 2;
                deltar[i].second += a[i] * 2;
            }
        }

        show(deltal);
        show(deltar);

        show(ins);

        ordered_set<pair<ll, int>> ss;

        int id = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ss.insert(mp(ins + deltal[i].first, id++));
                if (i != 0)
                    ss.insert(mp(ins + deltal[i].second, id++));
            } else {
                int j = i;
                ans += ss.size() - ss.order_of_key(mp(-deltar[j].first + 1, -1));
                if (j + 1 != n)
                    ans += ss.size() - ss.order_of_key(mp(-deltar[j].second + 1, -1));
            }
        }

        // #warning faster
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (i % 2 == 0 && j % 2 == 1) {
        //             if (ins + deltal[i].first + deltar[j].first > 0) ++ans;
        //             if (ins + deltal[i].second + deltar[j].first > 0 && i != 0) ++ans;
        //             if (ins + deltal[i].first + deltar[j].second > 0 && j + 1 != n) ++ans;
        //             if (ins + deltal[i].second + deltar[j].second > 0 && i != 0 && j + 1 != n) ++ans;
        //             show(i, j, ans);
        //         }
        //     }
        // }
    }
    show(ans);
    ll sm = sum(a);
    // all p => sum(p) > sum(c)

    // PPPPCCCC
    show(ans);
    ll delta = -sm;
    for (int k : a) {
        delta += k * 2;
        if (delta > 0)
            ++ans;
    }
    cout << ans << '\n';
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