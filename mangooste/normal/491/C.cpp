#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define ts to_string
#define sts string ts
sts(string s) { return s; }
sts(bool b) { return b ? "true" : "false"; }
sts(char c) { return string(1, c); }
sts(const char* s) { return (string) s; }
template<class A, class B> sts(pair<A, B>);
template<class T> sts(T v) { string s = "{", sep = ""; for (auto x : v) { s += sep; sep = ", "; s += ts(x); } return s + "}"; }
template<class A, class B> sts(pair<A, B> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
void dbgPrint() { cerr << endl; }
template<class A, class... B> void dbgPrint(A a, B... b) { cerr << ' ' << ts(a); dbgPrint(b...); }
#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()


struct MinCostMaxFlow {
    int n;
    int start, finish;
    vector<vector<tuple<int, int, int, int>>> g;

    int curId;
    vector<int> flow;
    vector<tuple<int, int, int, int>> edges;

    MinCostMaxFlow(int n, int start, int finish) :
        n(n), start(start), finish(finish), g(vector<vector<tuple<int, int, int, int>>>(n)), curId(0)
    {}

    inline void addEdge(int v, int u, int w, int cost) {
        g[v].emplace_back(u, curId, w, cost);
        g[u].emplace_back(v, curId + 1, 0, -cost);
        curId += 2;

        flow.push_back(0);
        flow.push_back(0);

        edges.emplace_back(v, u, w, cost);
        edges.emplace_back(u, v, 0, -cost);
    }

    const __int128 INF = (__int128) 1e18;

    vector<__int128> p;

    inline void buildP() {
        p = vector<__int128>(n, INF);
        p[start] = 0;
        while (true) {
            bool any = false;
            for (auto [v, u, w, cost] : edges) {
                if (w == 0) continue;
                if (p[v] == INF) continue;
                if (p[u] <= p[v] + cost) continue;
                p[u] = p[v] + cost;
                any = true;
            }
            if (!any) break;
        }
    }

    vector<__int128> dist;
    vector<int> parent;

    inline bool dijkstra() {
        dist = vector<__int128>(n, INF);
        dist[start] = 0;
        parent = vector<int>(n, -1);

        priority_queue<pair<__int128, int>, vector<pair<__int128, int>>, less<pair<__int128, int>>> q;
        q.push({ 0, start });
        while (sz(q)) {
            auto [curDist, v] = q.top();
            q.pop();
            if (dist[v] != curDist) continue;

            for (auto [u, index, w, cost] : g[v]) {
                if (flow[index] == w) continue;
                if (dist[u] <= dist[v] + cost + p[u] - p[v]) continue;
                dist[u] = dist[v] + cost + p[u] - p[v];
                q.push({ dist[u], u });
                parent[u] = index;
            }
        }
        return parent[finish] != -1;
    }

    inline void solve(int k) {
        int cost = 0;
        buildP();
        while (dijkstra()) {
            int curFlow = INT_MAX;
            for (int v = finish; v != start; v = get<0>(edges[parent[v]])) {
                curFlow = min(curFlow, get<2>(edges[parent[v]]) - flow[parent[v]]);
            }
            for (int v = finish; v != start; v = get<0>(edges[parent[v]])) {
                cost += curFlow * get<3>(edges[parent[v]]);
                flow[parent[v]] += curFlow;
                flow[parent[v] ^ 1] -= curFlow;
            }

            for (int i = 0; i < n; i++) {
                p[i] += dist[i];
            }
        }

        cout << -cost << '\n';
        for (int v = 0; v < k; v++) {
            int to = -1;
            for (auto [u, index, w, cost] : g[v]) {
                if (w == 0) continue;
                if (flow[index] == w) {
                    assert(to == -1);
                    to = u;
                }
            }
            assert(to != -1);
            to -= k;
            if (to < 26) {
                putchar('a' + to);
            } else {
                putchar('A' + to - 26);
            }
        }
        cout << '\n';
    }
};

inline int getId(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> costs(k, vector<int>(k, 0));
    string a;
    cin >> a;
    string b;
    cin >> b;
    for (int i = 0; i < n; i++) {
        costs[getId(a[i])][getId(b[i])]++;
    }

    MinCostMaxFlow g(k * 2 + 2, k * 2, k * 2 + 1);
    for (int i = 0; i < k; i++) {
        g.addEdge(k * 2, i, 1, 0);
        g.addEdge(k + i, k * 2 + 1, 1, 0);
        for (int j = 0; j < k; j++) {
            g.addEdge(i, k + j, 1, -costs[i][j]);
        }
    }
    g.solve(k);
}