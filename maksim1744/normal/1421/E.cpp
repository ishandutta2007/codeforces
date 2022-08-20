/*
    author:  Maksim1744
    created: 28.10.2020 00:18:13
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

const ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int rem_minus = 0;
    int rem_plus = 0;
    if (n % 3 == 0) {
        rem_minus = 1;
        rem_plus = 2;
    } else if (n % 3 == 1) {
        rem_minus = 0;
        rem_plus = 1;
    } else {
        rem_minus = 2;
        rem_plus = 0;
    }
    vector<int> a(n);
    cin >> a;
    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }
    vector<vector<vector<vector<vector<ll>>>>> dp(n, vector<vector<vector<vector<ll>>>>(3, vector<vector<vector<ll>>>(3, vector<vector<ll>>(2, vector<ll>(2, -inf)))));
    dp[0][1][0][0][0] = -a[0];
    dp[0][0][1][0][1] = a[0];
    for (int i = 1; i < n; ++i) {
        for (int m = 0; m < 3; ++m) {
            for (int p = 0; p < 3; ++p) {
                for (int b = 0; b < 2; ++b) {
                    for (int l = 0; l < 2; ++l) {
                        for (int s = 0; s < 2; ++s) {
                            umax(dp[i][(m + (s == 0)) % 3][(p + (s == 1)) % 3][b || (l == s)][s], dp[i - 1][m][p][b][l] + a[i] * (-1 + s * 2));
                        }
                    }
                }
            }
        }
    }
    ll ans = -inf;
    for (int l = 0; l < 2; ++l) {
        ans = max(ans, dp[n - 1][rem_minus][rem_plus][1][l]);
    }
    cout << ans << '\n';

    return 0;
}