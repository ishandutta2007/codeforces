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
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(4 * n);
    forn (i, 0, m) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        v *= 4;
        u *= 4;

        forn (rep, 0, 2) {
            g[v].emplace_back(u, w);
            g[v].emplace_back(u + 1, 0);
            g[v].emplace_back(u + 2, 2 * w);
            g[v].emplace_back(u + 3, w);

            g[v + 1].emplace_back(u + 1, w);
            g[v + 1].emplace_back(u + 3, 2 * w);

            g[v + 2].emplace_back(u + 2, w);
            g[v + 2].emplace_back(u + 3, 0);

            g[v + 3].emplace_back(u + 3, w);
            swap(v, u);
        }
    }

    vector<ll> dist(4 * n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (len(pq)) {
        auto [cur, v] = pq.top();
        pq.pop();
        if (cur != dist[v]) continue;

        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }

    forn (i, 1, n) cout << dist[4 * i + 3] << " \n"[i == n - 1];
}