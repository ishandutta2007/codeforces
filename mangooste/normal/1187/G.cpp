#include <bits/stdc++.h>

template<typename T>
struct min_cost_flow {
    struct edge {
        int to, rev;
        T capasity, cost, flow;
    };

    int n;
    std::vector<std::vector<edge>> g;

    min_cost_flow(int n = 0) : n(n), g(n) {}

    void add(int from, int to, T w, T cost) {
        g[from].push_back({to, int(g[to].size()), w, cost, 0});
        g[to].push_back({from, int(g[from].size()) - 1, 0, -cost, 0});
    }

    std::pair<T, T> solve(int source, int sink, T flow_limit = std::numeric_limits<T>::max()) {
        for (int v = 0; v < n; v++)
            for (int i = 0; i < int(g[v].size()); i++)
                g[v][i].flow = T(0);

        T cost = 0;
        T flow = 0;
        static constexpr T INF = std::numeric_limits<T>::max();
        std::vector<T> potential(n);

        auto build_potential = [&]() {
            std::fill(potential.begin(), potential.end(), INF);
            potential[source] = 0;
            while (true) {
                bool any = false;
                for (int v = 0; v < n; v++)
                    for (const auto &[u, rev, capasity, cost, flow] : g[v])
                        if (capasity != 0 && potential[v] != INF && potential[v] + cost < potential[u]) {
                            potential[u] = potential[v] + cost;
                            any = true;
                        }

                if (!any)
                    break;
            }
        };
        build_potential();

        std::vector<std::pair<int, int>> parent(n);
        std::vector<std::pair<T, T>> dist(n);

        auto dijkstra = [&]() {
            std::fill(dist.begin(), dist.end(), std::pair<T, T>{INF, flow_limit - flow});
            dist[source].first = 0;

            std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> q;
            q.push({0, source});

            while (q.size()) {
                const auto [cur_dist, v] = q.top();
                q.pop();

                if (cur_dist > dist[v].first)
                    continue;

                for (const auto &[u, rev, capasity, cost, flow] : g[v])
                    if (cur_dist + cost - potential[u] + potential[v] < dist[u].first && flow < capasity) {
                        parent[u] = {v, rev};
                        dist[u] = {cur_dist + cost - potential[u] + potential[v], std::min(dist[v].second, capasity - flow)};
                        q.push({dist[u].first, u});
                    }
            }
            return dist[sink].first != INF;
        };

        while (flow < flow_limit && dijkstra()) {
            T delta = dist[sink].second;
            flow += delta;
            for (int v = sink; v != source; v = parent[v].first) {
                cost -= g[v][parent[v].second].cost * delta;
                g[v][parent[v].second].flow -= delta;
                g[parent[v].first][g[v][parent[v].second].rev].flow += delta;

            }

            for (int i = 0; i < n; i++)
                if (dist[i].first != INF)
                    potential[i] += dist[i].first;
        }
        return {cost, flow};
    }
};

int main() {
    using namespace std;
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;
    const int TIME = n + k + 4;

    int source = TIME * n;
    int sink = source + 1;
    min_cost_flow<long long> g(sink + 1);
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        g.add(source, v - 1, 1, 0);
    }

    for (int t = 0; t < TIME; t++)
        g.add(t * n, sink, k, 0);

    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;

        for (int rot = 0; rot < 2; rot++, swap(v, u))
            for (int t = 0; t < TIME - 1; t++)
                for (int i = 0; i < k; i++)
                    g.add(t * n + v, (t + 1) * n + u, 1, d * (2 * i + 1) + c);
    } 

    for (int i = 0; i < n; i++)
        for (int t = 0; t < TIME - 1; t++)
            g.add(t * n + i, (t + 1) * n + i, k, c);

    cout << g.solve(source, sink).first << '\n';
}