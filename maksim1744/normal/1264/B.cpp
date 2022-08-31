/*
    author:  Maksim1744
    created: 05.12.2019 17:47:51
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

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (abs(a + c - (b + d)) > 1) {
        cout << "NO\n";
        return 0;
    }
    if (a > b) {
        if (c == 0 && d == 0 && a == b + 1) {
            cout << "YES\n";
            for (int i = 0; i < b; ++i) {
                cout << "0 1 ";
            }
            cout << 0 << '\n';
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    if (d > c) {
        if (a == 0 && b == 0 && d == c + 1) {
            cout << "YES\n";
            for (int i = 0; i < c; ++i) {
                cout << "3 2 ";
            }
            cout << 3 << '\n';
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    if (a == b) {
        vector<int> ans;
        for (int i = 0; i < a; ++i) {
            ans.pb(0);
            ans.pb(1);
        }
        if (c == d) {
            for (int i = 0; i < c; ++i) {
                ans.pb(2);
                ans.pb(3);
            }
        } else if (c == d + 1) {
            for (int i = 0; i < d; ++i) {
                ans.pb(2);
                ans.pb(3);
            }
            ans.pb(2);
        } else {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        cout << ans << '\n';
        return 0;
    }
    if (c == d) {
        vector<int> ans;
        for (int i = 0; i < c; ++i) {
            ans.pb(3);
            ans.pb(2);
        }
        if (a == b) {
            for (int i = 0; i < a; ++i) {
                ans.pb(1);
                ans.pb(0);
            }
        } else if (b == a + 1) {
            for (int i = 0; i < a; ++i) {
                ans.pb(1);
                ans.pb(0);
            }
            ans.pb(1);
        } else {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        cout << ans << '\n';
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < a; ++i) {
        ans.pb(0);
        ans.pb(1);
    }
    b -= a;
    a = 0;
    vector<int> ans2;
    for (int i = 0; i < d; ++i) {
        ans2.pb(2);
        ans2.pb(3);
    }
    c -= d;
    d = 0;
    int k = min(b, c);
    for (int i = 0; i < k; ++i) {
        ans.pb(2);
        ans.pb(1);
    }
    b -= k;
    c -= k;
    if (b != 0) {
        ans.insert(ans.begin(), 1);
        --b;
    }
    if (c != 0) {
        ans2.pb(2);
        --c;
    }
    if (b != 0 || c != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans << ans2 << '\n';
    }
    return 0;
}