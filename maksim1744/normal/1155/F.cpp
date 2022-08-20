/*
    author:  Maksim1744
    created: 23.04.2019 17:43:37
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
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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

auto start_time = clock();
ld max_time = (ld)1.95 * CLOCKS_PER_SEC;
vector<pair<int, int>> e;
vector<bool> u;
vector<int> up;
vector<int> d;
vector<bool> du;
int n, m;

bool dfs(int v, int h, vector<vector<int>>& g, int p = -1) {
    d[v] = h;
    up[v] = h;
    du[v] = true;
    for (auto k : g[v]) {
        if (!du[k]) {
            bool ok = dfs(k, h + 1, g, v);
            if (!ok)
                return false;
            up[v] = min(up[v], up[k]);
        } else if (k != p) {
            up[v] = min(up[v], d[k]);
        }
    }
    if (v != 0 && up[v] == d[v])
        return false;
    return true;
}

bool check() {
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        if (u[i]) {
            g[e[i].first].pb(e[i].second);
            g[e[i].second].pb(e[i].first);
        }
    }
    // show(g);
    du.assign(n, false);
    bool res = dfs(0, 0, g);
    for (int i = 0; i < n; ++i) {
        res &= du[i];
    }
    // show(up);
    return res;
}

mt19937_64 rng(293842798243921ll);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    cin >> n >> m;
    e.resize(m);
    cin >> e;
    for (int i = 0; i < m; ++i) {
        --e[i].first;
        --e[i].second;
    }
    up.resize(n);
    d.resize(n);
    du.resize(n);
    u.assign(m, true);
    vector<bool> bestu = u;
    // {
    //     u[0] = false;
    //     // u[1] = false;
    //     // u[2] = false;
    //     bool y = check();
    //     show(y);
    //     return 0;
    // }
    int ans = m;
    int now = m;
    while ((ld)(clock() - start_time) < max_time) {
        if (rnd(1000) == 0) {
            u.assign(m, true);
            now = m;
        } else {
            if (rnd(4) <= 2) {
                int ind = rnd(m);
                while (!u[ind]) {
                    ind = rnd(m);
                }
                u[ind] = false;
                --now;
                if (check()) {
                    if (now < ans) {
                        ans = now;
                        bestu = u;
                    }
                } else {
                    ++now;
                    u[ind] = true;
                }
            } else {
                int y = 0;
                int ind = rnd(m);
                while (y < m * 2 && u[ind]) {
                    ind = rnd(m);
                    ++y;
                }
                if (!u[ind]) {
                    ++now;
                    u[ind] = true;
                }
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < m; ++i) {
        if (bestu[i]) {
            cout << e[i].first + 1 << ' ' << e[i].second + 1 << '\n';
        }
    }
    return 0;
}