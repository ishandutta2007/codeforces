/*
    author:  Maksim1744
    created: 01.11.2019 17:59:05
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
#endif

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    cin >> xy;
    vector<ll> c(n);
    cin >> c;
    vector<ll> k(n);
    cin >> k;
    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            edges.eb((k[i] + k[j]) * (abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second)), mp(i, j));
        }
    }
    // show(edges);
    for (int i = 0; i < n; ++i) {
        edges.eb(c[i], mp(i, n));
    }
    vector<int> p(n + 1, -1);
    vector<int> rk(n + 1, 0);
    for (int i = 0; i < n + 1; ++i) {
        p[i] = i;
    }
    function<int(int)> par = [&](int v) {
        if (p[v] == v)
            return v;
        p[v] = par(p[v]);
        return p[v];
    };
    auto un = [&](int v, int u) {
        u = par(u);
        v = par(v);
        if (u == v)
            return;
        if (rk[v] < rk[u])
            swap(v, u);
        rk[v] += rk[u];
        p[u] = v;
    };
    sort(edges.begin(), edges.end());
    vector<pair<ll, pair<int, int>>> ans;
    ll cost = 0;
    for (auto [l, p] : edges) {
        auto [u, v] = p;
        if (par(u) == par(v))
            continue;
        ans.eb(l, mp(u, v));
        un(u, v);
        cost += l;
    }
    show(ans);
    cout << cost << endl;
    vector<int> els;
    for (auto [l, p] : ans) {
        if (p.second == n)
            els.pb(p.first);
    }
    cout << els.size() << '\n';
    ++els;
    cout << els << '\n';
    cout << ans.size() - els.size() << '\n';
    for (auto [l, p] : ans) {
        if (p.second != n) {
            cout << p.first + 1 << ' ' << p.second + 1 << endl;
        }
    }
    return 0;
}