/*
    author:  Maksim1744
    created: 05.12.2019 18:34:29
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

const int N = 1e6 + 10;

const ll mod = 998244353;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inv(ll k) {
    return mpow(k, mod - 2);
}

int main() {
    vector<ll> f(N, 1);
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % mod;
    }
    vector<ll> fi(N, 1);
    fi.back() = inv(f.back());
    for (int i = N - 2; i >= 0; --i) {
        fi[i] = fi[i + 1] * (i + 1) % mod;
    }
    auto get_c = [&](int n, int k) {
        if (k > n || k < 0)
            return 0ll;
        return f[n] * fi[k] % mod * fi[n - k] % mod;
    };
    ll ans = 0;
    int open = 0, close = 0, que = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (auto c : s) {
        if (c == '(')
            ++open;
        else if (c == ')')
            ++close;
        else
            ++que;
    }
    int nowo = 0, nowc = 0, nowq = 0;
    for (int i = 0; i <= n; ++i) {
        for (ll l = 0; l <= n; ++l) {
            ans += l * get_c(nowq, l - nowo) % mod * get_c(que - nowq, l - (close - nowc)) % mod;
        }
        ans %= mod;
        if (i != n) {
            if (s[i] == '(')
                ++nowo;
            else if (s[i] == ')')
                ++nowc;
            else
                ++nowq;
        }
    }
    cout << ans << '\n';
    return 0;
}