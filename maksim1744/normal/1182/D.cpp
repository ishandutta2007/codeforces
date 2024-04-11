/*
    author:  Maksim1744
    created: 12.06.2019 15:31:54
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
    if (n <= 2) {
        cout << 1 << '\n';
        return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> leafes;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            leafes.pb(i);
        }
    }
    show(leafes);
    if (leafes.size() == 2) {
        cout << leafes[0] + 1 << '\n';
        return 0;
    }
    // vector<bool> u(n, false);
    vector<int> lvl(n, -1);
    vector<int> p(n, -1);
    function<void(int, int, int)> dfs = [&](int v, int d, int par) {
        lvl[v] = d;
        p[v] = par;
        for (auto k : g[v]) {
            if (lvl[k] == -1) {
                dfs(k, d + 1, v);
            }
        }
    };
    auto check = [&](int v) {
        lvl.assign(n, -1);
        dfs(v, 0, -1);
        vector<vector<int>> byl(n);
        for (int i = 0; i < n; ++i) {
            byl[lvl[i]].pb(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + 1 < byl[i].size(); ++j) {
                if (g[byl[i][j]].size() != g[byl[i][j + 1]].size()) {
                    return;
                }
            }
        }
        cout << v + 1 << '\n';
        exit(0);
    };
    dfs(leafes[0], 0, -1);
    int vfar = 0;
    for (int i = 0; i < n; ++i) {
        if (lvl[vfar] < lvl[i])
            vfar = i;
    }
    int v1 = vfar;
    lvl.assign(n, -1);
    dfs(v1, 0, -1);
    for (int i = 0; i < n; ++i) {
        if (lvl[vfar] < lvl[i])
            vfar = i;
    }
    int v2 = vfar;
    check(v1);
    check(v2);
    lvl.assign(n, -1);
    dfs(v1, 0, -1);
    show(v1, v2);
    show(p);
    vector<int> path;
    while (v2 != -1) {
        path.pb(v2);
        v2 = p[v2];
    }
    show(path);
    check(path[path.size() / 2]);

    int v = path[path.size() / 2];
    lvl.assign(n, -1);
    dfs(v, 0, -1);
    vector<vector<int>> byl(n);
    for (int i = 0; i < n; ++i) {
        byl[lvl[i]].pb(i);
    }
    auto down = [&](int v) {
        while (true) {
            int v0 = v;
            for (auto k : g[v]) {
                if (lvl[k] > lvl[v]) {
                    v = k;
                    break;
                }
            }
            if (v == v0)
                break;
        }
        return v;
    };
    for (int i = 1; i < n; ++i) {
        if (byl[i].size() <= 2) {
            for (auto v : byl[i]) {
                v = down(v);
                check(v);
            }
            break;
        }
        map<int, vector<int>> byd;
        for (auto k : byl[i]) {
            byd[g[k].size()].pb(k);
        }
        if (byd.size() > 2)
            break;
        if (byd.size() == 1)
            continue;
        for (auto p : byd) {
            if (p.second.size() == 1) {
                int v = down(p.second[0]);
                check(v);
            }
        }
        break;
    }

    cout << -1 << '\n';
    return 0;
}