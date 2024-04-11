/*
    author:  Maksim1744
    created: 28.05.2021 03:15:53
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
    vector<ll> a(n);
    cin >> a;
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    dp[1] = a[0];
    for (int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i], dp[i - 2] + a[i - 1]);
        if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + max(a[i - 1], a[i - 2]));
    }
    int x = (dp[n - 1] < dp[n] ? n - 1 : n);
    vector<int> ans;
    while (x > 0) {
        if (x == 1 || dp[x] == dp[x - 2] + a[x - 1]) {
            ans.pb(x - 1);
            ans.pb(x - 2);
            x -= 2;
        } else {
            ans.pb(x - 2);
            ans.pb(x - 1);
            ans.pb(x - 3);
            x -= 3;
        }
    }

    ll s = min(dp[n - 1], dp[n]);
    ll tot = 0;

    vector<int> real_ans;
    for (int k : ans) {
        if (k < 0 || k + 1 >= n) continue;
        ll m = min(a[k], a[k + 1]);
        if (m) real_ans.pb(k);
        tot += m;
        a[k] -= m;
        a[k + 1] -= m;
    }

    assert(s == tot);

    cout << real_ans.size() << '\n';
    for (int k : real_ans) {
        cout << k + 1 << '\n';
    }

    return 0;
}