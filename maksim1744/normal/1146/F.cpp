/*
    author:  Maksim1744
    created: 10.05.2019 14:33:34
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

const ll mod = 998244353;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i + 1);
    }
    ll i2 = mpow(2, mod - 2);
    function<void(int)> dfs = [&](int v) {
        if (g[v].size() == 0) {
            dp[v][2] = 1;
            return;
        }
        for (auto u : g[v])
            dfs(u);
        dp[v][0] = 1;
        for (auto u : g[v])
            dp[v][0] = dp[v][0] * (dp[u][0] + dp[u][2]) % mod;
        for (auto u : g[v])
            dp[v][1] += dp[v][0] * (dp[u][1] + dp[u][2]) % mod * mpow(dp[u][0] + dp[u][2], mod - 2) % mod;
        dp[v][1] %= mod;
        dp[v][2] = 1;
        for (auto u : g[v])
            dp[v][2] = dp[v][2] * (dp[u][0] + dp[u][2]) % mod + dp[v][2] * (dp[u][1] + dp[u][2]) % mod;
        dp[v][2] = (dp[v][2] - dp[v][0] - dp[v][1] + mod * 2) % mod;
        // if (g[v].size() == 1)
        //     dp[v][2] = 0;
        // for (auto u : g[v]) {
        //     dp[v][2] = dp[v][2] * (dp[u][0] + dp[u][1] + dp[u][2]) % mod;
        //     p1 = p1 * dp[u][0] % mod;
        // }
        // ll p2 = 0;
        // if (p1 > 0)
        //     for (auto u : g[v])
        //         p2 += p1 * mpow(dp[u][0], mod - 2) % mod * (dp[u][1] + dp[u][2]) % mod;
        // show(dp[v][2], p1, p2);
        // dp[v][2] = (dp[v][2] - p1 - p2 % mod + mod * 2) % mod;
    };
    printTree(g);
    dfs(0);
    show(dp);
    cout << (dp[0][0] + dp[0][2]) % mod << '\n';
    return 0;
}