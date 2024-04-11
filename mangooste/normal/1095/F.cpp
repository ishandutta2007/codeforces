#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

namespace Debug {
    #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

struct edge {
    int v, u;
    ll w;

    edge(int v = 0, int u = 0, ll w = 0) :
        v(v), u(u), w(w)
    {}
};

vector<int> parent, sz;

int get_parent(int v) {
    return parent[v] == v ? v : parent[v] = get_parent(parent[v]);
}

void unite(int v, int u) {
    v = get_parent(v);
    u = get_parent(u);
    if (v == u)
        return;
    if (sz[v] > sz[u])
        parent[u] = v, sz[v] += sz[u];
    else
        parent[v] = u, sz[u] += sz[v];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> vers;
    for (int i = 0; i < n; i++)
        vers.push_back(i);
    sort(all(vers), [&](int &i, int &j) {
        return a[i] < a[j];
    });
    ll ans = 0;
    parent.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w, v--, u--;
        edges.push_back(edge(v, u, w));
    }
    sort(all(edges), [](edge &a, edge &b) {
        return a.w < b.w;
    });
    int j = 0;
    for (int i = 1; i < n; i++) {
        ll cur_cost = a[vers[0]] + a[vers[i]];
        while (j < m && edges[j].w <= cur_cost) {
            if (get_parent(edges[j].v) != get_parent(edges[j].u)) {
                ans += edges[j].w;
                unite(edges[j].v, edges[j].u);
            }
            j++;
        }
        if (get_parent(vers[i]) != get_parent(vers[0])) {
            ans += cur_cost;
            unite(vers[0], vers[i]);
        }
    }
    cout << ans << '\n';
}