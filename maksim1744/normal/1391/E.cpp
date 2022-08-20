/*
    author:  Maksim1744
    created: 09.08.2020 18:17:52
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

void test_case() {
    int n, m;
    cin >> n >> m;
    int need = (n + 1) / 2;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> lvl(n, 0);
    vector<int> par(n, 0);
    vector<int> h(n, 0);
    vector<bool> u(n, false);
    vector<bool> leaf(n, true);
    vector<int> d(n, 0);
    function<void(int, int, int)> dfs = [&](int v, int level, int p) {
        u[v] = true;
        lvl[v] = level;
        par[v] = p;
        h[v] = 1;
        for (auto k : g[v]) {
            if (!u[k]) {
                d[v]++;
                leaf[v] = false;
                dfs(k, level + 1, v);
                h[v] = max(h[v], h[k] + 1);
            }
        }
    };
    dfs(0, 0, -1);
    if (h[0] >= need) {
        int mxi = 0;
        for (int i = 0; i < n; ++i) {
            if (lvl[i] > lvl[mxi]) mxi = i;
        }
        vector<int> path;
        while (mxi != -1) {
            path.pb(mxi);
            mxi = par[mxi];
        }
        ++path;
        cout << "PATH\n";
        cout << path.size() << '\n';
        cout << path << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        int mx1 = 0, mx2 = 0;
        int i1 = -1, i2 = -1;
        for (auto k : g[i]) {
            if (lvl[k] == lvl[i] + 1) {
                if (h[k] >= mx1) {
                    mx2 = mx1;
                    mx1 = h[k];
                    i2 = i1;
                    i1 = k;
                } else if (h[k] > mx2) {
                    mx2 = h[k];
                    i2 = k;
                }
            }
        }
        if (mx1 + mx2 + 1 >= need) {
            vector<int> path = {i};
            int v = i1;
            while (v != -1) {
                path.pb(v);
                int k = -1;
                for (auto y : g[v]) {
                    if (lvl[y] == lvl[v] + 1) {
                        if (k == -1 || h[k] < h[y])
                            k = y;
                    }
                }
                v = k;
            }

            reverse(path.begin(), path.end());

            v = i2;
            while (v != -1) {
                path.pb(v);
                int k = -1;
                for (auto y : g[v]) {
                    if (lvl[y] == lvl[v] + 1) {
                        if (k == -1 || h[k] < h[y])
                            k = y;
                    }
                }
                v = k;
            }

            ++path;
            cout << "PATH\n";
            cout << path.size() << '\n';
            cout << path << '\n';
            return;
        }
    }

    set<pair<int, int>> leafes;
    for (int i = 0; i < n; ++i) {
        if (leaf[i]) {
            leafes.emplace(-lvl[i], i);
        }
    }
    vector<pair<int, int>> ans;
    while (leafes.size() >= 2) {
        auto [hh1, v1] = *leafes.begin();
        leafes.erase(leafes.begin());
        auto [hh2, v2] = *leafes.begin();
        leafes.erase(leafes.begin());
        ans.eb(v1, v2);
        for (auto v : {v1, v2}) {
            if (par[v] != -1) {
                d[par[v]]--;
                if (d[par[v]] == 0) {
                    leafes.emplace(-lvl[par[v]], par[v]);
                }
            }
        }
    }

    assert(ans.size() * 2 >= need);
    cout << "PAIRING\n";
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a + 1 << ' ' << b + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}