#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 605;
int n, m, k;
int deg[maxN];
struct edge{
    int from, to, cap, flow;
    edge(int _from, int _to, int _cap, int _flow) {
        from = _from;
        to = _to;
        cap = _cap;
        flow = _flow;
    }
};
vector < edge > edges;
vector < int > g[2 * maxN];
vector < int > all_edges[maxN];
int s, t;
void addEdge(int from, int to, int cap) {
    g[from].push_back(edges.size());
    edges.emplace_back(from, to, cap, 0);
    g[to].push_back(edges.size());
    edges.emplace_back(to, from, cap, cap);
}
int dist[2 * maxN];
void bfs() {
    memset(dist, -1, sizeof dist);
    dist[s] = 0;
    queue < int > q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int id : g[v]) {
            int to = edges[id].to;
            if (edges[id].flow < edges[id].cap && dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}
int ptr[2 * maxN];
const int INF = (int)1e9;
int c[maxN];
int dfs(int v, int lim) {
    if (lim == 0) return 0;
    if (v == t) return lim;
    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int id = g[v][ptr[v]];
        int to = edges[id].to;
        if (dist[to] != dist[v] + 1) continue;
        int pushed = dfs(to, min(lim, edges[id].cap - edges[id].flow));
        if (pushed) {
            edges[id].flow += pushed;
            edges[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
int flow = 0;
void goFlow() {
    flow = 0;
    while (true) {
        bfs();
        if (dist[t] == -1) break;
        memset(ptr, 0, sizeof ptr);
        while (true) {
            int pushed = dfs(s, INF);
            flow += pushed;
            if (pushed == 0) break;
        }
    }
}
void solve() {
    cin >> n >> m >> k;
    edges.clear();
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
        all_edges[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        c[i] = 0;
        int a, b;
        cin >> a >> b;
        all_edges[a].push_back(i);
        all_edges[b].push_back(i);
        deg[a]++;
        deg[b]++;
    }
    s = 0;
    t = n + m + 1;
    for (int i = s; i <= t; i++) {
        g[i].clear();
    }
    int all = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > k) {
            all += 2 * (deg[i] - k);
            addEdge(s, i, 2 * (deg[i] - k));
            for (int ed: all_edges[i]) {
                addEdge(i, n + ed, 1);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        addEdge(n + i, t, 1);
    }
    goFlow();
    //cout << flow << endl;
    if (flow != all) {
        for (int i = 1; i <= m; i++) {
            cout << 0 << " ";
        }
        cout << '\n';
    }
    else {
        int sz = 1;
        int num = 0;
        for (int i = 1; i <= n; i++) {
            for (int id : g[i]) {
                auto ed = edges[id];
                if (ed.to == s || ed.to == t) continue;
                if (ed.flow == ed.cap) {
                    c[ed.to - n] = sz;
                    num++;
                    if (num == 2) {
                        num = 0;
                        sz++;
                    }
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (c[i] == 0) {
                c[i] = sz;
                sz++;
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << c[i] << " ";
        }
        cout << '\n';
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}