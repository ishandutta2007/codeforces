#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int infinity = 1e7;
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
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<bool>> good(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (a[i][j] > a[nx][ny]) good[i][j] = true;
                }
            }
        }
        int old_source = n * m;
        int old_sink = n * m + 1;
        int new_source = n * m + 2;
        int new_sink = n * m + 3;
        DinitzFlow ds(new_sink + 1, new_source, new_sink);
        int sum = 0;
        auto add_edge =[&](int from, int to, int l, int r) {
            sum += l;
            if (l == 0) {
                ds.addEdge(from, to, r);
            }
            else {
                ds.addEdge(from, to, r - l);
                ds.addEdge(new_source, to, l);
                ds.addEdge(from, new_sink, l);
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0) {
                    add_edge(old_source, i * m + j, !good[i][j], 1);
                }
                else {
                    add_edge(i * m + j, old_sink, !good[i][j], 1);
                }
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (a[i][j] != a[ni][nj]) continue;
                    if ((i + j) % 2 == 0) {
                        ds.addEdge(i * m + j, ni * m + nj, 1);
                    }
                    else {
                        ds.addEdge(ni * m + nj, i * m + j, 1);
                    }
                }
            }
        }
        ds.addEdge(old_sink, old_source, 3 * n * m);
        int p = ds.flow();
        if (p != sum) {
            cout << "NO\n";
            continue;
        }
        vector<vector<char>> sym(n, vector<char>(m, 'Z'));
        vector<vector<int>> val(n, vector<int>(m));
        for (auto& it : ds.getEdges()) {
            if (it.src < n * m && it.dst < n * m && it.flow > 0) {
                int x = it.src / m;
                int y = it.src % m;
                int nx = it.dst / m;
                int ny = it.dst % m;
                if ((x + y) % 2 == 0) {
                    assert(it.flow == 1);
                    assert(abs(nx - x) + abs(ny - y) == 1);
                    assert(a[x][y] == a[nx][ny]);
                    val[x][y] = 1;
                    val[nx][ny] = a[x][y] - 1;
                    if (ny == y - 1) {
                        sym[x][y] = 'L';
                        sym[nx][ny] = 'R';
                    }
                    else if (ny == y + 1) {
                        sym[x][y] = 'R';
                        sym[nx][ny] = 'L';
                    }
                    else if (nx == x + 1) {
                        sym[x][y] = 'D';
                        sym[nx][ny] = 'U';
                    }
                    else {
                        sym[x][y] = 'U';
                        sym[nx][ny] = 'D';
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (sym[i][j] != 'Z') continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (a[i][j] > a[ni][nj]) {
                        val[i][j] = a[i][j] - a[ni][nj];
                        int x = i;
                        int y = j;
                        int nx = ni;
                        int ny = nj;
                        if (ny == y - 1) {
                            sym[x][y] = 'L';
                        }
                        else if (ny == y + 1) {
                            sym[x][y] = 'R';
                        }
                        else if (nx == x + 1) {
                            sym[x][y] = 'D';
                        }
                        else {
                            sym[x][y] = 'U';
                        }
                        break;
                    }
                }
            }
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << val[i][j] << " ";
            }
            cout << '\n';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                assert(sym[i][j] != 'Z');
                cout << sym[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}