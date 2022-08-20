/*
    author:  Maksim1744
    created: 20.07.2019 19:18:54
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
// #include "C:/C++ libs/print.cpp"
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

const ll mod = 998244353;
const int N = 20;

int main() {
    // // int n, m;
    // // cin >> n >> m;
    // vector<ll> dp(N, 0);
    // dp[0] = 1;
    // vector<vector<ll>> c(N, vector<ll>(N, 0));
    // for (int i = 0; i < N; ++i) {
    //     c[0][i] = 0;
    //     c[i][0] = 1;
    // }
    // for (int i = 1; i < N; ++i) {
    //     for (int j = 1; j < N; ++j) {
    //         c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    //     }
    // }
    // for (int n = 1; n < N; ++n) {
    //     for (int j = 0; j < n; ++j) {
    //         for (int l = 0; l <= j; ++l) {
    //             for (int r = j; r < n; ++r) {
    //                 int n1 = l, n2 = j - l, n3 = r - j, n4 = n - 1 - r;
    //                 dp[n] += dp[n1] * dp[n2] % mod * dp[n3] % mod * dp[n4] % mod * c[n - 1][n1] % mod * c[n - 1 - n1][n2] % mod
    //                     * c[n - 1 - n1 - n2][n3] % mod;
    //                 dp[n] %= mod;
    //             }
    //         }
    //     }
    //     cerr << n << endl;
    // }
    // cout << dp << '\n';
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> imn(n, vector<int>(n));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<vector<ll>> dps(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        imn[i][i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[imn[i][j - 1]])
                imn[i][j] = j;
            else
                imn[i][j] = imn[i][j - 1];
        }
    }
    // vector<vector<vector<ll>>> dps(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
    for (int i = 0; i < n - 1; ++i) {
        dp[i + 1][i] = 1;
        dps[i + 1][i] = 1;
    }
    for (int ln = 0; ln < n; ++ln) {
        for (int l = 0; l + ln < n; ++l) {
            int r = l + ln;
            dp[l][r] = 0;
            // for (int k = l; k <= r; ++k) {
            int k = imn[l][r];
                if (k == 0)
                    dp[l][r] += dps[k + 1][r] % mod;
                else if (k + 1 == n)
                    dp[l][r] += dps[l][k - 1] % mod;
                else
                    dp[l][r] += dps[l][k - 1] * dps[k + 1][r] % mod;
                dp[l][r] %= mod;
            // }
        }
        for (int l = 0; l + ln < n; ++l) {
            int r = l + ln;
            dps[l][r] = 0;
            for (int k = l - 1; k <= r; ++k) {
                if (k == -1)
                    dps[l][r] += dp[k + 1][r] % mod;
                else if (k + 1 == n)
                    dps[l][r] += dp[l][k] % mod;
                else
                    dps[l][r] += dp[l][k] * dp[k + 1][r] % mod;
                dps[l][r] %= mod;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dps[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    cout << dp[0][n - 1] << '\n';
    return 0;
}