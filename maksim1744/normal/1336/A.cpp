/*
    author:  Maksim1744
    created: 15.04.2020 17:43:17
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
    int k;
    cin >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> p(n, -1);
    vector<int> u(n, false);
    vector<ll> h(n, 0);
    vector<ll> sz(n, 1);
    function<void(int, int, int)> dfs = [&](int v, int pp, int hh) {
        u[v] = true;
        h[v] = hh + 1;
        p[v] = pp;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k, v, hh + 1);
                sz[v] += sz[k];
            }
        }
    };
    dfs(0, -1, 0);
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += sz[i];
    }
    
    sm = 0;
    show(sm);
    show(sz);
    set<pair<int, int>> leafes;
    for (int i = 1; i < n; ++i) {
        if (g[i].size() == 1) {
            leafes.emplace(sz[i] - h[i], i);
        }
    }
    for (int i = 0; i < k; ++i) {
        auto [ss, v] = *leafes.begin();
        sm -= ss;
        // sm += h[v];
        leafes.erase(leafes.begin());
        if (p[v] != -1)
            leafes.emplace(sz[p[v]] - h[p[v]], p[v]);
    }
    cout << sm << endl;

    return 0;
}