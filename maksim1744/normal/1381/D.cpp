/*
    author:  Maksim1744
    created: 21.07.2020 18:48:57
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

void test_case() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    --a; --b;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n, -1);
    function<void(int, int)> dfs1 = [&](int v, int p) {
        par[v] = p;
        for (auto k : g[v]) {
            if (k != p) {
                dfs1(k, v);
            }
        }
    };
    dfs1(a, -1);
    vector<int> snake;
    int v = b;
    while (v != -1) {
        snake.pb(v);
        v = par[v];
    }
    vector<vector<int>> tails(snake.size());
    function<int(int, int)> dfs2 = [&](int v, int p) {
        int res = 1;
        for (auto k : g[v]) {
            if (k != p) {
                res = max(res, dfs2(k, v) + 1);
            }
        }
        return res;
    };
    vector<bool> u(n, false);
    for (auto k : snake) {
        u[k] = true;
    }
    for (int i = 0; i < snake.size(); ++i) {
        int v = snake[i];
        for (auto k : g[v]) {
            if (!u[k]) {
                tails[i].pb(dfs2(k, v));
            }
        }
    }
    vector<int> longest(snake.size(), 0);
    for (int i = 0; i < snake.size(); ++i) {
        if (!tails[i].empty()) {
            longest[i] = maxe(tails[i]);
        }
        longest[i] = min(longest[i], (int)snake.size() - 1);
    }
    vector<int> rmax = longest;
    vector<int> lmax = longest;
    for (int i = 0; i < snake.size(); ++i) {
        rmax[i] += i + 1;
        lmax[snake.size() - i - 1] += i + 1;
    }
    for (int i = (int)snake.size() - 2; i >= 0; --i) {
        rmax[i] = max(rmax[i], rmax[i + 1]);
    }
    for (int i = 1; i < snake.size(); ++i) {
        lmax[i] = max(lmax[i], lmax[i - 1]);
    }
    int l = 0, r = snake.size() - 1;
    while (true) {
        int lprev = l, rprev = r;

        int ldist = lmax[l];
        ldist -= snake.size();
        r = min(r, (int)snake.size() - 1 - ldist);

        int rdist = rmax[r];
        rdist -= snake.size();
        l = max(l, rdist);

        if (lprev == l && rprev == r) break;
    }
    vector<pair<int, int>> dp(n, {0, 0});
    function<void(int, int)> dfs3 = [&](int v, int p) {
        dp[v] = {0, 0};
        for (auto k : g[v]) {
            if (u[k] || k == p) continue;
            dfs3(k, v);
            int ln = dp[k].first + 1;
            if (ln >= dp[v].first) {
                dp[v].second = dp[v].first;
                dp[v].first = ln;
            } else if (ln > dp[v].second) {
                dp[v].second = ln;
            }
        }
    };
    dfs3(snake[0], -1);
    dfs3(snake.back(), -1);
    for (int i = 1; i + 1 < snake.size(); ++i) {
        if (i > l && i < r) continue;
        if (longest[i] >= snake.size() - 1) {
            if (rmax[i + 1] >= i + snake.size() && lmax[i - 1] >= snake.size() - 1 - i + snake.size()) {
                cout << "YES\n";
                return;
            }
        }
        dfs3(snake[i], -1);
    }
    show(snake);
    show(l, r);
    show(longest);
    show(dp);
    for (int i = 0; i < n; ++i) {
        if (dp[i].second >= snake.size() - 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}