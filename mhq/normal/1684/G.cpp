#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1005;
const int INF = 1e9;
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

    int dfs(int v, int flow = INF) {
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
int t[maxN];
void solve() {
    cin >> n >> m;
    vector<int> f1, f2;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if (t[i] + t[i] + 1 > m) {
            cout << -1 << '\n';
            return;
        }
        if (3LL * t[i] > m) {
            f1.emplace_back(t[i]);
        }
        else {
            f2.emplace_back(t[i]);
        }
    }

    int s = f1.size() + f2.size();
    int t = f1.size() + f2.size() + 1;
    DinitzFlow ds(f1.size() + f2.size() + 2, s, t);
    for (int i = 0; i < f1.size(); i++) {
        ds.addEdge(s, i, 1);
        for (int j = 0; j < f2.size(); j++) {
            if (f1[i] % f2[j] == 0 && 2LL * f1[i] + (ll)f2[j] <= (ll)m) {
                ds.addEdge(i, j + f1.size(), 1);
            }
        }
    }
    for (int j = 0; j < f2.size(); j++) {
        ds.addEdge(j + f1.size(), t, 1);
    }
    int res = ds.flow();
    if (res != f1.size()) {
        cout << -1 << '\n';
    }
    else {
        vector<bool> used(f2.size(), false);
        vector<pair<int,int>> all;
        for (auto& it : ds.getEdges()) {
            if (it.flow == 1 && it.src >= 0 && it.src < (int)f1.size() && it.dst >= (int)f1.size() && it.dst < (int)f1.size() + (int)f2.size()) {
                all.emplace_back(2 * f1[it.src] + f2[it.dst - f1.size()], f1[it.src] + f2[it.dst - f1.size()]);
                used[it.dst - f1.size()] = true;
            }
        }
        assert(all.size() == f1.size());
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                all.emplace_back(3 * f2[i], 2 * f2[i]);
            }
        }
        cout << all.size() << '\n';
        for (auto& it : all) {
            cout << it.first << " " << it.second << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 1;
//    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}