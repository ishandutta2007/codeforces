/*
    14.03.2019 23:59:03
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOMEm
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long inf = 1000000000000000000ll;

vector< vector< int > > g;
vector< long long > c;
vector< bool > u;
vector< long long > mn_all, mn_not_all;
set< int > ans;

void dfs(int v) {
    u[v] = true;
    mn_all[v] = c[v];
    long long delta1 = c[v], delta2 = 0;
    bool leaf = true;
    for (auto k : g[v]) {
        if (!u[k]) {
            leaf = false;
            dfs(k);
            mn_all[v] += mn_all[k];
            int delta = mn_all[k] - mn_not_all[k];
            if (delta >= delta1) {
                delta2 = delta1;
                delta1 = delta;
            } else if (delta > delta2) {
                delta2 = delta;
            }
        }
    }
    if (leaf) {
        mn_not_all[v] = 0;
        return;
    }
    mn_not_all[v] = mn_all[v] - c[v] - (delta1 == c[v] ? delta2 : delta1);
    mn_all[v] -= delta1;
}

void down(int v, int type = 1) {
    u[v] = true;
    long long delta1 = c[v], delta2 = 0;
    bool leaf = true;
    for (auto k : g[v]) {
        if (!u[k]) {
            leaf = false;
            int delta = mn_all[k] - mn_not_all[k];
            if (delta >= delta1) {
                delta2 = delta1;
                delta1 = delta;
            } else if (delta > delta2) {
                delta2 = delta;
            }
        }
    }
    if (leaf && (type & 1)) {
        ans.insert(v);
        return;
    }
    if (delta2 >= c[v] && (type & 1))
        ans.insert(v);
    delta2 = (delta1 == c[v] ? delta2 : delta1);
    int cnt1 = 0, cnt2 = 0;
    int v1 = (delta1 == c[v]);
    int v2 = (delta2 == c[v]);
    for (auto k : g[v]) {
        if (!u[k]) {
            int delta = mn_all[k] - mn_not_all[k];
            if (delta == delta1) ++cnt1;
            if (delta == delta2) ++cnt2;
        }
    }
    showt(v, c[v], delta1, delta2, cnt1, cnt2, v1, v2, mn_all[v], mn_not_all[v]);
    for (auto k : g[v]) {
        if (!u[k]) {
            int ttype = 0;
            int delta = mn_all[k] - mn_not_all[k];
            if ((type & 1) && delta == delta1)
                ttype |= 2;
            if ((type & 1) && ((delta != delta1) || cnt1 + v1 > 1))
                ttype |= 1;
            if ((type & 2) && (delta == delta2))
                ttype |= 2;
            if ((type & 2) && (delta != delta2 || cnt2 > 1))
                ttype |= 1;
            showt("down to:", k, ttype);
            down(k, ttype);
        }
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    c.resize(n);
    u.assign(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    printTree(g, 0, c);
    mn_all.assign(n, inf);
    mn_not_all.assign(n, inf);
    dfs(0);
    show(mn_all);
    show(mn_not_all);
    u.assign(n, false);
    down(0);
    cout << mn_all[0] << ' ';
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v + 1 << ' ';
    }
    cout << '\n';
    return 0;
}