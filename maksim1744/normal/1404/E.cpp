/*
    author:  Maksim1744
    created: 28.01.2021 16:22:32
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

auto find_matching_dinic(vector<vector<int>>& g_main, vector<int>& a) {
    int n = g_main.size();
    vector<vector<int>> g(n + 2);
    vector<int> e;
    vector<bool> can;
    vector<bool> in_a(n, false);
    auto add = [&](int i, int j) {
        g[i].push_back(e.size());
        e.push_back(j);
        can.push_back(true);
        g[j].push_back(e.size());
        e.push_back(i);
        can.push_back(false);
    };
    for (auto u : a) {
        in_a[u] = true;
        for (auto v : g_main[u])
            add(u, v);
    }
    int s = n, t = n + 1;
    for (int u = 0; u < n; ++u) {
        if (in_a[u])
            add(s, u);
        else
            add(u, t);
    }
    n += 2;
    int flow = 0;
    vector<int> layer(n, -5);
    vector<int> q(n + 10);
    int ql, qr;
    vector<int> ptr(n, 0);
    vector<int> to(n);
    for (int i = 0; i < n; ++i) {
        layer.assign(n, -5);
        ptr.assign(n, 0);
        ql = 0;
        qr = 1;
        q[0] = s;
        layer[s] = 0;
        while (ql < qr) {
            int v = q[ql++];
            for (auto k : g[v]) {
                if (can[k] && layer[e[k]] == -5) {
                    layer[e[k]] = layer[v] + 1;
                    q[qr++] = e[k];
                }
            }
        }
        if (layer[t] == -5)
            break;
        int prev_flow = flow;
        while (true) {
            function<bool(int)> go = [&](int v) -> bool {
                if (v == t)
                    return true;
                while (ptr[v] < g[v].size()) {
                    if (layer[v] + 1 == layer[e[g[v][ptr[v]]]] && can[g[v][ptr[v]]]) {
                        int x = go(e[g[v][ptr[v]]]);
                        if (x) {
                            can[g[v][ptr[v]]] = false;
                            can[g[v][ptr[v]]^1] = true;
                            return true;
                        } else {
                            ++ptr[v];
                        }
                    } else {
                        ++ptr[v];
                    }
                }
                return false;
            };
            if (!go(s))
                break;
            ++flow;
        }
        if (flow == prev_flow)
            break;
    }
    // return flow;  // if need only size
    vector<pair<int, int>> res;
    for (auto i : a) {
        for (auto k : g[i]) {
            if (e[k] != s && !can[k])
                res.emplace_back(i, e[k]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n * 2 - 1, vector<int>(m * 2 - 1, -1));
    int total = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '#') {
                v[i * 2][j * 2] = 0;
                ++total;
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if ((i + j) % 2 == 0) continue;
            if (i != 0 && i + 1 < v.size() && v[i - 1][j] == 0 && v[i + 1][j] == 0) v[i][j] = cur++;
            else if (j != 0 && j + 1 < v[i].size() && v[i][j - 1] == 0 && v[i][j + 1] == 0) v[i][j] = cur++;
        }
    }
    const vector<pair<int, int>> D = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    vector<vector<int>> g(cur);
    vector<int> a;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            if ((i + j) % 2 == 0) continue;
            if (v[i][j] == -1) continue;
            if (i % 2) a.pb(v[i][j]);
            for (auto [di, dj] : D) {
                if (i + di >= 0 && j + dj >= 0 && i + di < v.size() && j + dj < v[i].size() && v[i + di][j + dj] != -1)
                    g[v[i][j]].pb(v[i + di][j + dj]);
            }
        }
    }

    auto res = find_matching_dinic(g, a);
    int fr = g.size() - res.size();
    cout << total - fr << '\n';

    return 0;
}