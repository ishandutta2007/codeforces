#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int infinity = 1e9;
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
const int maxN = 5e4 + 10;
int a[maxN];
int id[maxN];
vector<int> divs[maxN];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    DinitzFlow ds(4 * n + 2, 4 * n, 4 * n + 1);
    for (int i = 0; i < n; i++) {
        ds.addEdge(i + 3 * n, 4 * n + 1, 1);
        ds.addEdge(4 * n, i, 1);
        ds.addEdge(i + n, i + 2 * n, 1);
        for (int v : divs[a[i]]) {
            if (id[v] != -1) {
//                cout << " HI " << " " << i << "  " << v << endl;
                ds.addEdge(i, id[v] + n, 1);
                ds.addEdge(i + 2 * n, id[v] + 3 * n, 1);
            }
        }
    }

    for (int i = 0; i < n; i++) id[a[i]] = -1;
    cout << ds.flow() << '\n';
//    cout << n - ds.flow() << '\n';
    return;
    vector<int> mt(n, -1);
    vector<int> nxt(n, -1);
    ds.flow();
    for (auto& it : ds.getEdges()) {
        if (it.src < n && it.dst >= n && it.dst < 2 * n && it.flow == 1) {
            mt[it.dst - n] = it.src;
            nxt[it.src] = it.dst - n;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mt[i] == -1) {
            int t = i;
            if (nxt[t] == -1) {
                ans += 1;
            }
            else {
                ans += 2;
            }
        }
    }
    cout << n - ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    memset(id, -1, sizeof id);
    for (int i = 1; i < maxN; i++) {
        for (int j = 2 * i; j < maxN; j += i) divs[j].emplace_back(i);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}