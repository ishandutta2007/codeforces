/*
    author:  Maksim1744
    created: 28.10.2020 21:25:35
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
    vector<ll> t(n);
    cin >> t;
    vector<int> h(n);
    cin >> h;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<ll>> dp(n, vector<ll>(2, 1e18));
    vector<bool> u(n, false);
    function<void(int, int)> dfs = [&](int v, int p) {
        u[v] = true;
        vector<int> ch;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k, v);
                ch.pb(k);
            }
        }
        ll cur_up = 0;
        ll cur_down = 0;
        ll ans = 0;
        vector<ll> eq_now_down;
        vector<ll> eq_now_up;
        for (auto k : ch) {
            // show(v, k, dp[k], h[v], h[k]);
            if (dp[k][0] < dp[k][1]) {
                ++cur_down;
                assert(h[v] <= h[k]);
                if (h[k] == h[v]) {
                    eq_now_down.pb(dp[k][1] - dp[k][0]);
                }
            } else {
                ++cur_up;
                assert(h[v] >= h[k]);
                if (h[k] == h[v]) {
                    eq_now_up.pb(dp[k][0] - dp[k][1]);
                }
            }
            ans += mine(dp[k]);
        }
        auto ans0 = ans;
        auto eq_now_up0 = eq_now_up;
        auto eq_now_down0 = eq_now_down;
        auto cur_down0 = cur_down;
        auto cur_up0 = cur_up;
        if (p == -1 || h[p] <= h[v]) {
            sort(eq_now_up.rbegin(), eq_now_up.rend());
            sort(eq_now_down.rbegin(), eq_now_down.rend());
            if (p != -1)
                cur_up++;
            dp[v][0] = min(dp[v][0], ans + max(cur_up, cur_down) * t[v]);
            while (cur_up > cur_down && !eq_now_up.empty()) {
                ans += eq_now_up.back();
                --cur_up;
                ++cur_down;
                eq_now_up.pop_back();
                dp[v][0] = min(dp[v][0], ans + max(cur_up, cur_down) * t[v]);
            }
            while (cur_up < cur_down && !eq_now_down.empty()) {
                ans += eq_now_down.back();
                ++cur_up;
                --cur_down;
                eq_now_down.pop_back();
                dp[v][0] = min(dp[v][0], ans + max(cur_up, cur_down) * t[v]);
            }
        }
        ans = ans0;
        eq_now_up = eq_now_up0;
        eq_now_down = eq_now_down0;
        cur_down = cur_down0;
        cur_up = cur_up0;
        if (p == -1 || h[p] >= h[v]) {
            sort(eq_now_up.rbegin(), eq_now_up.rend());
            sort(eq_now_down.rbegin(), eq_now_down.rend());
            if (p != -1)
                cur_down++;
            dp[v][1] = min(dp[v][1], ans + max(cur_up, cur_down) * t[v]);
            while (cur_up > cur_down && !eq_now_up.empty()) {
                ans += eq_now_up.back();
                --cur_up;
                ++cur_down;
                eq_now_up.pop_back();
                dp[v][1] = min(dp[v][1], ans + max(cur_up, cur_down) * t[v]);
            }
            while (cur_up < cur_down && !eq_now_down.empty()) {
                ans += eq_now_down.back();
                ++cur_up;
                --cur_down;
                eq_now_down.pop_back();
                dp[v][1] = min(dp[v][1], ans + max(cur_up, cur_down) * t[v]);
            }
        }
    };
    dfs(0, -1);
    show(dp);
    cout << mine(dp[0]) << '\n';

    return 0;
}