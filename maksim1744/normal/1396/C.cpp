/*
    author:  Maksim1744
    created: 30.08.2020 18:42:18
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    ll r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    ll d;
    cin >> d;
    vector<ll> a(n);
    cin >> a;
    vector<ll> full(n), part(n);
    r1 = min(r1, r3);
    for (int i = 0; i < n; ++i) {
        part[i] = min(r1 * (a[i] + 1), r2) + min({r1, r2, r3});
        full[i] = r1 * a[i] + r3;

        part[i] = min(part[i], full[i]);
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 2e18));
    dp[0][0] = full[0];
    dp[0][1] = part[0] + d * 2;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = mine(dp[i - 1]) + full[i];
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + part[i]);

        dp[i][1] = dp[i - 1][0] + part[i] + d * 2;
    }
    vector<ll> sufs = part;
    sufs.back() = min(full.back(), part.back() + d * 2);
    for (int i = n - 2; i >= 0; --i)
        sufs[i] += sufs[i + 1];

    // show(part);
    // show(sufs);
    // show(full);
    // show(part);

    ll ans = dp.back()[0] + d * (n - 1);
    // printMatrix(dp);
    // show(ans);
    for (int k = 0; k < n; ++k) {
        ll last = 0;
        if (k != 0) {
            last = dp[k - 1][0];
        }
        ans = min(ans, d * (n - 1) + d * (n - 1 - k) + last + sufs[k]);
        // if (ans == 35) {
        //     show(k);
        // }
    }
    cout << ans << '\n';

    return 0;
}