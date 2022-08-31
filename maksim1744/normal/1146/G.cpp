/*
    author:  Maksim1744
    created: 10.05.2019 15:44:39
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
#define printWGraph(...) 42;
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

const ll inf = 1e7;

int main() {
    int n, h, m;
    cin >> n >> h >> m;
    vector<vector<pair<int, ll>>> g(2 + n * (h + 2) + m);
    int k = g.size();
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= h + 1; ++i) {
            g[j * (h + 2) + i + 2].eb(j * (h + 2) + i - 1 + 2, inf);
            g[j * (h + 2) + i - 1 + 2].eb(j * (h + 2) + i + 2, h * h - (i - 1) * (i - 1));
        }
        g[0].eb(j * (h + 2) + 2, inf);
        g[j * (h + 2) + (h + 1) + 2].eb(1, inf);
    }
    for (int i = 0; i < m; ++i) {
        int l, r, x, c;
        cin >> l >> r >> x >> c;
        --l; --r; ++x;
        for (int j = l; j <= r; ++j) {
            g[j * (h + 2) + x + 2].eb(k - m + i, inf);
        }
        g[k - m + i].eb(1, c);
    }
    // printWGraph(g, 1);
    // show(k, g);
    cout << n * h * h - max_flow_dinic(g, 0, 1) << '\n';
    return 0;
}