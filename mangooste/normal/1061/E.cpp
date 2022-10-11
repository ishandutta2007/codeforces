#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<class W, class C = W>
struct MCMF {
    int n;
    int s, t;
    vector<vector<tuple<int, int, W, C>>> g;

    int curId;
    vector<W> flow;
    vector<tuple<int, int, W, C>> edges;

    static constexpr C INF_C = numeric_limits<C>::max();
    static constexpr W INF_W = numeric_limits<W>::max();

    MCMF() {}

    MCMF(int n, int s, int t) :
        n(n), s(s), t(t), g(vector<vector<tuple<int, int, W, C>>>(n)), curId(0)
    {}

    inline void addEdge(int v, int u, W w, C cost) {
        g[v].emplace_back(u, curId, w, cost);
        g[u].emplace_back(v, curId + 1, 0, -cost);

        curId += 2;

        flow.push_back(0);
        flow.push_back(0);

        edges.emplace_back(v, u, w, cost);
        edges.emplace_back(u, v, 0, -cost);
    }

    inline pair<C, W> addWay(vector<int> &parent) {
        W curFlow = INF_W;
        for (int v = t; v != s; v = get<0>(edges[parent[v]]))
            curFlow = min(curFlow, get<2>(edges[parent[v]]) - flow[parent[v]]);

        C deltaCost = 0;
        for (int v = t; v != s; v = get<0>(edges[parent[v]])) {
            deltaCost += curFlow * get<3>(edges[parent[v]]);
            flow[parent[v]] += curFlow;
            flow[parent[v] ^ 1] -= curFlow;
        }

        return {deltaCost, curFlow};
    }

    inline pair<C, W> minCostMaxFlowDijkstra() {
        C cost = 0;
        W maxFlow = 0;

        vector<C> pat(n);

        auto buildPat = [&]() {
            fill(pat.begin(), pat.end(), INF_C);
            pat[s] = 0;

            while (true) {
                bool any = false;
                for (const auto &[v, u, w, cost] : edges) {
                    if (w == 0 || pat[v] == INF_C || pat[u] <= pat[v] + cost)
                        continue;

                    pat[u] = pat[v] + cost;
                    any = true;
                }

                if (!any)
                    break;
            }
        };

        buildPat();

        vector<C> dist(n);
        vector<int> parent(n);

        auto dijkstra = [&]() {
            fill(dist.begin(), dist.end(), INF_C);
            dist[s] = 0;
            fill(parent.begin(), parent.end(), -1);

            priority_queue<pair<C, int>, vector<pair<C, int>>, greater<pair<C, int>>> q;
            q.push({ 0, s });

            while (q.size()) {
                auto [curDist, v] = q.top();
                q.pop();

                if (dist[v] != curDist)
                    continue;

                for (const auto &[u, index, w, cost] : g[v]) {
                    if (flow[index] == w)
                        continue;

                    if (dist[u] <= dist[v] + cost + pat[u] - pat[v])
                        continue;

                    dist[u] = dist[v] + cost + pat[u] - pat[v];
                    q.push({ dist[u], u });
                    parent[u] = index;
                }
            }
            return parent[t] != -1;
        };

        while (dijkstra()) {
            const auto [deltaCost, deltaFlow] = addWay(parent);
            cost += deltaCost;
            maxFlow += deltaFlow;

            for (int i = 0; i < n; i++)
                if (dist[i] != INF_C)
                    pat[i] += dist[i];
        }
        return {cost, maxFlow};
    }

    inline pair<C, W> minCostMaxFlowFordBellmanQueue() {
        C cost = 0;
        W maxFlow = 0;

        queue<int> que;
        vector<char> inQue(n);

        vector<C> dist(n);
        vector<int> parent(n);

        auto fordBellmanQueue = [&]() {
            fill(dist.begin(), dist.end(), INF_C);
            dist[s] = 0;
            fill(parent.begin(), parent.end(), -1);

            que.push(s);
            inQue[s] = 1;
            while (que.size()) {
                int v = que.front();
                inQue[v] = 0;
                que.pop();

                for (const auto &[u, index, w, cost] : g[v]) {
                    if (flow[index] == w)
                        continue;

                    if (dist[u] <= dist[v] + cost)
                        continue;

                    dist[u] = dist[v] + cost;
                    parent[u] = index;

                    if (!inQue[u]) {
                        inQue[u] = 1;
                        que.push(u);
                    }
                }
            }
            return parent[t] != -1;
        };

        while (fordBellmanQueue()) {
            const auto [deltaCost, deltaFlow] = addWay(parent);
            cost += deltaCost;
            maxFlow += deltaFlow;
        }
        return {cost, maxFlow};
    }

    inline pair<C, W> minCostMaxFlowFordBellman() {
        C cost = 0;
        W maxFlow = 0;

        vector<C> dist(n);
        vector<int> parent(n);

        auto fordBelman = [&]() {
            fill(dist.begin(), dist.end(), INF_C);
            dist[s] = 0;
            fill(parent.begin(), parent.end(), -1);

            while (true) {
                bool any = false;
                for (int i = 0; i < int(edges.size()); i++) {
                    const auto &[v, u, w, cost] = edges[i];
                    if (flow[i] == w || dist[v] == INF_C || dist[u] <= dist[v] + cost)
                        continue;

                    dist[u] = dist[v] + cost;
                    parent[u] = i;
                    any = true;
                }

                if (!any)
                    break;
            }

            return parent[t] != -1;
        };

        while (fordBelman()) {
            const auto [deltaCost, deltaFlow] = addWay(parent);
            cost += deltaCost;
            maxFlow += deltaFlow;
        }
        return {cost, maxFlow};
    }
};


int dfs(int v, int par, vec<vec<int>> &g, vec<int> &need, MCMF<int> &dinic, bool swapped, int shift) {
    int sum = 0;

    for (auto u : g[v]) {
        if (u == par)
            continue;

        if (need[u] == -1) {
            if (swapped)
                dinic.addEdge(shift + u, shift + v, len(g), 0);
            else
                dinic.addEdge(shift + v, shift + u, len(g), 0);
        }

        sum += dfs(u, v, g, need, dinic, swapped, shift);
    }

    if (need[v] != -1) {
        if (need[v] < sum) {
            cout << "-1\n";
            exit(0);
        }

        if (swapped)
            dinic.addEdge(shift + v, dinic.t, need[v] - sum, 0);
        else
            dinic.addEdge(dinic.s, shift + v, need[v] - sum, 0);

        sum = need[v];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, r1, r2;
    cin >> n >> r1 >> r2;
    r1--, r2--;

    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    MCMF<int> dinic(2 * n + 2, 2 * n, 2 * n + 1);

    auto read_graph = [&]() {
        vec<vec<int>> g(n);
        for (int i = 1; i < n; i++) {
            int v, u;
            cin >> v >> u;
            v--, u--;

            g[v].push_back(u);
            g[u].push_back(v);
        }

        return g;
    };

    auto g1 = read_graph();
    auto g2 = read_graph();

    auto read_need = [&]() {
        int q;
        cin >> q;

        vec<int> need(n, -1);
        while (q--) {
            int v;
            cin >> v;
            v--;

            cin >> need[v];
        }

        return need;
    };

    auto need1 = read_need();
    auto need2 = read_need();

    dfs(r1, r1, g1, need1, dinic, false, 0);
    dfs(r2, r2, g2, need2, dinic, true, n);

    for (int i = 0; i < n; i++)
        dinic.addEdge(i, i + n, 1, -a[i]);

    auto [answer, flow] = dinic.minCostMaxFlowFordBellman();

    if (flow == need1[r1] && flow == need2[r2])
        cout << -answer << '\n';
    else
        cout << "-1\n";
}