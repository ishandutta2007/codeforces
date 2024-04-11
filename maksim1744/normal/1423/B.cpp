/*
    author:  Maksim1744
    created: 08.04.2021 10:56:29
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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

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
    if (2 * a.size() > g.size() || true) {
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

    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            swap(g[i][j], g[i][rnd(j, g[i].size() - 1)]);
        }
    }

    vector<bool> done(g.size(), false);
    vector<bool> u(g.size(), false);
    vector<int> from(g.size(), -1);

    for (int i : a) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (from[g[i][j]] == -1) {
                from[g[i][j]] = i;
                done[i] = true;
                break;
            }
        }
    }

    for (auto v : a)
        if (!done[v] && matching_dfs(v, g, from, u))
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> w;
    vector<pair<pair<int, int>, int>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i];
        --e[i].first.first;
        --e[i].first.second;
        w.pb(e[i].second);
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    int l = -1, r = w.size();
    vector<int> a(n); iota(a.begin(), a.end(), 0);
    while (r - l > 1) {
        int c = (l + r) / 2;
        vector<vector<int>> g(n * 2);
        for (auto [uv, x] : e) {
            if (x <= w[c]) {
                g[uv.first].pb(uv.second + n);
                g[uv.second + n].pb(uv.first);
            }
        }
        if (find_matching(g, a).size() == n) {
            r = c;
        } else {
            l = c;
        }
    }
    if (r == w.size()) {
        cout << -1 << '\n';
    } else {
        cout << w[r] << '\n';
    }

    return 0;
}