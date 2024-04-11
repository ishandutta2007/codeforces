/*
    author:  Maksim1744
    created: 05.11.2019 22:26:24
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
    int n;
    cin >> n;
    vector<set<int>> g0(n);
    vector<set<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        g0[p].insert(i + 1);
    }
    vector<int> sz(n, 0);
    vector<int> h(n, 0);
    function<void(int)> dfs = [&](int v) {
        sz[v] = 1;
        h[v] = 0;
        for (auto u : g0[v]) {
            dfs(u);
            sz[v] += sz[u];
            h[v] = max(h[v], h[u]);
        }
        ++h[v];
    };
    dfs(0);
    for (int i = 0; i < n; ++i) {
        for (auto u : g0[i]) {
            g[i].emplace(-h[u], u);
        }
    }
    int cur = 0;
    vector<int> ans;
    while (true) {
        // show(cur);
        // show(g);
        if (g[cur].size() == 0)
            break;
        if (g[cur].size() == 1) {
            cur = g[cur].begin()->second;
            continue;
        }
        auto it = g[cur].begin();
        int k1 = it->second;
        ++it;
        int k2 = it->second;
        ans.pb(k1);
        int y = g[cur].size();
        g[k2].emplace(-h[k1], k1);
        g[cur].erase(mp(-h[k1], k1));
        g[cur].erase(mp(-h[k2], k2));
        h[k2] = max(h[k2], h[k1] + 1);
        g[cur].emplace(-h[k2], k2);
        assert(y - 1 == g[cur].size());
    }
    reverse(ans.begin(), ans.end());
    cur = 0;
    cout << 0;
    for (int i = 0; i < n - 1; ++i) {
        cur = g[cur].begin()->second;
        cout << ' ' << cur;
    }
    cout << '\n';
    cout << ans.size() << '\n' << ans << endl;
    return 0;
}