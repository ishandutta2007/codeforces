#include <bits/stdc++.h>

using namespace std;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> g(N * 2);
    constexpr static auto id = [](int x, int y) {
        return x << 1 | y;
    };

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[id(u, 0)].emplace_back(w, id(v, 0));
        g[id(v, 1)].emplace_back(w, id(u, 1));
    }

    for (int i = 0; i < N; i++)
        g[id(i, 0)].emplace_back(0, id(i, 1));

    vector<int64_t> d(N * 2, -1);
    min_heap<pair<int64_t,int>> pq;
    const int src = id(0, 0);
    pq.emplace(d[src] = 0, src);
    while (!pq.empty()) {
        auto [dd, i] = pq.top(); pq.pop();
        if (dd != d[i]) continue;

        for (auto [w, j]: g[i]) {
            if (d[j] == -1 || d[j] > d[i] + w) {
                d[j] = d[i] + w;
                pq.emplace(d[j], j);
            }
        }
    }

    for (int i = 1; i < N; i++) {
        cout << d[id(i, 1)] << (i+1==N ? '\n' : ' ');
    }
}