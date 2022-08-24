#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;

const int inf = 1e7;
class DinitzFlow {
private:
    struct Edge {
        int src, dst, cap, flow;

        Edge() {
        }

        Edge(int src, int dst, int cap, int flow)
            : src(src), dst(dst), cap(cap), flow(flow) {
        }
    };

    int n, s, t;
    vector<Edge> edges;
    vector< vector<int> > g;
    vector<int> layer;
    vector<int> ptr;

    inline bool bfs() {
        layer.assign(n, -1);
        queue<int> q;
        layer[s] = 0;
        q.push(s);
        while (!q.empty() && layer[t] < 0) {
            int v = q.front(); q.pop();
            for (int eid: g[v]) {
                int to = edges[eid].dst;
                if (edges[eid].cap > edges[eid].flow) {
                    if (layer[to] < 0) {
                        layer[to] = layer[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
        return layer[t] >= 0;
    }

    int dfs(int v, int flow = inf) {
        if (v == t) {
            return flow;
        }
        if (flow == 0) {
            return 0;
        }
        for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
            int eid = g[v][ptr[v]];
            int to = edges[eid].dst;
            if (layer[to] == layer[v] + 1) {
                int can = edges[eid].cap - edges[eid].flow;
                int pushed = dfs(to, min(flow, can));
                if (pushed > 0) {
                    edges[eid].flow += pushed;
                    edges[eid^1].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
public:
    inline void changeSrcDst(int ns, int nt) {
        s = ns; t = nt;
        for (Edge &e : edges) {
            e.flow = 0;
        }
    }

    inline const vector<Edge> &getEdges() const {
        return edges;
    }

    inline vector<char> getCut() {
        // side[i] = 1 if the vertex is in component of s after the cut
        // side[i] = 0 otherwise (even if the vertex is not in component of t)
        vector<char> side(n, 0);

        function<void(int)> dfs = [&](int v) {
            if (side[v]) {
                return;
            }
            side[v] = 1;
            for (int eid : g[v]) {
                if (edges[eid].cap == edges[eid].flow) {
                    continue;
                }
                dfs(edges[eid].dst);
            }
        };

        dfs(s);
        return side;
    }

    inline int flow() {
        int ans = 0;
        while (bfs()) {
            ptr.assign(n, 0);
            int pushed = dfs(s);
            while (pushed != 0) {
                ans += pushed;
                pushed = dfs(s);
            }
        }
        return ans;
    }

    inline void addEdge(int src, int dst, int cap) {
        g[src].push_back(edges.size());
        edges.emplace_back(src, dst, cap, 0);
        g[dst].push_back(edges.size());
        edges.emplace_back(dst, src, 0, 0);
    }

    DinitzFlow(int n, int s, int t)
        : n(n), s(s), t(t), g(n), layer(n), ptr(n) {
    }
};
const int maxN = 205;
char c[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    DinitzFlow ds(2 * n * m + 3, 2 * n * m, 2 * n * m + 1);
    int s = 2 * n * m;
    int t = 2 * n * m + 1;
    // x 0 .. n * m - 1
    // y
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = i * m + j;
            int valx = val;
            int valy = val + n * m;
            if (c[i][j] == '.') {
                ds.addEdge(s, valx, inf);
                ds.addEdge(valy, t, inf);
                continue;
            }
            ds.addEdge(valy, valx, inf);
            ds.addEdge(valx, valy, inf);
            if (i == n - 1) {
                ds.addEdge(s, valx, 1);
            }
            else {
                ds.addEdge((i + 1) * m + j, valx, 1);
            }
            if (j == m - 1) {
                ds.addEdge(valy, t, 1);
            }
            else {
                ds.addEdge(valy, i * m + (j + 1) + n * m, 1);
            }
        }
    }
    auto it = ds.flow();
    cout << it << '\n';
    return 0;
}