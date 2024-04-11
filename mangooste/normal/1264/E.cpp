#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename T>
struct min_cost_flow {
    struct edge {
        int to, rev;
        T capasity, cost, flow;
    };

    int n;
    std::vector<std::vector<edge>> g;

    min_cost_flow(int n = 0) : n(n), g(n) {}

    int size() const {
        return n;
    }

    int add(int from, int to, T capasity, T cost) {
        int id = g[from].size();
        g[from].push_back({to, int(g[to].size()) + (from == to), capasity, cost, 0});
        g[to].push_back({from, id, 0, -cost, 0});
        return id;
    }

    std::pair<T, T> solve(int source, int sink, T flow_limit = std::numeric_limits<T>::max()) {
        for (int v = 0; v < n; v++)
            for (edge &e : g[v])
                e.flow = 0;

        T cost = 0, flow = 0;
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
                    if (potential[u] != INF && cur_dist + cost - potential[u] + potential[v] < dist[u].first && flow < capasity) {
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
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector know(n, vector<bool>(n));
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        know[v][u] = true;
    }

    int source = n + n * n + n * n, sink = source + 1;
    min_cost_flow<int> mcf(sink + 1);
    vector id(n, vector<int>(n, -1));
    for (int row = 0; row < n; row++) {
        auto f = [&](int x) {
            return -x * x + (n - 1) * x;
        };
        for (int flow = 1; flow < n; flow++) {
            mcf.add(source, row, 1, f(flow) - f(flow - 1));
        }

        for (int col = 0; col < n; col++) {
            if (row == col) continue;
            mcf.add(row, n + row * n + col, 1, 0);
            if (col < row) continue;

            int common = n + n * n + n * row + col;
            mcf.add(common, sink, 1, 0);
            if (know[row][col] || know[col][row]) {
                if (know[row][col]) {
                    mcf.add(n + row * n + col, common, 1, 0);
                } else {
                    mcf.add(n + col * n + row, common, 1, 0);
                }
            } else {
                id[row][col] = mcf.add(n + row * n + col, common, 1, 0);
                id[col][row] = mcf.add(n + col * n + row, common, 1, 0);
            }
        }
    }

    mcf.solve(source, sink);
    dbg(mcf.solve(source, sink));

    vector ans(n, vector<int>(n));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (know[row][col]) ans[row][col] = 1;
            if (col <= row || know[row][col] || know[col][row]) continue;
            if (mcf.g[n + row * n + col][id[row][col]].flow) {
                ans[row][col] = 1;
            } else {
                assert(mcf.g[n + col * n + row][id[col][row]].flow);
                ans[col][row] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}