/*
    author:  Maksim1744
    created: 24.11.2019 12:02:23
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

int main() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> h(n);
    cin >> h;
    int ind = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (h[i] != h[i + 1]) {
            ind = i + 1;
            break;
        }
    }
    if (ind != -1) {
        vector<int> h0;
        for (int i = ind; i < n; ++i)
            h0.pb(h[i]);
        for (int i = 0; i < ind; ++i) {
            h0.pb(h[i]);
        }
        swap(h, h0);
    }
    // vector<ll> p(n + 5);
    // p[0] = 1;
    // for (int i = 1; i < p.size(); ++i) {
    //     p[i] = p[i - 1] * k % mod;
    // }
    ll mul = 1;
    for (int i = 1; i < h.size(); ++i) {
        if (h[i] == h[i - 1]) {
            --n;
            mul = mul * k % mod;
        }
    }
    if (h[0] == h.back()) {
        --n;
        mul = mul * k % mod;
    }
    vector<ll> f(n + 5);
    vector<ll> fi(n + 5);
    f[0] = 1;
    for (int i = 1; i < f.size(); ++i) {
        f[i] = f[i - 1] * i % mod;
    }
    fi.back() = mpow(f.back(), mod - 2);
    for (int i = fi.size() - 2; i >= 0; --i) {
        fi[i] = fi[i + 1] * (i + 1) % mod;
    }
    auto c = [&](int n, int k) {
        return f[n] * fi[k] % mod * fi[n - k] % mod;
    };
    ll ans = 0;
    for (int t = 0; t <= n / 2; ++t) {
        ans += c(n, t * 2) * c(t * 2, t) % mod * mpow(k - 2, n - t * 2) % mod;
    }
    ans %= mod;
    ans = (mpow(k, n) - ans + mod) % mod;
    ans = ans * mpow(2, mod - 2) % mod;
    ans = ans * mul % mod;
    cout << ans << '\n';
    return 0;
}