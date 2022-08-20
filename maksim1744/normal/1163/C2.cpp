/*
    author:  Maksim1744
    created: 09.05.2019 18:33:04
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
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    cin >> p;
    vector<pair<pair<int, int>, int>> ls;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int b = p[i].first - p[j].first;
            int a = p[j].second - p[i].second;
            int c = -(a * p[i].first + b * p[i].second);
            // show(p[i], p[j], a, b, c);
            assert(c == -(a * p[j].first + b * p[j].second));
            int d = -1;
            if (a == 0 || b == 0) {
                d = a + b;
            } else {
                d = __gcd(a, b);
            }
            if (c != 0)
                d = __gcd(d, c);
            a /= d; b /= d; c /= d;
            if (a < 0) {
                a *= -1; b *= -1; c *= -1;
            } else if (a == 0) {
                if (b < 0) {
                    a *= -1; b *= -1; c *= -1;
                }
            }
            ls.pb(mp(mp(a, b), c));
        }
    }
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());
    ll m = ls.size();
    ll res = m * (m - 1) / 2;
    map<pair<int, int>, int> mm;
    for (auto p : ls) {
        mm[p.first]++;
    }
    for (auto p : mm) {
        res -= (ll)p.second * (p.second - 1) / 2;
    }
    cout << res << '\n';
    return 0;
}