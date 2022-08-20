/*
    author:  Maksim1744
    created: 07.05.2019 21:12:25
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

mt19937_64 rng(487236884723ll);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int n, m;
vector<vector<int>> g;
int counter = 0;

#ifdef HOME
vector<vector<int>> mat;
void init() {
    mat.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (rnd(2))
                mat[i][j] = 3;
            else
                mat[j][i] = 3;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            mat[i][j] = 1;
            mat[j][i] = 0;
        }
    }
    // for (int i = 0; i < n * (n - 1) / 2 - m; ++i) {
    //     int  a, b;
    //     cin >> a >> b;
    //     --a; --b;
    //     mat[a][b] = 3;
    // }
    // printMatrix(mat);
}
bool ask(int u, int v) {
    assert(++counter <= n * 2);
    if (mat.empty())
        init();
    if (mat[u][v] == 3)
        mat[u][v] = 2;
    else if (mat[v][u] == 3)
        mat[v][u] = 2;
    return mat[u][v] != 0;
}
void guess(int v) {
    if (mat.empty())
        init();
    vector<bool> u1(n, false), u2(n, false);
    function<void(int, int)> dfs = [&](int v, int y) {
        u1[v] = true;
        for (int i = 0; i < n; ++i) {
            if (mat[v][i] == y && !u1[i])
                dfs(i, y);
        }
    };
    dfs(v, 1);
    swap(u1, u2);
    dfs(v, 2);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (!(u1[i] || u2[i])) {
            cout << i << " is not reachable from " << v << '\n';
            if (ok)
                printMatrix(mat);
            ok = false;
        }
    }
    if (ok) {
        cout << "WIN, v = " << v << '\n';
    }
}
#else
bool ask(int u, int v) {
    assert(++counter <= n * 2);
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int k;
    cin >> k;
    assert(k != -1);
    return k;
}
void guess(int v) {
    cout << "! " << v + 1 << endl;
}
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
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }
    vector<int> col = scc(g);
    vector<vector<int>> comp(maxe(col) + 1);
    for (int i = 0; i < n; ++i) {
        comp[col[i]].pb(i);
    }
    vector<int> cnt(comp.size(), 0);
    for (int i = 0; i < n; ++i)
        for (auto j : g[i])
            if (col[i] != col[j])
                ++cnt[col[j]];
    queue<int> free;
    // show(cnt, comp);
    for (int i = 0; i < comp.size(); ++i)
        if (cnt[i] == 0)
            free.push(i);
    int ind1 = free.front();
    cnt[ind1] = -1;
    free.pop();
    vector<vector<int>> real_comp = comp;
    while (free.size() > 0) {
        int ind2 = free.front();
        cnt[ind2] = -1;
        // show(ind2);
        free.pop();
        while (!comp[ind1].empty() && !comp[ind2].empty()) {
            if (ask(comp[ind1].back(), comp[ind2].back()))
                comp[ind2].pop_back();
            else
                comp[ind1].pop_back();
        }
        if (comp[ind1].empty())
            swap(ind1, ind2);
        for (auto v : real_comp[ind2])
            for (auto u : g[v])
                if (col[u] != col[v])
                    if ((--cnt[col[u]]) == 0)
                        free.push(col[u]);
    }
    guess(comp[ind1].back());
    return 0;
}