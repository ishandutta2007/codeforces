/*
    author:  Maksim1744
    created: 23.04.2019 16:27:57
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i1 = 0, i2 = 0;
    vector<bool> u(n * 5, false);
    while (i1 < n && s[i1] == '8')
        ++i1;
    while (i2 < n && s[i2] != '8')
        ++i2;
    for (int i = 0; i < (n - 11) / 2; ++i) {
        u[i1++] = true;
        u[i2++] = true;
        while (i1 < n && (s[i1] == '8' || u[i1]))
            ++i1;
        while (i2 < n && (s[i2] != '8' || u[i2]))
            ++i2;
    }
    for (int i = 0; i < n; ++i) {
        if (!u[i]) {
            if (s[i] == '8')
                cout << "YES\n";
            else
                cout << "NO\n";
            return 0;
        }
    }
    return 0;
}