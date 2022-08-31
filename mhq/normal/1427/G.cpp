#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n;

const int maxN = 202;
int x[maxN][maxN];
const int F = (int)1e9;
mt19937 rnd(228);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
//    n = 200;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
//            x[i][j] = 0;
//            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
//                x[i][j] = rnd() % F + 1;
//            }
        }
    }
//    mcf_graph<int,ll> mc(n * n + 2);
    int s = n * n;
    int t = n * n + 1;
    ll tot = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    ll sumx = 0;
    struct Edge {
        int src, dst, cap, flow;

        Edge() {
        }

        Edge(int src, int dst, int cap, int flow)
            : src(src), dst(dst), cap(cap), flow(flow) {
        }
    };
    vector<Edge> edges;
    vector< vector<int> > g(n * n + 2);
    vector<int> lim(n * n);
    vector<int> cur(n * n);
    auto addEdge = [&](int src, int dst, int cap) {
        if (dst == t) {
            lim[src] += 2;
            return;
        }
        g[src].push_back(edges.size());
        edges.emplace_back(src, dst, cap, 0);
        g[dst].push_back(edges.size());
        edges.emplace_back(dst, src, 0, 0);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] != 0 && x[i][j] != -1) {
                /*  mc.add_edge(s, i * n + j, 1, 0);
                  mc.add_edge(i * n + j, t, 2, x[i][j]);*/
                addEdge(s, i * n + j, 1);
                addEdge(i * n + j, t, 1);
                sumx += x[i][j];
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (x[i][j] > 0 && x[nx][ny] > 0) {
                    tot += abs(x[i][j] - x[nx][ny]);
                    continue;
                }
                if (x[i][j] < 0 || x[nx][ny] < 0) {
                    continue;
                }
                addEdge(i * n + j, nx * n + ny, 1);
            }
        }
    }
    ll fl = 0;
    for (int i = 0; ; i++) {
        queue<int> q;
        vector<int> dist(n * n + 2, -1);
        vector<pair<int,int>> prv(n * n + 2, make_pair(-1, -1));
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int eid : g[v]) {
                int to = edges[eid].dst;
                if (edges[eid].cap > edges[eid].flow) {
                    if (dist[to] == -1) {
                        dist[to] = dist[v] + 1;
                        prv[to] = make_pair(v, eid);
                        q.push(to);
                    }
                }
            }
        }
        pair<int,int> mn = make_pair(2e9, 2e9);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (dist[x * n + y] != -1 && cur[x * n + y] < lim[x * n + y]) {
                    mn = min(mn, make_pair(::x[x][y], x * n + y));
                }
            }
        }
        if (mn.first > 1e9 + 5) break;
        fl += mn.first;
        int who = mn.second;
        assert(who < n * n);
        cur[who]++;
        while (who != s) {
            edges[prv[who].second].flow += 1;
            edges[prv[who].second ^ 1].flow -= 1;
            who = prv[who].first;
        }
    }
    tot /= 2;
    fl -= sumx;
    fl *= -1;
    tot += fl;
    cout << tot;
    return 0;
}