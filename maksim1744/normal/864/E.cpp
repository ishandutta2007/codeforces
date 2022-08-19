/*
    author:  Maksim1744
    created: 05.07.2021 23:24:44
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
    vector<pair<pair<int, pair<int, int>>, int>> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i].first;
        u[i].second = i + 1;
    }
    sort(u.begin(), u.end(), [&](const auto &a, const auto &b) {
        return a.first.second.first < b.first.second.first;
    });;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = u[i].first;
    }

    const int N = 2120;
    vector<vector<int>> dp(n + 1, vector<int>(N, -1e9));
    dp[0][0] = 0;
    vector<vector<int>> fr(n + 1, vector<int>(N, -1));
    int it = 1;
    for (auto [t, d_p] : v) {
        auto [d, p] = d_p;

        dp[it] = dp[it - 1];

        for (int i = 0; i < dp[it].size(); ++i) {
            if (i + t < d) {
                if (dp[it - 1][i] + p > dp[it][i + t]) {
                    dp[it][i + t] = max(dp[it][i + t], dp[it - 1][i] + p);
                    fr[it][i + t] = i;
                }
            }
        }

        ++it;
    }
    cout << maxe(dp.back()) << '\n';

    int cur = maxi(dp.back());
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        if (fr[i][cur] == -1) {
            continue;
        }
        cur = fr[i][cur];
        ans.pb(u[i - 1].second);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int k : ans)
        cout << k << ' ';
    cout << '\n';

    return 0;
}