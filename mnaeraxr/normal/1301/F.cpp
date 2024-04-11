#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <assert.h>

#define endl '\n'

using namespace std;

struct FastDijkstra {
    vector<vector<int>> nodes;
    int distance, pos;

    FastDijkstra() {
        nodes = vector<vector<int>>(3);
        distance = pos = 0;
    }

    bool empty() {
        for (auto &x : nodes)
            if (!x.empty()) return false;
        return true;
    }

    pair<int,int> pop() {
        while (nodes[distance % 3].empty())
            distance++;
        int d = distance % 3;
        int u = nodes[d].back(); nodes[d].pop_back();
        return {u, distance};
    }

    void push(int u, int d) {
        while (distance < d && nodes[distance % 3].empty())
            ++distance;
        int dx = d - distance;
        assert(0 <= dx && dx <= 2);
        nodes[d % 3].push_back(u);
    }
};

vector<short> dijkstra(vector<vector<pair<int,int>>> &graph, int s) {
    vector<short> dist(graph.size(), 0x3f3f);
    dist[s] = 0;

    FastDijkstra fd;
    fd.push(s, 0);

    while (!fd.empty()) {
        auto cur = fd.pop();

        int v = cur.first;
        int d = cur.second;

        if (dist[v] < d)
            continue;

        for (auto e : graph[v]) {
            int nd = d + e.second;
            int nv = e.first;

            if (dist[nv] > nd) {
                dist[nv] = nd;
                fd.push(nv, nd);
            }
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> graph(n * m + k);

    const int dx[4] = {0, -1, 0, +1};
    const int dy[4] = {-1, 0, +1, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c; cin >> c; c--;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];

                int uix = i * m + j;

                graph[uix].push_back({n * m + c, 1});
                graph[n * m + c].push_back({uix, 1});

                if (0 <= x && x < n && 0 <= y && y < m) {
                    int vix = x * m + y;
                    graph[uix].push_back({vix, 2});
                }
            }
        }
    }

    vector<vector<short>> distances(k);

    for (int i = 0; i < k; ++i) {
        distances[i] = dijkstra(graph, n * m + i);
    }

    int q; cin >> q;

    while (q-->0) {
        short x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        short answer = 2 * (abs(x1 - x2) + abs(y1 - y2));

        int ix1 = x1 * m + y1;
        int ix2 = x2 * m + y2;

        for (int c = 0; c < k; ++c) {
            short cur = distances[c][ix1] + distances[c][ix2];
            answer = min(answer, cur);
        }

        assert(answer % 2 == 0);

        cout << answer / 2 << endl;
    }

    return 0;
}