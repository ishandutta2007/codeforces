/*
    author:  Maksim1744
    created: 08.09.2020 19:19:56
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

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> w;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u; --v;
        if (u == v) continue;
        if (w.count({u, v}) && w[{u, v}] != t)
            w[{u, v}] = -1;
        else
            w[{u, v}] = t;
    }
    vector<vector<pair<int, int>>> gi(n);
    for (auto [p, t] : w) {
        gi[p.second].eb(p.first, t);
    }
    queue<pair<int, int>> s;
    vector<int> d(n, inf);
    d[n - 1] = 0;
    s.emplace(0, n - 1);
    vector<bool> u(n, false);
    u[n - 1] = true;
    vector<int> color(n, -1);
    while (!s.empty()) {
        auto [dd, v] = s.front();
        s.pop();
        for (auto [k, t] : gi[v]) {
            if (d[k] <= d[v]) continue;
            if (u[k]) continue;
            // if (v == 2 && k == 0) show(t, color[k]);
            if (t == -1 || t == color[k]) {
                d[k] = d[v] + 1;
                u[k] = true;
                s.emplace(d[k], k);
                if (t != -1)
                    color[k] = t;
            } else if (color[k] == -1) {
                color[k] = 1 - t;
            } else {
                continue;
            }
        }
    }
    show(gi);
    show(color);
    show(d);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) color[i] = 0;
    }
    if (d[0] == inf) {
        cout << -1 << '\n';
    } else {
        cout << d[0] << '\n';
    }
    for (auto c : color) {
        cout << c;
    }
    cout << '\n';

    return 0;
}