/*
    author:  Maksim1744
    created: 23.02.2020 20:57:14
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

    int n, k;
    cin >> n >> k;
    if (k == 1) {
        vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1, 0));
        dp[0][0] = 1;
        Mint res = 0;
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i + 1 <= n && j + 1 <= n)
                    dp[i + 1][j + 1] += dp[i][j];
                if (i + j <= n)
                    dp[i][i + j] += dp[i][j];
                if (i != 0 && j != 0)
                    res += dp[i][j];
            }
        }
        cout << res << endl;
    } else if (k == 2) {
        vector<vector<Mint>> dp(n + 1, vector<Mint>(n + 1, 0));
        dp[0][0] = 1;
        Mint res = 0;
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (i + 1 <= n && j + i + 1 <= n)
                    dp[i + 1][j + i + 1] += dp[i][j];
                if (j + i * (i + 1) / 2 <= n)
                    dp[i][j + i * (i + 1) / 2] += dp[i][j];
                if (i != 0 && j != 0)
                    res += dp[i][j];
                // if dp[i][j] != 0 then cnt <= 63
            }
        }
        cout << res << endl;
    } else {
        vector<vector<int>> bs;
        vector<int> b;
        function<void(int)> gen = [&](int sm) {
            if (sm > 70) return;
            vector<int> a;
            for (int i = 0; i < b.size(); ++i) {
                for (int j = 0; j < b[i]; ++j) {
                    a.pb((i + 1));
                }
            }
            reverse(a.begin(), a.end());
            int sma = 0;
            for (int i = 0; i < a.size(); ++i) {
                sma += (i + 1) * a[i];
                if (sma > n)
                    return;
            }
            assert(sm <= 64);
            int r;
            if (b.empty()) {
                r = n;
            } else {
                bs.pb(b);
                r = b.back();
            }
            for (int i = 1; i <= r; ++i) {
                b.pb(i);
                gen(sm + b.back());
                b.pop_back();
            }
        };
        gen(0);
        if (k == 3) {
            cout << bs.size() << endl;
            return 0;
        }
        vector<vector<int>> cs;
        for (int i = 0; i < k - 3; ++i) {
            cs.clear();
            for (auto& v : bs) {
                vector<int> c;
                int last = -1;
                for (int i = 0; i < v.size(); ++i) {
                    if (i + 1 == v.size() || v[i] != v[i + 1]) {
                        c.pb(i - last);
                        last = i;
                    }
                }
                sort(c.begin(), c.end());
                cs.pb(c);
            }
            sort(cs.begin(), cs.end());
            cs.erase(unique(cs.begin(), cs.end()), cs.end());
            swap(cs, bs);
            if (bs.size() == 1) break;
        }
        cout << bs.size() << endl;
    }

    return 0;
}