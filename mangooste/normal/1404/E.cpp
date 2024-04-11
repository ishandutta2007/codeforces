#include <bits/stdc++.h>

template<typename T>
struct push_relabel {
    struct edge {
        int to, rev;
        T capasity, flow;
    };

    int n;
    std::vector<std::vector<edge>> g;

    push_relabel(int n) : n(n), g(n) {}

    int size() const {
        return n;
    }

    void add(int from, int to, T forward_capasity, T backward_capasity = 0) {
        g[from].push_back({to, int(g[to].size()), forward_capasity, 0});
        g[to].push_back({from, int(g[from].size()) - 1, backward_capasity, 0});
    }

    template<typename U>
    U solve(int source, int sink) {
        for (int v = 0; v < n; v++)
            for (auto &e : g[v])
                e.flow = 0;

        std::vector<int> height(n), count(n + 1);
        count[0] = n;
        std::vector<U> excess(n);
        std::vector<bool> activated(n);
        activated[sink] = true;
        std::vector<std::vector<int>> layers(n);
        int layer = 0;

        auto activate = [&](int v) {
            if (!activated[v] && excess[v] > 0 && height[v] < n) {
                layer = std::max(layer, height[v]);
                layers[height[v]].push_back(v);
                activated[v] = true;
            }
        };

        auto push = [&](int v) {
            for (auto &e : g[v])
                if (height[e.to] == height[v] - 1) {
                    T pushed = std::min<U>(e.capasity - e.flow, excess[v]);
                    if (pushed > 0) {
                        e.flow += pushed;
                        g[e.to][e.rev].flow -= pushed;
                        excess[v] -= pushed;
                        excess[e.to] += pushed;
                        activate(e.to);
                        if (excess[v] == 0)
                            break;
                    }
                }
        };

        auto relabel = [&](int v) {
            count[height[v]]--;
            height[v] = n;
            for (auto &e : g[v])
                if (e.flow < e.capasity)
                    height[v] = std::min(height[v], height[e.to] + 1);

            activate(v);
            count[height[v]]++;
        };

        for (auto &e : g[source])
            excess[source] += e.capasity;

        activate(source);
        while (layer >= 0) {
            if (layers[layer].empty()) {
                layer--;
                continue;
            }

            int v = layers[layer].back();
            layers[layer].pop_back();
            activated[v] = false;

            push(v);
            if (excess[v] > 0) {
                if (count[height[v]] == 1) {
                    layer = height[v];
                    for (int u = 0; u < n; u++)
                        if (height[u] >= layer) {
                            count[height[u]]--;
                            height[u] = n;
                            count[height[u]]++;
                            activate(u);
                        }
                } else {
                    relabel(v);
                }
            }
        }
        return excess[sink];
    }
};

int main() {
    using namespace std;
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m >> ws;
    vector<string> a(n);
    for (auto &s : a)
        getline(cin, s);

    int source = n * m;
    int sink = n * m + 1;
    push_relabel<int> g(n * m + 2);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '#') {
                if (i == 0 || a[i - 1][j] != '#')
                    g.add(source, i * m + j, 1);
                else
                    g.add((i - 1) * m+ j, i * m + j, 1);

                if (j == 0 || a[i][j - 1] != '#')
                    g.add(i * m + j, sink, 1);
                else
                    g.add(i * m + j, i * m + j - 1, 1);
            }

    cout << g.solve<int>(source, sink) << '\n';
}