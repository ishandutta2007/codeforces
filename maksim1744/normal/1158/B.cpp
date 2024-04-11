/*
    author:  Maksim1744
    created: 12.05.2019 17:55:29
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
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

int main() {
    int n, k;
    cin >> n >> k;
    // if ((n - k) / 2 > (k - 1)) {
    //     string tmp = string((n - k) / 2 - (k - 1), '1') + string(k - 1, '0');
    //     string s = string(k, '0') + tmp + tmp;
    //     cout << s << '\n';
    //     return 0;
    // }
    if (n == k) {
        cout << string(n, '0') << '\n';
        return 0;
    }
    // if (k == 2) {
    //     cout << string(n / 2, '0') + string(n / 2, '1') << '\n';
    //     return 0;
    // }
    if (n * 2 % (n - k + 2) == 0) {
        int t = n * 2 / (n - k + 2);
        int p = n / t;
        assert(p * t == n);
        if (p == 2) {
            string y = "01";
            for (int i = 0; i < n / 2; ++i) {
                cout << y;
            }
            cout << '\n';
            // for (int i = 0; i < (1 << n); ++i) {
            //     string tr;
            //     for (int j = 0; j < n; ++j) {
            //         tr.pb('0' + ((i >> j) & 1));
            //     }
            //     int mn = n;
            //     map<string, int> y;
            //     for (int j = 0; j < n; ++j) {
            //         for (int k = 1; k < n; ++k) {
            //             if (j + k <= n) {
            //                 y[tr.substr(j, k)]++;
            //             }
            //         }
            //     }
            //     for (auto p : y) {
            //         if (p.second == 1 && p.first.size() < mn)
            //             mn = p.first.size();
            //     }
            //     if (mn == k) {
            //         show(y);
            //         cout << tr << '\n';
            //         break;
            //     }
            // }
        } else {
            string e = string(p, '0');
            e.back() = '1';
            e[0] = '1';
            for (int i = 0; i < t; ++i) {
                cout << e;
            }
            cout << '\n';
        }
        return 0;
    }
    int a = n * 2 / (n - k + 2) + 1;
    int x = n - (a - 1) * (n - k + 2) / 2;
    int y = (n - k + 2) / 2 - x;
    assert(x > 0);
    assert(y > 0);
    string sx = string(x, '1');
    string sy = string(y, '0');
    string s;
    for (int i = 0; i < a - 1; ++i) {
        s += sx + sy;
    }
    s += sx;
    cout << s << '\n';
    return 0;
}