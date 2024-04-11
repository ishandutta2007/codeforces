/*
    author:  Maksim1744
    created: 23.04.2019 16:33:16
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
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), p(m);
    cin >> x >> p;
    ll g = x[1] - x[0];
    for (int i = 2; i < n; ++i) {
        g = __gcd(g, x[i] - x[i - 1]);
    }
    show(g);
    ll okp = -1;
    int okpi = -1;
    for (int i = 0; i < m; ++i) {
        if (g % p[i] == 0) {
            okp = p[i];
            okpi = i;
            break;
        }
    }
    if (okp == -1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        cout << x[0] << ' ' << okpi + 1 << '\n';
    }
    return 0;
}