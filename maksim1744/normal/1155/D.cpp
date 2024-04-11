/*
    author:  Maksim1744
    created: 23.04.2019 16:40:48
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
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    cin >> a;
    vector<ll> s(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
    }
    if (x > 0) {
        ll mn = s[0];
        ll mx = s[1];
        for (int i = 1; i <= n; ++i) {
            mx = max(mx, s[i] - mn);
            mn = min(mn, s[i]);
        }
        cout << max({0ll, mx, mx * x}) << '\n';
    } else {
        ll mn = s[0];
        ll mx = s[1];
        int l = 0, r = 1, imn = 0;
        for (int i = 1; i <= n; ++i) {
            if (mx > s[i] - mn) {
                l = imn;
                r = i;
            }
            if (mn < s[i]) {
                imn = i;
            }
            mx = min(mx, s[i] - mn);
            mn = max(mn, s[i]);
        }
        ll mx1 = -1;
        {
            ll mn = s[0];
            ll mx = s[1];
            for (int i = 1; i <= n; ++i) {
                mx = max(mx, s[i] - mn);
                mn = min(mn, s[i]);
            }
            mx1 = mx;
            mx1 = max(mx1, 0ll);
        }
        // show(s, imn, l, r);
        auto aa = a;
        for (int i = l + 1; i <= r; ++i) {
            a[i - 1] *= x;
        }
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + a[i];
        }
        {
            ll mn = s[0];
            ll mx = s[1];
            for (int i = 1; i <= n; ++i) {
                mx = max(mx, s[i] - mn);
                mn = min(mn, s[i]);
            }
            mx1 = max(mx1, mx);
        }
        a = aa;
        vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(a[i - 1], a[i - 1] + dp[i - 1][0]);
            dp[i][1] = max(a[i - 1] + dp[i - 1][1], a[i - 1] + dp[i - 1][2]);
            dp[i][2] = max(a[i - 1] * x + dp[i - 1][0], a[i - 1] * x + dp[i - 1][2]);
            mx1 = max({mx1, dp[i][0], dp[i][1], dp[i][2]});
        }
        cout << mx1 << '\n';
    }
    return 0;
}