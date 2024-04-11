/*
    author:  Maksim1744
    created: 08.05.2019 17:42:21
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int nax = 200005;

int n;
vector<vector<int>> g;
vector<bool> dead;
array<char, nax> col;
array<int, nax> sz;

int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for (auto u : g[v])
        if (u != p && !dead[u])
            sz[v] += dfs_sz(u, v);
    return sz[v];
}

int find_centroid(int v, int s, int p = -1) {
    for (auto u : g[v])
        if (!dead[u] && u != p && sz[u] * 2 > s)
            return find_centroid(u, s, v);
    return v;
}

ll go(int v, char lvl = 'A') {
    int c = find_centroid(v, dfs_sz(v));
    dead[c] = true;
    col[c] = lvl;
    for (auto u : g[c])
        if (!dead[u])
            go(u, lvl + 1);
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dead.assign(n, false);
    go(0);
    for (int i = 0; i < n; ++i) {
        cout << col[i] << ' ';
    }
    cout << '\n';
    return 0;
}