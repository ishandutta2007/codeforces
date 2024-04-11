#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
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

int n;
vector<int> a;
vector<vector<int>> g;

int timer;
vector<int> tin;
vector<int> tout;
map<int, vector<int>> positions;

vector<char> dp;
int ans;

void dfsInit(int v, int par) {
    positions[a[v]].push_back(timer);
    tin[v] = timer++;
    for (auto u : g[v]) {
        if (u == par) continue;
        dfsInit(u, v);
    }
    tout[v] = timer;
}

inline int getNum(vector<int> &positions, int l, int r) {
    return int(lower_bound(all(positions), r) - lower_bound(all(positions), l));
}

void dfsDp(int v, int par) {
    for (auto u : g[v]) {
        if (u == par) continue;
        dfsDp(u, v);
        dp[v] &= dp[u];
    }
    dp[v] &= getNum(positions[a[v]], tin[v], tout[v]) == 1;
}

void dfsSolve(int v, int par) {
    if (len(positions[a[v]]) - getNum(positions[a[v]], tin[v], tout[v])) return;
    ans += dp[v];
    int sum = 0;
    for (auto u : g[v]) {
        if (u == par) continue;
        sum += !dp[u];
    }
    for (auto u : g[v]) {
        if (u == par) continue;
        if (len(positions[a[v]]) - getNum(positions[a[v]], tin[u], tout[u]) > 1) continue;
        if (sum - !dp[u]) continue;
        dfsSolve(u, v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    g.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    tin.resize(n);
    tout.resize(n);
    dfsInit(0, 0);

    dp.resize(n, 1);
    dfsDp(0, 0);

    dfsSolve(0, 0);
    cout << ans << '\n';
}