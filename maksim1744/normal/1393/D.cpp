/*
    author:  Maksim1744
    created: 07.08.2020 17:55:50
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

int n, m;
vector<vector<int>> calc(vector<string>& v) {
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int mx = 1e9;
            if (i != 0 && v[i][j] == v[i - 1][j]) mx = min(mx, dp[i - 1][j]);
            else mx = 0;
            if (j != 0 && v[i][j] == v[i][j - 1]) mx = min(mx, dp[i][j - 1]);
            else mx = 0;

            dp[i][j] = mx + 1;
        }
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    vector<string> f(n);
    cin >> f;

    auto d = calc(f);
    printMatrix(d);
    shows;
    for (int i = 0; i < n; ++i) {
        reverse(f[i].begin(), f[i].end());
    }
    auto d2 = calc(f);
    for (int i = 0; i < n; ++i) {
        reverse(f[i].begin(), f[i].end());
    }
    for (int i = 0; i < n; ++i) {
        reverse(d2[i].begin(), d2[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = min(d[i][j], d2[i][j]);
        }
    }

    reverse(f.begin(), f.end());
    d2 = calc(f);
    reverse(d2.begin(), d2.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = min(d[i][j], d2[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        reverse(f[i].begin(), f[i].end());
    }
    d2 = calc(f);
    reverse(d2.begin(), d2.end());
    for (int i = 0; i < n; ++i) {
        reverse(d2[i].begin(), d2[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = min(d[i][j], d2[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += d[i][j];
        }
    }
    printMatrix(d);
    cout << ans << endl;

    return 0;
}