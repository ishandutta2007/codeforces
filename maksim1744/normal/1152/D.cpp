/*
    author:  Maksim1744
    created: 24.04.2019 20:07:59
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

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(n + 2, vector<ll>(2, 0)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j][0] = dp[i - 1][j + 1][1] + 1;
                dp[i][j][1] = dp[i - 1][j + 1][0];
            } else if (j == i) {
                dp[i][j][0] = dp[i - 1][j - 1][1] + 1;
                dp[i][j][1] = dp[i - 1][j - 1][0];
            } else {
                dp[i][j][0] = (dp[i - 1][j - 1][0] + dp[i - 1][j + 1][1] + 1) % mod;
                dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j + 1][0]) % mod;
            }
        }
    }
    cout << dp[n][0][0] % mod << '\n';
    return 0;
}