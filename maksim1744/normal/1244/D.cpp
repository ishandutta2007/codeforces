/*
    author:  Maksim1744
    created: 13.10.2019 12:25:39
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

    int n;
    cin >> n;
    vector<vector<ll>> c(3, vector<ll>(n));
    cin >> c;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<int> path;
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            start = i;
            break;
        }
    }
    path.pb(start);
    vector<bool> u(n, false);
    u[start] = true;
    for (int i = 0; i < n - 1; ++i) {
        for (auto k : g[start]) {
            if (!u[k]) {
                path.pb(k);
                u[k] = true;
                start = k;
            }
        }
    }
    show(path);
    vector<pair<int, int>> check = {
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 2},
        {2, 0},
        {2, 1}
    };
    ll res = 1e18;
    pair<int, int> cres;
    for (auto [c0, c1] : check) {
        auto p = mp(c0, c1);
        ll sm = c[c0][path[0]] + c[c1][path[1]];
        for (int i = 2; i < n; ++i) {
            int c2 = 3 - c0 - c1;
            sm += c[c2][path[i]];
            c0 = c1;
            c1 = c2;
        }
        if (sm < res) {
            res = sm;
            cres = p;
        }
    }
    vector<int> ans(n);
    auto [c0, c1] = cres;
    ans[path[0]] = c0;
    ans[path[1]] = c1;
    // cout << c0 + 1 << ' ' << c1 + 1 << ' ';
    for (int i = 2; i < n; ++i) {
        int c2 = 3 - c0 - c1;
        ans[path[i]] = c2;
        c0 = c1;
        c1 = c2;
    }
    ++ans;
    cout << res << '\n';
    cout << ans << '\n';
    // cout << '\n';
    return 0;
}