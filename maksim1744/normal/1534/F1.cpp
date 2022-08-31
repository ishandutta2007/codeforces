/*
    author:  Maksim1744
    created: 13.06.2021 19:12:13
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

vector<int> scc(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> topsort; topsort.reserve(n);
    vector<bool> u(n, false);
    function<void(int)> scc_dfs1 = [&](int v) {
        u[v] = true;
        for (auto k : g[v])
            if (!u[k])
                scc_dfs1(k);
        topsort.push_back(v);
    };
    for (int i = 0; i < n; ++i)
        if (!u[i])
            scc_dfs1(i);
    vector<vector<int>> gi(n);
    for (int i = 0; i < n; ++i)
        for (auto j : g[i])
            gi[j].push_back(i);
    int color = 0;
    vector<int> comp(n, -1);
    reverse(topsort.begin(), topsort.end());
    function<void(int, int)> scc_dfs2 = [&](int v, int color) {
        comp[v] = color;
        for (auto k : gi[v])
            if (comp[k] == -1)
                scc_dfs2(k, color);
    };
    for (auto v : topsort)
        if (comp[v] == -1)
            scc_dfs2(v, color++);
    return comp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    vector<vector<int>> ind(n, vector<int>(m, -1));
    int last = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '#')
                ind[i][j] = last++;
        }
    }
    vector<vector<int>> g(last);
    for (int j = 0; j < m; ++j) {
        int il = -1, im = -1, ir = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (j != 0 && v[i][j - 1] == '#')
                il = i;
            if (j != m - 1 && v[i][j + 1] == '#')
                ir = i;

            if (v[i][j] == '#') {
                if (il != -1)
                    g[ind[i][j]].pb(ind[il][j - 1]);
                if (ir != -1)
                    g[ind[i][j]].pb(ind[ir][j + 1]);
                if (im != -1)
                    g[ind[i][j]].pb(ind[im][j]);
                if (i != 0 && v[i - 1][j] == '#')
                    g[ind[i][j]].pb(ind[i - 1][j]);
            }

            if (v[i][j] == '#')
                im = i;
        }
    }
    if (g.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    show(g);

    auto col = scc(g);
    vector<vector<int>> gc(maxe(col) + 1);
    vector<int> inc(gc.size(), 0);
    for (int i = 0; i < g.size(); ++i) {
        for (int j : g[i]) {
            if (col[i] == col[j]) continue;
            gc[col[i]].pb(col[j]);
            inc[col[j]]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < gc.size(); ++i)
        if (inc[i] == 0)
            ++ans;
    cout << ans << '\n';

    return 0;
}