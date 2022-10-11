#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_A = 100;
const int MAX_N = 3000;
const int SUM = MAX_N + MAX_A + MAX_N + 2;

struct Edge {
    int vertex, index, w;
};

int edge_index, s, t;
vector<Edge> graph[SUM];
vector<int> flow;
int dist[SUM], head[SUM];

void add_edge(int v, int u, int w) {
    graph[v].push_back({u, edge_index++, w});
    graph[u].push_back({v, edge_index++, 0});
    flow.push_back(0), flow.push_back(0);
}

int dfs(int v, int min_edge = INT_MAX) {
    if (v == t)
        return min_edge;
    for (; head[v] < int(graph[v].size()); head[v]++) {
        auto [u, index, w] = graph[v][head[v]];
        if (dist[u] == dist[v] + 1 && flow[index] != w)
            if (int result = dfs(u, min(min_edge, w - flow[index]))) {
                flow[index] += result, flow[index ^ 1] -= result;
                return result;
            }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> values(n);
    for (auto &x : values)
        cin >> x;
    vector<int> costs(n);
    for (auto &x : costs)
        cin >> x;

    s = n + MAX_A + n, t = s + 1;
    vector<int> fective(MAX_A);
    iota(fective.begin(), fective.end(), n);
    int free = n + MAX_A;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (costs[i] < 0)
            add_edge(i, t, -costs[i]);
        else
            add_edge(s, i, costs[i]), ans += costs[i];
        for (int j = 1; j <= values[i]; j++)
            if (values[i] % j == 0)
                add_edge(i, fective[j - 1], INF);

        add_edge(free, fective[values[i] - 1], INF);
        fective[values[i] - 1] = free;
        add_edge(free++, i, INF);
    }

    while (true) {
        fill(dist, dist + SUM, INF);
        dist[s] = 0;
        queue<int> vertexes;
        vertexes.push(s);
        while (!vertexes.empty()) {
            int v = vertexes.front();
            vertexes.pop();
            for (auto [u, index, w] : graph[v])
                if (flow[index] != w && dist[u] > dist[v] + 1)
                    dist[u] = dist[v] + 1, vertexes.push(u);
        }
        if (dist[t] == INF)
            break;

        memset(head, 0, sizeof(head));
        while (int delta = dfs(s))
            ans -= delta;
    }
    cout << ans << '\n';
}