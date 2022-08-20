/*
    author:  Maksim1744
    created: 15.08.2020 15:28:38
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

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    vector<vector<int>> g(n * m + 2);

    vector<vector<bool>> can(n, vector<bool>(m, false));
    can[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            if (v[i][j] == '#') continue;
            if (i != 0 && v[i - 1][j] == '.') can[i][j] = (can[i][j] || can[i - 1][j]);
            if (j != 0 && v[i][j - 1] == '.') can[i][j] = (can[i][j] || can[i][j - 1]);
        }
    }
    if (!can.back().back()) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!can[i][j]) v[i][j] = '#';
        }
    }

    // for (auto s : v) {
    //     cout << s << '\n';
    // }

    vector<int> p(g.size());
    for (int i = 0; i < g.size(); ++i) {
        p[i] = i;
    }
    vector<int> rk(g.size(), 1);
    function<int(int)> par = [&](int v) {
        return (v == p[v] ? v : p[v] = par(p[v]));
    };
    auto un = [&](int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
    };

    int v1 = n * m, v2 = n * m + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] != '#') continue;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    if (i + di >= 0 && j + dj >= 0 && i + di < n && j + dj < m) {
                        if (v[i + di][j + dj] == '#') {
                            un(i * m + j, (i + di) * m + j + dj);
                            // g[i * m + j].pb((i + di) * m + j + dj);
                        }
                    }
                }
            }
            if (i == 0 || j == m - 1) {
                un(v1, i * m + j);
                // g[v1].pb(i * m + j);
                // g[i * m + j].pb(v1);
            }
            if (j == 0 || i == n - 1) {
                un(v2, i * m + j);
                // g[v2].pb(i * m + j);
                // g[i * m + j].pb(v2);
            }
        }
    }

    v1 = par(v1);
    v2 = par(v2);
    // vector<vector<int>> tmp(n, vector<int>(m));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         tmp[i][j] = par(i * m + j);
    //     }
    // }
    // printMatrix(tmp);
    // show(v1,)

    if (v1 == v2) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0 || i == n - 1 && j == m - 1) continue;
            bool has1 = false, has2 = false;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    if (i + di >= 0 && j + dj >= 0 && i + di < n && j + dj < m) {
                        if (v[i + di][j + dj] == '#') {
                            if (par((i + di) * m + j + dj) == v1) has1 = true;
                            if (par((i + di) * m + j + dj) == v2) has2 = true;
                        }
                    }
                }
            }
            if (i == 0 || j == m - 1) has1 = true;
            if (j == 0 || i == n - 1) has2 = true;
            if (has1 && has2) {
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 2 << '\n';

    return 0;
}