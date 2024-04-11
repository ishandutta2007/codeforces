/*
    author:  Maksim1744
    created: 06.12.2020 18:21:04
*/

#include "bits/stdc++.h"

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
    vector<vector<int>> mt(n, vector<int>(n, inf));
    for (int i = 0; i < n; ++i) {
        mt[i][i] = 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int b;
        cin >> b;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
        if (b == 0) {
            mt[u][v] = 1;
            mt[v][u] = 1;
        } else {
            mt[u][v] = 1;
            mt[v][u] = -1;
        }
    }

    // bipartite
    {
        vector<int> col(n, -1);
        function<void(int, int)> dfs = [&](int v, int color) {
            col[v] = color;
            for (auto k : g[v]) {
                if (col[k] == -1)
                    dfs(k, color ^ 1);
            }
        };
        dfs(0, 0);
        for (int i = 0; i < n; ++i) {
            for (auto j : g[i]) {
                if (col[i] == col[j]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    // negative cycles
    {
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && mt[i][j] != inf)
                    g[i].eb(j, mt[i][j]);
            }
        }
        vector<int> d(n, inf);
        d[0] = 0;
        int C = n + 5;
        for (int k = 0; k < C; ++k) {
            if (k == C - 1) {
                cout << "NO\n";
                return 0;
            }
            bool ch = false;
            for (int i = 0; i < n; ++i) {
                for (auto [j, w] : g[i]) {
                    int was = d[j];
                    d[j] = min(d[j], d[i] + w);
                    if (d[j] != was) {
                        ch = true;
                    }
                }
            }
            if (!ch) break;
        }
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mt[i][j] = min(mt[i][j], mt[i][k] + mt[k][j]);

    int best = -1;
    int besti = -1;
    for (int i = 0; i < n; ++i) {
        int mx = maxe(mt[i]);
        if (mx > best) {
            best = mx;
            besti = i;
        }
    }

    cout << "YES\n";
    cout << best << '\n';
    cout << mt[besti] << '\n';

    return 0;
}