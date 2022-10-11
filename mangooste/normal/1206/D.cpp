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
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const int INF = 1e9;
vector<vector<int>> G;

int bfs(int start, int n) {
    vector<int> parent(n);
    parent[start] = start;
    vector<int> dist(n, INF);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    int cur_ans = INF;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : G[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
                parent[u] = v;
            } else if (u != parent[v])
                cur_ans = min(cur_ans, dist[v] + dist[u] + 1);
        }
    }
    return cur_ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    const int Log = 61;
    vector<vector<int>> bits(Log);
    for (int i = 0; i < n; i++) {
        ll el;
        cin >> el;
        for (ll bit = 0; bit < Log; bit++)
            if (el & (1ll << bit))
                bits[bit].pb(i);
    }
    for (int i = 0; i < Log; i++)
        if (bits[i].size() >= 3)
            return cout << "3\n", 0;
    int ans = INF;
    G.resize(n);
    for (int i = 0; i < Log; i++)
        if (bits[i].size() == 2) {
            int v = bits[i][0];
            int u = bits[i][1];
            G[v].pb(u);
            G[u].pb(v);
        }
    for (auto &el : G) {
        sort(all(el));
        el.resize(unique(all(el)) - el.begin());
    }
    for (int i = 0; i < n; i++)
        if (G[i].size() > 1)
            ans = min(ans, bfs(i, n));
    cout << (ans == INF ? -1 : ans) << '\n';
}