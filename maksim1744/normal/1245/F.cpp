/*
    author:  Maksim1744
    created: 01.11.2019 18:27:05
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
const int K = 64;
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
const int K = 64;
#endif

const ll mod = 1e18 + 1;

int main() {
    int T;
    cin >> T;
    vector<vector<ll>> dp(K, vector<ll>(K));
    auto calc = [&](ll a, ll b) -> ll {
        if (a == -1 || b == -1)
            return 0;
        if (a & b)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                if (i == 0 && j == 0)
                    continue;
                int c1 = (a & (1ll << (i - 1)));
                int c2 = (b & (1ll << (j - 1)));
                if (i != 0 && c1 == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j != 0 && c2 == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    ll a0 = a - (a & ((1ll << (i)) - 1));
                    ll b0 = b - (b & ((1ll << (j)) - 1));
                    if (i == 0) {
                        ll n0 = 1;
                        for (int k = 0; k < j - 1; ++k) {
                            if ((a & (1ll << k)) == 0) {
                                n0 <<= 1;
                                n0 %= mod;
                            }
                        }
                        if ((a0 & b0) != 0)
                            n0 = 0;
                        dp[i][j] = dp[i][j - 1] + n0;
                        dp[i][j] %= mod;
                    } else if (j == 0) {
                        ll n0 = 1;
                        for (int k = 0; k < i - 1; ++k) {
                            if ((b & (1ll << k)) == 0)
                                n0 <<= 1;
                        }
                        if ((a0 & b0) != 0)
                            n0 = 0;
                        dp[i][j] = dp[i - 1][j] + n0;
                        dp[i][j] %= mod;
                    } else {
                        ll sth = 0;
                        int i0 = i, j0 = j;
                        if (i0 > j0) {
                            swap(i0, j0);
                            swap(a0, b0);
                        }
                        ll n0 = 1;
                        for (int u = 0; u < i0 - 1; ++u) {
                            n0 = n0 * 3 % mod;
                        }
                        for (int u = i0 - 1;  u < j0 - 1; ++u) {
                            if ((a0 & (1ll << u)) == 0) {
                                n0 = n0 * 2 % mod;
                            }
                        }
                        if ((a0 & b0) != 0)
                            n0 = 0;
                        dp[i][j] = (i == 0 ? 0ll : dp[i - 1][j]) + (j == 0 ? 0ll : dp[i][j - 1])
                                                        - (i == 0 || j == 0 ? 0ll : dp[i - 1][j - 1]) + n0;
                        dp[i][j] = (dp[i][j] % mod + mod) % mod;
                    }
                }
            }
        }
        return dp.back().back();
    };
    while (T--) {
        ll l, r;
        cin >> l >> r;
        auto rr = calc(r, r);
        // printMatrix(dp);
        auto lr = calc(l - 1, r);
        auto ll_ = calc(l - 1, l - 1);
        // show(rr, lr, ll_);
        ll ans = rr - lr * 2 + ll_;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}