/*
    author:  Maksim1744
    created: 24.04.2019 17:49:08
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }
    if (b < a)
        swap(a, b);
    ll k = 0;
    ll mn = a * b / __gcd(a, b);
    for (ll i = 1; i * i <= b - a; ++i) {
        if ((b - a) % i != 0)
            continue;
        for (auto d : {i, (b - a) / i}) {
            ll t = a % d;
            ll nowk = 0;
            if (t != 0) {
                nowk = d - t;
            }
            ll ans = (a + nowk) * (b + nowk) / __gcd(a + nowk, b - a);
            if (ans < mn) {
                mn = ans;
                k = nowk;
            }
        }
    }
    show(mn);
    cout << k << '\n';
    return 0;
}