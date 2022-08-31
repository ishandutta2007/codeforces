/*
    author:  Maksim1744
    created: 13.10.2019 12:11:55
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll g = gcd(w, d);
    if (p % g != 0) {
        cout << -1 << '\n';
        return 0;
    }
    p /= g;
    w /= g;
    d /= g;
    ll w0 = -1, d0 = -1;
    for (ll i = 0; i < max(w, d); ++i) {
        if ((p - i * w) % d == 0) {
            w0 = i;
            d0 = (p - i * w) / d;
        }
    }
    show(w, d, p);
    show(w0, d0);
    // 15x + 5y = 0
    if (w0 == -1) {
        cout << -1 << '\n';
        return 0;
    }
    // w = w0 + kd >= 0
    // d = d0 - kw >= 0
    ll kmin = (-w0) / d;
    ll kmax;
    if (d0 >= 0)
        kmax = d0 / w;
    else
        kmax = (d0 - w + 1) / w;
    show(kmax);
    if (kmax < kmin) {
        cout << -1 << '\n';
        return 0;
    }
    ll k;
    k = kmax;
    ll wr = w0 + k * d;
    ll dr = d0 - k * w;
    ll z = n - wr - dr;
    if (z < 0) 
        cout << -1 << '\n';
    else
        cout << wr << ' ' << dr << ' ' << z << '\n';
    return 0;
}