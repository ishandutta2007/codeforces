#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define int long long
const ll infinity = 1e15;
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

    int dfs(int v, int flow = infinity) {
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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int s = n + m + 1;
    int t = n + m + 2;
    DinitzFlow dn(n + m + 3, s, t);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dn.addEdge(i, t, x);
    }
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dn.addEdge(s, n + i, w);
        dn.addEdge(n + i, u, infinity / 10);
        dn.addEdge(n + i, v, infinity / 10);
        pos += w;
    }
    int x = dn.flow();
    cout << pos - x << '\n';
    return 0;
}