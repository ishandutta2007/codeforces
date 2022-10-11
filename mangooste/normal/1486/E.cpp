#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

const int A = 51;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<pr<int>>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
    }

    vec<vec<pr<int>>> ng(n);
    int sz = n;
    for (int i = 0; i < n; i++) {
        vec<vec<int>> classes(A);
        for (auto [j, w] : g[i])
            classes[w].push_back(j);
        vec<pr<int>> num(A);
        for (int i = 1; i < A; i++)
            if (len(classes[i])) {
                num[i].first = sz++;
                num[i].second = sz++;
                ng.push_back({});
                ng.push_back({});
                for (auto j : classes[i]) {
                    ng[j].emplace_back(num[i].first, 0);
                    ng[num[i].second].emplace_back(j, 0);
                }
            }

        for (int i = 1; i < A; i++)
            for (int j = i; j < A; j++)
                if (len(classes[i]) && len(classes[j])) {
                    ng[num[i].first].emplace_back(num[j].second, 2 * i * j + i * i + j * j);
                    ng[num[j].first].emplace_back(num[i].second, 2 * i * j + i * i + j * j);
                }
    }

    priority_queue<pr<ll, int>, vec<pr<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    vec<ll> dist(sz, INF);
    dist[0] = 0;
    while (len(pq)) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v])
            continue;
        for (auto [u, w] : ng[v])
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            dist[i] = -1;
        cout << dist[i] << ' ';
    }
    cout << '\n';
}