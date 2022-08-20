/*
    author:  Maksim1744
    created: 22.05.2021 12:37:53
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> s(n);
    cin >> s;
    sort(s.begin(), s.end());
    vector<vector<ll>> mn(n, vector<ll>(n, 2e9));
    vector<vector<ll>> mx(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        mn[i][i] = mx[i][i] = s[i];
        for (int j = i + 1; j < n; ++j) {
            mn[i][j] = min(mn[i][j - 1], s[j]);
            mx[i][j] = max(mx[i][j - 1], s[j]);
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    for (int ln = 2; ln <= n; ++ln) {
        for (int l = 0; l < n; ++l) {
            int r = l + ln - 1;
            if (r >= n) break;
            dp[l][r] = min(dp[l + 1][r] + mx[l + 1][r] - mn[l][r], dp[l][r - 1] + mx[l][r] - mn[l][r - 1]);
        }
    }
    cout << dp[0][n - 1] << '\n';

    return 0;
}