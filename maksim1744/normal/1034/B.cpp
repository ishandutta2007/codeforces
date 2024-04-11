/*
    author:  Maksim1744
    created: 03.05.2019 16:02:21
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
    ll n, m;
    cin >> n >> m;
    ll a = n % 6, b = m % 6;
    ll ans = (n * m - a * b);
    if (n % 6 == 0 || m % 6 == 0) {
        cout << n * m << '\n';
        return 0;
    } else if (n % 2 == 0 || m % 2 == 0) {
        if (n % 2 == 0 && m % 4 == 0 || n % 4 == 0 && m % 2 == 0) {
            cout << m * n << '\n';
            return 0;
        }
        if (n % 2 == 0 && m % 5 == 0 || n % 5 == 0 && m % 2 == 0) {
            cout << m * n << '\n';
            return 0;
        }
        if (m % 2 == 0) {
            swap(n, m);
            swap(a, b);
        }
        if (m == 1)
            cout << n / 6 * 6 + 2 * (n % 6 >= 4) + 2 * (n % 6 >= 5) << '\n';
        else if (m == 2)
            if (n == 2)
                cout << 0 << '\n';
            else
                cout << n * m << '\n';
        else if (m == 3)
            if (n == 2)
                cout << 4 << '\n';
            else
                cout << n * m << '\n';
        else if (m == 7)
            if (n == 2)
                cout << 12 << '\n';
            else
                cout << n * m << '\n';
        else if (m == 11)
            if (n == 2)
                cout << 22 << '\n';
            else
                cout << n * m << '\n';
        else
            cout << n * m << '\n';
    } else {
        if (n % 5 == 0 || m % 5 == 0) {
            cout << m * n - 1 << '\n';
            return 0;
        }
        // if (n % 3 == 0 || m % 3 == 0) {
        //     cout << m * n 
        // }
        if (n == 1 || m == 1) {
            n *= m;
            cout << n / 6 * 6 + 2 * (n % 6 >= 4) + 2 * (n % 6 >= 5) << '\n';
            return 0;
        } else {
            cout << m * n - 1 << '\n';
        }
        // } else {
        //     if (a > b)
        //         swap(a, b);
        //     if (a == 0)
        //         cout << ans << '\n';
        //     else if (a == 1)
        //         cout << ans + 2 * (b >= 4) << '\n';
        //     else if (a == 2)
        //         if (b == 2)
        //             cout << ans << '\n';
        //         else if (b == 3)
        //             cout << ans + 4 << '\n';
        //         else
        //             cout << ans + b * a << '\n';
        //     else if (a == 3)
        //         if (b == 3)
        //             cout << ans + 8 << '\n';
        //         else if (b == 4)
        //             cout << ans + 12 << '\n';
        //         else if (b == 5)
        //             cout << ans + 14 << '\n';
        //     else if (a == 4)
        //         cout << ans + a * b << '\n';
        //     else
        //         cout << ans + 24 << '\n';
        // }
    }
    return 0;
}