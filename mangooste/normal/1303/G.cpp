#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

template<class T>
struct LiChao {
    struct Line {
        T k, b;
        bool empty;

        Line() : empty(true) {}
        Line(T k, T b) : k(k), b(b), empty(false) {}

        inline T getVal(T x) {
            return k * x + b;
        }
    };

    int n;
    vector<Line> tree;

    LiChao() {}
    LiChao(int n) : n(n), tree(4 * n) {}

    inline void addLine(Line ln) {
        addLine(1, 0, n, ln);
    }

    void addLine(int v, int vl, int vr, Line &ln) {
        if (tree[v].empty) {
            tree[v] = ln;
            return;
        }

        T a = tree[v].getVal(vl);
        T b = tree[v].getVal(vr - 1);
        T c = ln.getVal(vl);
        T d = ln.getVal(vr - 1);

        if (a >= c && b >= d) return;
        if (c >= a && d >= b) {
            tree[v] = ln;
            return;
        }

        int vm = (vl + vr) / 2;
        addLine(2 * v, vl, vm, ln);
        addLine(2 * v + 1, vm, vr, ln);
    }

    inline T get(int pos) {
        return get(1, 0, n, pos, numeric_limits<T>::min());
    }

    T get(int v, int vl, int vr, int pos, T mx) {
        if (!tree[v].empty) mx = max(mx, tree[v].getVal(pos));
        if (vr - vl == 1) return mx;

        int vm = (vl + vr) / 2;
        if (pos < vm) return get(2 * v, vl, vm, pos, mx);
        return get(2 * v + 1, vm, vr, pos, mx);
    }
};

using Line = LiChao<ll>::Line;

int n;
vector<vector<int>> g;
vector<int> a;

vector<char> used;
vector<int> sz;

ll ans;

void dfsSz(int v, int par) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u == par || used[u]) continue;
        dfsSz(u, v);
        sz[v] += sz[u];
    }
}

int dfsCentroid(int v, int par, int szAll) {
    for (auto u : g[v]) {
        if (u == par || used[u]) continue;
        if (sz[u] * 2 > szAll) return dfsCentroid(u, v, szAll);
    }
    return v;
}

void dfsRelax(int v, int par, ll val, ll sum, int dist, LiChao<ll> &lichao) {
    sum += a[v];
    val += sum;
    ans = max(ans, lichao.get(dist) + val);

    for (auto u : g[v]) {
        if (u == par || used[u]) continue;
        dfsRelax(u, v, val, sum, dist + 1, lichao);
    }
}

void dfsAdd(int v, int par, ll s0, ll s1, ll k, LiChao<ll> &lichao) {
    s0 += a[v];
    s1 += k * a[v];
    ans = max(ans, s1);
    lichao.addLine(Line(s0, s1));

    for (auto u : g[v]) {
        if (u == par || used[u]) continue;
        dfsAdd(u, v, s0, s1, k + 1, lichao);
    }
}

void solveOne(int v) {
    LiChao<ll> lichao(sz[v]);
    lichao.addLine(Line(a[v], a[v]));
    for (auto u : g[v]) {
        if (used[u]) continue;
        dfsRelax(u, v, 0, 0, 1, lichao);
        dfsAdd(u, v, a[v], a[v], 2, lichao);
    }
}

void mainDfs(int v) {
    dfsSz(v, v);
    v = dfsCentroid(v, v, sz[v]);
    used[v] = 1;

    solveOne(v);
    reverse(all(g[v]));
    solveOne(v);

    for (auto u : g[v]) {
        if (!used[u]) mainDfs(u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }
    ans = *max_element(all(a));

    used.resize(n);
    sz.resize(n);
    mainDfs(0);

    cout << ans << '\n';
}