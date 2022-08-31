/*
    author:  Maksim1744
    created: 08.05.2019 18:35:48
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
const int nax = 10;
const int naxl = 4;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int nax = 100005;
const int naxl = 20;
#endif


int n, m, k;
vector<vector<int>> g;
vector<bool> dead;
array<int, nax> sz;
array<set<int>, nax> cnt;
array<array<pair<int, set<int>>, nax>, naxl> cent;

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

void dfs_set(int v, int c, int lvl, set<int> s, int p = -1) {
    for (auto y : cnt[v])
        s.insert(y);
    while (s.size() > 10)
        s.erase(--s.end());
    cent[lvl][v] = {c, s};
    for (auto u : g[v])
        if (!dead[u] && u != p)
            dfs_set(u, c, lvl, s, v);
}

void build(int v = 0, int lvl = 0) {
    int c = find_centroid(v, dfs_sz(v));
    dead[c] = true;
    dfs_set(c, c, lvl, set<int>());
    for (auto u : g[c])
        if (!dead[u])
            build(u, lvl + 1);
}

set<int> ask(int u, int v) {
    int lvl = 0;
    while (cent[lvl][u].first == cent[lvl][v].first)
        ++lvl;
    --lvl;
    // show(u, v, lvl);
    set<int> s = cent[lvl][u].second;
    for (auto y : cent[lvl][v].second)
        s.insert(y);
    // show(s);
    return s;
}

int main() {
    cin >> n >> m >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u;
        cnt[u - 1].insert(i + 1);
    }
    dead.assign(n, false);
    for (int i = 0; i < naxl; ++i) {
        cent[i].fill(mp(-1, set<int>()));
    }
    build();
    show(cent);
    for (int i = 0; i < k; ++i) {
        int v, u, a;
        cin >> v >> u >> a;
        if (u == v) {
            if (!cnt[u - 1].empty()) {
                cout << min(a, (int)cnt[u - 1].size());
                auto it = cnt[u - 1].begin();
                for (int i = 0; i < min(a, (int)cnt[u - 1].size()); ++i) {
                    cout << ' ' << *it;
                    ++it;
                }
                cout << '\n';
            }
            else
                cout << 0 << '\n';
            continue;
        }
        set<int> s = ask(v - 1, u - 1);
        while (s.size() > a)
            s.erase(--s.end());
        cout << s.size();
        for (auto u : s) {
            cout << ' ' << u;
        }
        cout << '\n';
    }
    return 0;
}