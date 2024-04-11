/*
    author:  Maksim1744
    created: 19.06.2019 18:52:43
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int T;
    cin >> T;
    vector<pair<int, int>> v(n);
    cin >> v;
    ll dp[n + 1][n + 1][n + 1][3];
    for (int i = 0; i < 3; ++i) {
        dp[1][0][0][i] = 0;
        dp[0][1][0][i] = 0;
        dp[0][0][1][i] = 0;
    }
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            for (int k = 0; k < n + 1; ++k) {
                if (i + j + k <= 1)
                    continue;
                for (int x = 0; x < 3; ++x) {
                    dp[i][j][k][x] = 0;
                }
                if (i > 0)
                    dp[i][j][k][0] = dp[i - 1][j][k][1] + dp[i - 1][j][k][2];
                if (j > 0)
                    dp[i][j][k][1] = dp[i][j - 1][k][0] + dp[i][j - 1][k][2];
                if (k > 0)
                    dp[i][j][k][2] = dp[i][j][k - 1][0] + dp[i][j][k - 1][1];
                for (int x = 0; x < 3; ++x) {
                    dp[i][j][k][x] %= mod;
                }
            }
        }
    }
    vector<ll> f(n + 5, 1);
    for (int i = 2; i <= n; ++i)
        f[i] = f[i - 1] * i % mod;
    ll ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int t = 0;
        vector<int> g(4, 0);
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                t += v[j].first;
                g[v[j].second]++;
            }
        }
        if (t != T)
            continue;
        for (int x = 0; x < 3; ++x) {
            show(g, x, dp[g[1]][g[2]][g[3]][x]);
            ans += dp[g[1]][g[2]][g[3]][x] * f[g[1]] % mod * f[g[2]] % mod * f[g[3]] % mod;
        }
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}