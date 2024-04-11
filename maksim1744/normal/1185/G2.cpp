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
const int maxn = 55, maxt = 2505;

array<array<array<ll, maxt>, maxn>, maxn> dp2, dp3, dpmid;

int main() {
    auto tt = clock();
    show("here9");
    int n;
    cin >> n;
    int T;
    cin >> T;
    show("here8");
    vector<pair<int, int>> v(n);
    cin >> v;
    show("here6");
    vector<vector<vector<vector<ll>>>> dp(n+1, vector<vector<vector<ll>>>(n+1, vector<vector<ll>>(n+1, vector<ll>(3, 0))));
    show("here5");
    for (int i = 0; i < 3; ++i) {
        dp[1][0][0][i] = 0;
        dp[0][1][0][i] = 0;
        dp[0][0][1][i] = 0;
    }
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    dp[0][0][1][2] = 1;
    show("here4");
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
    show("here3");
    vector<ll> f(n + 25, 1);
    for (int i = 2; i <= n; ++i)
        f[i] = f[i - 1] * i % mod;
    ll ans = 0;
    vector<vector<int>> byt(3);
    for (int i = 0; i < n; ++i) {
        byt[v[i].second - 1].pb(v[i].first);
    }
    show("here2");
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int u = 0; u < maxt; ++u) {
                dp2[i][j][u] = 0;
                dp3[i][j][u] = 0;
                dpmid[i][j][u] = 0;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        dp3[i][0][0] = 1;
        for (int j = 0; j < byt[i].size(); ++j) {
            for (int k = n; k >= 0; --k) {
                for (int u = T; u >= 0; --u) {
                    dp3[i][k][u] = (dp3[i][k][u] + (u >= byt[i][j] && k >= 1 ? dp3[i][k - 1][u - byt[i][j]] : 0ll)) % mod;
                }
            }
        }
    }
    dp2[0][0][0] = 1;
    show("here1", v);
    for (int o = 0; o < n; ++o) {
        if (v[o].second == 3)
            continue;
        if (v[o].second == 2) {
            for (int i = n; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    for (int u = T; u >= 0; --u) {
                        if (j > 0 && u >= v[o].first)
                            dp2[i][j][u] += dp2[i][j - 1][u - v[o].first];
                        dp2[i][j][u] %= mod;
                    }
                }
            }
        } else {
            for (int i = n; i >= 0; --i) {
                for (int j = n; j >= 0; --j) {
                    for (int u = T; u >= 0; --u) {
                        if (i > 0 && u >= v[o].first)
                            dp2[i][j][u] += dp2[i - 1][j][u - v[o].first];
                        dp2[i][j][u] %= mod;
                    }
                }
            }
        }
    }
    show("here0");
    show("here1");
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; i + j < n + 1; ++j) {
            for (int k = 0; i + j + k < n + 1; ++k) {
                if (i + j + k == 0)
                    continue;
                ll sm = (dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2]) % mod;
                if (sm == 0)
                    continue;
                for (int u = 0; u < T + 1; ++u) {
                    ans += dp3[2][k][u] * dp2[i][j][T - u] % mod * f[i] % mod * f[j] % mod * f[k] % mod * sm % mod;
                    if (ans >= mod)
                        ans %= mod;
                }
            }
        }
    }
    show("here2");
    // for (int i = 0; i < (1 << n); ++i) {
    //     int t = 0;
    //     vector<int> g(4, 0);
    //     for (int j = 0; j < n; ++j) {
    //         if (i & (1 << j)) {
    //             t += v[j].first;
    //             g[v[j].second]++;
    //         }
    //     }
    //     if (t != T)
    //         continue;
    //     for (int x = 0; x < 3; ++x) {
    //         show(g, x, dp[g[1]][g[2]][g[3]][x]);
    //         ans += dp[g[1]][g[2]][g[3]][x] * f[g[1]] % mod * f[g[2]] % mod * f[g[3]] % mod;
    //     }
    //     ans %= mod;
    // }
    cout << ans << '\n';
    ld time = (ld)(clock() - tt) / CLOCKS_PER_SEC;
    show(time);
    return 0;
}