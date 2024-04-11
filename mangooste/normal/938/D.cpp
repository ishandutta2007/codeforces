#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> G(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        v--, u--;
        w *= 2;
        G[v].eb(u, w);
        G[u].eb(v, w);
    }
    vector<ll> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = a[i];
        pq.push(mp(-a[i], i));
    }
    while (!pq.empty()) {
        int v = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (d != dist[v]) {
            continue;
        }
        for (auto i : G[v]) {
            int u = i.first;
            ll w = i.second;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push(mp(-dist[u], u));
            }
        }
    }
    for (auto el : dist) {
        cout << el << ' ';
    }
    cout << '\n';
}