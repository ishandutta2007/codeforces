#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>
#include <queue>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> s(k);

    for (int i = 0; i < k; ++i) {
        cin >> s[i]; s[i]--;
    }

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    auto bfs = [&](int s) {
        vector<int> dist(n, n);
        dist[s] = 0;
        queue<int> q; q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : graph[u]) {
                if (dist[v] == n) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    };

    auto d0 = bfs(0);
    auto d1 = bfs(n - 1);

    sort(s.begin(), s.end(), [&](int u, int v) {
        return d1[u] < d1[v];
    });

    int answer = d0[n - 1];

    int new_dist = 0;

    for (int i = 1; i < s.size(); ++i) {
        int u = s[i], v = s[i - 1];
        new_dist = max(d0[u] + 1 + d1[v], new_dist);
    }

    answer = min(answer, new_dist);

    cout << answer << endl;

    return 0;
}