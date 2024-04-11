/*
    author:  Maksim1744
    created: 04.05.2021 00:25:20
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

struct dinic_edge {
    int from, to;
    long long mx;
};

long long max_flow_dinic(vector<vector<pair<int, long long>>> g_main, int s, int t) {
    int n = g_main.size();
    vector<vector<int>> g(n);
    vector<dinic_edge> e;
    for (int u = 0; u < n; ++u) {
        for (auto pr : g_main[u]) {
            int v = pr.first;
            long long w = pr.second;
            g[u].push_back(e.size());
            e.push_back({u, v, w});
            g[v].push_back(e.size());
            e.push_back({v, u, 0});
        }
    }
    long long flow = 0;
    vector<int> layer(n, -5);
    vector<int> q(n + 10);
    int ql, qr;
    vector<int> ptr(n, 0);
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
                if (e[k].mx > 0 && layer[e[k].to] == -5) {
                    layer[e[k].to] = layer[v] + 1;
                    q[qr++] = e[k].to;
                }
            }
        }
        if (layer[t] == -5)
            break;
        long long prev_flow = flow;
        while (true) {
            function<long long(int, long long)> go = [&](int v, long long now) -> long long {
                if (v == t)
                    return now;
                while (ptr[v] < g[v].size()) {
                    if (layer[v] + 1 == layer[e[g[v][ptr[v]]].to] && e[g[v][ptr[v]]].mx > 0) {
                        long long next = min(now, e[g[v][ptr[v]]].mx);
                        long long x = go(e[g[v][ptr[v]]].to, next);
                        if (x > 0) {
                            e[g[v][ptr[v]]].mx -= x;
                            e[g[v][ptr[v]]^1].mx += x;
                            return x;
                        } else {
                            ++ptr[v];
                        }
                    } else {
                        ++ptr[v];
                    }
                }
                return 0;
            };
            long long el_flow = go(s, 1e9l * 1e9l * 4l);
            if (el_flow == 0)
                break;
            flow += el_flow;
        }
        if (flow == prev_flow)
            break;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    cin >> v;
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        v[i].first.first += (int)1e9;
        v[i].first.second += (int)1e9;
        sm += v[i].second;
    }
    auto col = [&](pair<int, int> p) {
        assert(p.first >= 0 && p.second >= 0);
        if (p.second % 2 == 0)
            return (p.first + 1) % 2 + 1;
        return p.first % 2 + 3;
    };

    vector<vector<pair<int, ll>>> g(n * 2 + 2);

    const ll inf = 1e16;

    for (int i = 0; i < n; ++i) {
        g[i * 2].eb(i * 2 + 1, v[i].second);
        if (col(v[i].first) == 1)
            g[n * 2].eb(i * 2, inf);
        else if (col(v[i].first) == 4)
            g[i * 2 + 1].eb(n * 2 + 1, inf);
    }

    auto neigh = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second) == 1;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (col(v[i].first) + 1 == col(v[j].first) && neigh(v[i].first, v[j].first)) {
                g[i * 2 + 1].eb(j * 2, inf);
            }
        }
    }

    show(g);

    debug {
        int tot = 0;
        for (int i = 0; i < g.size(); ++i) {
            tot += g[i].size();
        }
        cerr << g.size() << ' ' << tot << '\n';
        for (int i = 0; i < g.size(); ++i)
            for (auto [j, w] : g[i])
                cerr << i + 1 << ' ' << j + 1 << ' ' << w << '\n';
    }

    show(sm);

    cout << sm - max_flow_dinic(g, n * 2, n * 2 + 1) << '\n';

    return 0;
}