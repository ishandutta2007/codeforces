#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

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

    void add(int from, int to, T w, T cost) {
        g[from].push_back({to, int(g[to].size()), w, cost, 0});
        g[to].push_back({from, int(g[from].size()) - 1, 0, -cost, 0});
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
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(1 << n);
    for (auto &x : a)
        cin >> x;

    vector<vector<pair<int, int>>> best(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) % 2 != 0)
            continue;

        best[i].reserve(n);
        for (int j = 0; j < n; j++) {
            int k = i ^ (1 << j);
            best[i].emplace_back(a[i] + a[k], k);
        }

        sort(all(best[i]));
    }

    auto cmp = [&](int v, int u) {
        return best[v].back().first < best[u].back().first;
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < (1 << n); i++)
        if (__builtin_popcount(i) % 2 == 0)
            pq.push(i);

    int need = 2 * n * k;
    vector<array<int, 3>> edges;

    while (need-- && len(pq)) {
        int v = pq.top();
        pq.pop();
        edges.push_back({best[v].back().first, v, best[v].back().second});

        best[v].pop_back();
        if (len(best[v]))
            pq.push(v);
    }

    vector<int> vertexes;
    for (auto [c, v, u] : edges) {
        vertexes.push_back(v);
        vertexes.push_back(u);
    }

    sort(all(vertexes));
    vertexes.resize(unique(all(vertexes)) - vertexes.begin());

    int total = len(vertexes) + 2;
    int source = total - 2;
    int sink = total - 1;
    min_cost_flow<int> mcf(total);

    for (int i = 0; i < len(vertexes); i++)
        if (__builtin_popcount(vertexes[i]) % 2 == 0)
            mcf.add(source, i, 1, 0);
        else
            mcf.add(i, sink, 1, 0);

    auto get = [&](int x) {
        return lower_bound(all(vertexes), x) - vertexes.begin();
    };

    for (auto [c, v, u] : edges)
        mcf.add(get(v), get(u), 1, -c);

    cout << -mcf.solve(source, sink, k).first << '\n';
}