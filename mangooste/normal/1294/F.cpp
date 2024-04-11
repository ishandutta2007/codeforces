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

int n;
vector<vector<int>> G;
vector<int> parent, depth;

void dfs(int v, int pr) {
    parent[v] = pr;
    for (auto u : G[v]) {
        if (u != pr) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

pii dfs_find(int v, int pr, int h) {
    pii ans = mp(h, v);
    for (auto u : G[v]) {
        if (u != pr) {
            pii cur = dfs_find(u, v, h + 1);
            ans = max(ans, cur);
        }
    }
    return ans;
}

vector<int> get_way(int v, int u) {
    if (depth[v] < depth[u]) {
        swap(u, v);
    }
    vector<int> way;
    while (depth[v] != depth[u]) {
        way.pb(v);
        v = parent[v];
    }
    while (u != v) {
        way.pb(v);
        way.pb(u);
        u = parent[u];
        v = parent[v];
    }
    way.pb(v);
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
        G[v].pb(u);
        G[u].pb(v);
    }
    parent.resize(n);
    depth.resize(n);
    dfs(0, 0);
    int a = dfs_find(0, 0, 0).second;
    int b = dfs_find(a, a, 0).second;
    vector<int> way = get_way(a, b);
    queue<int> q;
    vector<int> dist(n, 2 * n + 1);
    for (auto el : way) {
        dist[el] = 0;
        q.push(el);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : G[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    pii c = mp(-1, -1);
    for (int i = 0; i < n; i++) {
        if (i != a && i != b) {
            c = max(c, mp(dist[i], i));
        }
    }
    cout << dist[c.second] + way.size() - 1 << '\n';
    cout << a + 1 << ' ' << b + 1 << ' ' << c.second + 1 << '\n';
}