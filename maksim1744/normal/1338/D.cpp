/*
    author:  Maksim1744
    created: 12.04.2020 18:00:23
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

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<bool> u(n, false);
    int ans = 0;
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        vector<int> ch;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
                ch.pb(k);
            }
        }
        if (ch.empty()) {
            dp[v] = {0, 1};
            ans = max(ans, 1);
            return;
        }
        for (auto k : ch) {
            dp[v][0] = max(dp[v][0], maxe(dp[k]));
            dp[v][1] = max(dp[v][1],  dp[k][0] + 1);
        }
        dp[v][0] += ch.size() - 1;
        ans = max(ans, dp[v][0] + (v != 0));
        ans = max(ans, dp[v][1]);
        if (ch.size() >= 2) {
            int mx1 = 0, mx2 = 0;
            for (auto k : ch) {
                int c = dp[k][0];
                if (c >= mx1) {
                    mx2 = mx1;
                    mx1 = c;
                } else if (c > mx2) {
                    mx2 = c;
                }
            }
            ans = max(ans, mx1 + mx2 + 1);
            mx1 = 0; mx2 = 0;
            for (auto k : ch) {
                int c = maxe(dp[k]);
                if (c >= mx1) {
                    mx2 = mx1;
                    mx1 = c;
                } else if (c > mx2) {
                    mx2 = c;
                }
            }
            ans = max(ans, mx1 + mx2 + (int)(ch.size() - 2) + (v != 0));
        }
    };
    dfs(0);
    // update from 0
    cout << ans << '\n';

    return 0;
}