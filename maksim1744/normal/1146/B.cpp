/*
    author:  Maksim1744
    created: 20.04.2019 21:08:32
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
    string t;
    cin >> t;
    int a = 0;
    for (auto c : t) {
        if (c == 'a') ++a;
    }
    int n = t.size();
    int sn = n - a;
    if (sn % 2 == 1) {
        cout << ":(" << '\n';
        return 0;
    }
    sn /= 2;
    string s = t.substr(sn + a, sn);
    string s1 = "";
    for (int i = 0; i < sn + a; ++i) {
        if (t[i] == 'a')
            continue;
        s1.pb(t[i]);
    }
    if (s1 == s && count(s.begin(), s.end(), 'a') == 0) {
        cout << t.substr(0, sn + a) << '\n';
    } else {
        cout << ":(" << '\n';
    }
    return 0;
}