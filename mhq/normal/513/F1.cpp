#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
const int maxN = 25;
const ll INF = (ll)1e18;
int n, m, male, female;
char cell[maxN][maxN];
struct skeiger{
    int r, c, t;
    skeiger(int _r, int _c, int _t) :
    r(_r), c(_c), t(_t)
    {}
};
vector < skeiger > all[2];
int dist[maxN][maxN][maxN][maxN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void find_dist(int x, int y) {
    if (cell[x][y] == '#') return ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[x][y][i][j] = -1;
        }
    }
    dist[x][y][x][y] = 0;
    queue < pair < int, int > > q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int i = t.first;
        int j = t.second;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 1 || ni > n || nj < 1 || nj > m || cell[ni][nj] == '#') continue;
            if (dist[x][y][ni][nj] != -1) continue;
            dist[x][y][ni][nj] = dist[x][y][i][j] + 1;
            q.push(make_pair(ni, nj));
        }
    }
}
void cals_dists() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            find_dist(i, j);
        }
    }
}
struct edge{
  int from, to, cap, flow;
  edge(int _from, int _to, int _cap, int _flow) :
  from(_from), to(_to), cap(_cap), flow(_flow)
  {}
};
vector < int > g[maxN * maxN * maxN];
int id[maxN][maxN];
vector < edge > edges;
int ptr[maxN * maxN * maxN];
int s, t, num;
void add_edge(int from, int to, int cap) {
    g[from].push_back(edges.size());
    edges.emplace_back(edge(from, to, cap, 0));
    g[to].push_back(edges.size());
    edges.emplace_back(edge(to, from, cap, cap));
}
void init() {
    edges.clear();
    for (int i = 0; i <= t; i++) g[i].clear();
}
int d[maxN * maxN * maxN];
bool bfs() {
    for (int i = 0; i <= t; i++) {
        d[i] = -1;
    }
    d[s] = 0;
    queue < int > q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int id = g[v][i];
            if (d[edges[id].to] != -1) continue;
            if (edges[id].flow < edges[id].cap) {
                d[edges[id].to] = d[v] + 1;
                q.push(edges[id].to);
            }
        }
    }
    return (d[t] != -1);
}
int dfs(int from, int flow) {
    if (flow == 0) return 0;
    if (from == t) return flow;
    for (; ptr[from] < g[from].size(); ptr[from]++) {
        int id = g[from][ptr[from]];
        int to = edges[id].to;
        if (d[to] != d[from] + 1) continue;
        int pushed = dfs(to, min(flow, edges[id].cap - edges[id].flow));
        if (pushed) {
            edges[id].flow += pushed;
            edges[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
int go_flow() {
    int flow = 0;
    while (true) {
        if (!bfs()) break;
        for (int i = 0; i <= t; i++) ptr[i] = 0;
        while (true) {
            int pushed = dfs(s, (int) 1e9);
            if (pushed) {
                flow += pushed;
            } else break;
        }
    }
    return flow;
}
bool can(ll lim) {
   // cout << lim << endl;
    num = all[0].size();
    assert(all[0].size() == all[1].size());
    s = 0;
    t = 2 * n * m + 2 * num + 1;
    init();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < all[i].size(); j++) {
            int r = all[i][j].r;
            int c = all[i][j].c;
            int tt = all[i][j].t;
            if (i == 0) {
                add_edge(s, 2 * n * m + 1 + j, 1);
            }
            else {
                add_edge(2 * n * m + 1 + j + num, t, 1);
            }
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    if (dist[r][c][x][y] == -1) continue;
                    if (1LL * dist[r][c][x][y] * tt > lim) continue;
                    if (i == 0) add_edge(2 * n * m + 1 + j, id[x][y], 1);
                    else add_edge(id[x][y] + n * m, 2 * n * m + 1 + j + num, 1);
                }
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            add_edge(id[x][y], id[x][y] + n * m, 1);
        }
    }
    return go_flow() == num;
}
void solve() {
    ll l = 0;
    ll r = INF;
    if (can(l)) {
        cout << 0;
        return ;
    }
    else if (!can(r)) {
        cout << -1;
        return ;
    }
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> male >> female;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cell[i][j];
            id[i][j] = (i - 1) * m + j;
        }
    }
    if (abs(male - female) != 1) {
        cout << -1;
        return 0;
    }
    int x, y, t;
    cin >> x >> y >> t;
    if (male > female) {
        all[1].emplace_back(x, y, t);
    }
    else {
        all[0].emplace_back(x, y, t);
    }
    for (int i = 1; i <= male; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        all[0].emplace_back(x, y, t);
    }
    for (int i = 1; i <= female; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        all[1].emplace_back(x, y, t);
    }
    cals_dists();
    solve();
    return 0;
}