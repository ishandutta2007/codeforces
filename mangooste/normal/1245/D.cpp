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

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

struct edge {
    int x, y;
    ll cost;
    edge(int x = 0, int y = 0, ll cost = 0) :
        x(x), y(y), cost(cost)
    {}
};

vector<int> parent, sz;

int get_parent(int v) {
    return (parent[v] == v ? v : parent[v] = get_parent(parent[v]));
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
    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    for (auto &el : pts)
        cin >> el.first >> el.second;
    vector<int> c(n), k(n);
    for (int &el : c)
        cin >> el;
    for (int &el : k)
        cin >> el;
    vector<edge> edgs;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edgs.pb(edge(i, j, 1ll * (abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second)) * (k[i] + k[j])));
    for (int i = 0; i < n; i++)
        edgs.pb(edge(i, n, c[i]));
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i, sz[i] = 1;
    sort(all(edgs), [](edge &a, edge &b) {
        return a.cost < b.cost;
    });
    ll ans = 0;
    vector<int> in;
    vector<pair<int, int>> need_edgs;
    for (auto el : edgs) {
        int v = el.x, u = el.y;
        if (get_parent(v) != get_parent(u)) {
            ans += el.cost;
            unite(v, u);
            if (v > u)
                swap(u, v);
            if (u == n)
                in.pb(v);
            else
                need_edgs.eb(u, v);
        }
    }
    cout << ans << '\n';
    cout << in.size() << '\n';
    for (auto el : in)
        cout << el + 1 << ' ';
    cout << '\n' << need_edgs.size() << '\n';
    for (auto el : need_edgs)
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
}