/*
    author:  Maksim1744
    created: 16.05.2021 11:55:48
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

bool matching_dfs(int v, vector<vector<int>>& g, vector<int>& from, vector<bool>& u) {
    u[v] = true;
    for (auto k : g[v]) {
        if (from[k] == -1 || (!u[from[k]] && matching_dfs(from[k], g, from, u))) {
            from[k] = v;
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> find_matching(vector<vector<int>>& g, vector<int> a) {
    bool rev = false;
    if (2 * a.size() > g.size()) {
        rev = true;
        vector<bool> has(g.size(), false);
        for (auto v : a)
            has[v] = true;
        a.clear();
        a.reserve(g.size() - a.size());
        for (int i = 0; i < g.size(); ++i)
            if (!has[i])
                a.push_back(i);
    }
    vector<bool> u(g.size(), false);
    vector<int> from(g.size(), -1);
    for (auto v : a)
        if (matching_dfs(v, g, from, u))
            u.assign(g.size(), false);
    vector<pair<int, int>> result;
    for (int v = 0; v < from.size(); ++v) {
        if (from[v] != -1) {
            if (rev) result.emplace_back(v, from[v]);
            else result.emplace_back(from[v], v);
        }
    }
    return result;
}

void dominating_set_dfs(int v, vector<vector<int>>& g, vector<int>& with, vector<bool>& u,
                                                                          vector<bool>& take) {
    u[v] = true;
    for (auto k : g[v]) {
        take[k] = true;
        if (!u[with[k]])
            dominating_set_dfs(with[k], g, with, u, take);
    }
}

vector<int> find_dominating_set(vector<vector<int>>& g, vector<int>& a) {
    auto matching = find_matching(g, a);
    vector<int> with(g.size(), -1);
    for (auto edge : matching) {
        with[edge.first] = edge.second;
        with[edge.second] = edge.first;
    }
    vector<bool> u(g.size(), false);
    vector<bool> take(g.size(), false);
    for (auto v : a)
        if (with[v] == -1)
            dominating_set_dfs(v, g, with, u, take);
    for (auto e : matching)
        if (!take[e.second])
            take[e.first] = true;
    vector<int> result(matching.size());
    for (int i = 0; i < matching.size(); ++i) {
        if (take[matching[i].second]) result[i] = matching[i].second;
        else result[i] = matching[i].first;
    }
    return result;
}

vector<int> find_independent_set(vector<vector<int>>& g, vector<int>& a) {
    vector<int> result;
    vector<bool> u(g.size(), false);
    for (auto v : find_dominating_set(g, a))
        u[v] = true;
    for (int i = 0; i < g.size(); ++i)
        if (!u[i])
            result.push_back(i);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n * 2);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v + n);
        g[v + n].pb(u);
    }
    vector<int> aaa(n);
    iota(aaa.begin(), aaa.end(), 0);

    int sz0 = n - find_matching(g, aaa).size();
    vector<int> ord;
    show(sz0);
    while (true) {
        auto st = find_independent_set(g, aaa);
        show(st);
        if (st.size() == n * 2) break;
        set<int> sst(st.begin(), st.end());
        int v = 0;
        while (sst.count(v)) ++v;
        g[v].clear();
        show(g);
        for (int i = 0; i < g.size(); ++i) {
            int ind = find(g[i].begin(), g[i].end(), v) - g[i].begin();
            if (ind != g[i].size())
                g[i].erase(g[i].begin() + ind);
        }
        ord.pb(v);
        show(find_matching(g, aaa).size());
    }
    show(ord);
    assert(ord.size() == n - sz0);

    vector<ll> x(k), y(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
    }
    
    vector<int> at_least(k);
    for (int i = 0; i < k; ++i) {
        at_least[i] = max(0, (i + 1) - sz0 + 1);
    }

    vector<vector<ll>> dp(k, vector<ll>(n * 2 + 5, -1));
    for (int i = 0; i < dp[0].size(); ++i) {
        dp[0][i] = max(0ll, x[0] - y[0] * i);
    }
    show(x, y);
    vector<vector<int>> from(k, vector<int>(n * 2 + 5, 0));
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 0; j < dp[i].size(); ++j) {
            for (int u = 0; u <= j; ++u) {
                if (j - u < at_least[i - 1]) continue;
                ll val = dp[i - 1][j - u] + max(0ll, x[i] - y[i] * u);
                if (val > dp[i][j]) {
                    dp[i][j] = max(dp[i][j], val);
                    from[i][j] = j - u;
                }
            }
        }
    }
    show(at_least);
    show(dp);
    show(dp.back()[at_least.back()]);

    vector<int> counts(k, 0);
    {
        int x = k - 1;
        int y = at_least.back();
        while (x >= 0) {
            int d = from[x][y];
            counts[x] = y - d;
            x--;
            y = d;
        }
    }
    show(counts);

    cout << sum(counts) + k << '\n';
    int ind = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            int v = ord[ind];
            ++ind;
            if (v >= n) v = -(v - n + 1);
            else v++;
            cout << v << ' ';
        }
        cout << 0 << ' ';
    }
    cout << '\n';

    return 0;
}