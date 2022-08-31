/*
    author:  Maksim1744
    created: 18.09.2019 19:35:27
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;
    cin >> s;
    --s;
    vector<ll> dp(n, 0);
    vector<char> u(n, false);
    if (n == m + 1) {
        function<void(int)> dfs = [&](int v) {
            u[v] = true;
            for (auto k : g[v]) {
                if (!u[k]) {
                    dfs(k);
                    dp[v] = max(dp[v], dp[k]);
                }
            }
            dp[v] += w[v];
        };
        dfs(s);
        cout << dp[s] << '\n';
        return 0;
    }
    queue<int> leafes;
    vector<char> is_leaf(n, false);
    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
        if (deg[i] == 1) {
            is_leaf[i] = true;
            leafes.push(i);
        }
    }
    int cnt = 0;
    while (!leafes.empty() && cnt < n * 2) {
        ++cnt;
        auto v = leafes.front();
        leafes.pop();
        for (auto k : g[v]) {
            if (!is_leaf[k]) {
                --deg[k];
                if (deg[k] == 1) {
                    leafes.push(k);
                    is_leaf[k] = true;
                }
            }
        }
    }
    ll ans = 0;
    if (is_leaf[s]) {
        vector<int> par(n, -1);
        function<void(int, int)> dfs1 = [&](int v, int p) {
            u[v] = true;
            par[v] = p;
            for (auto k : g[v]) {
                if (!u[k]) {
                    dfs1(k, v);
                }
            }
        };
        dfs1(s, -1);
        for (int i = 0; i < n; ++i) {
            if (!is_leaf[i]) {
                int v = i;
                int cnt = 0;
                while (v != s && cnt < n * 2) {
                    ++cnt;
                    v = par[v];
                    if (is_leaf[v]) {
                        ans += w[v];
                        w[v] = 0;
                    }
                }
                break;
            }
        }
        u.assign(n, false);
    }
    function<void(int)> dfs2 = [&](int v) {
        u[v] = true;
        dp[v] = 0;
        for (auto k : g[v]) {
            if (!u[k] && is_leaf[k]) {
                dfs2(k);
                dp[v] = max(dp[v], dp[k]);
            }
        }
        dp[v] += w[v];
    };
    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_leaf[i]) {
            ans += w[i];
            for (auto k : g[i]) {
                if (!u[k] && is_leaf[k]) {
                    dfs2(k);
                    mx = max(mx, dp[k]);
                }
            }
        }
    }
    cout << ans + mx << '\n';
    return 0;
}