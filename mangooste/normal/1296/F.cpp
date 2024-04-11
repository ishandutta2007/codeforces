#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int n, m;
vector<vector<pii>> G;
int timer = 0;
vector<int> tin, tout;
vector<pii> parent;
vector<vector<int>> ways;
vector<int> g, ans;

void dfs(int v, int pr) {
    tin[v] = timer++;
    for (auto i : G[v]) {
        int u = i.first;
        if (u != pr) {
            parent[u] = mp(v, i.second);
            dfs(u, v);
        }
    }
    tout[v] = timer++;
}

bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

vector<int> get_way(int v, int u) {
    vector<int> way;
    while (!is_par(v, u)) {
        way.pb(parent[v].second);
        v = parent[v].first;
    }
    while (u != v) {
        way.pb(parent[u].second);
        u = parent[u].first;
    }
    sort(all(way));
    return way;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].eb(u, i);
        G[u].eb(v, i);
    }
    tin.resize(n);
    tout.resize(n);
    parent.resize(n, mp(-1, -1));
    dfs(0, 0);
    int m;
    cin >> m;
    ways.resize(m);
    g.resize(m);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u >> g[i];
        v--, u--;
        ways[i] = get_way(v, u);
        assert(ways[i].size() != 0);
    }
    int mx = *max_element(all(g));
    ans.resize(n - 1, -1);
    vector<int> inds(m);
    iota(all(inds), 0);
    sort(all(inds), [&](int i, int j) {
        return g[i] < g[j];
    });
    for (auto ind : inds) {
        for (auto el : ways[ind]) {
            ans[el] = g[ind];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == -1) {
            ans[i] = mx;
        }
    }
    for (int i = 0; i < m; i++) {
        int mn = ans[ways[i][0]];
        for (auto el : ways[i]) {
            mn = min(mn, ans[el]);
        }
        if (mn != g[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    for (auto el : ans) {
        if (el == -1) {
            cout << mx << ' ';
        } else {
            cout << el << ' ';
        }
    }
    cout << '\n';
}