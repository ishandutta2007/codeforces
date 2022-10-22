#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = 1000*1000*1000;
const int Maxn = 305;

struct rib {
    int b, u, c, f;
    size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
    rib r1 = { b, u, c, 0, g[b].size() };
    rib r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int n, m;
int vals[Maxn];
int my[Maxn];
int pnt[Maxn];
vector <ii> res;

int main()
{
    scanf("%d %d", &n, &m);
    int N = 2 * n + 2 * m + 2;
    vector <vector <rib> > g(N);
    int s = 0, t = N - 1;
    for (int i = 1; i <= m; i++) {
        add_rib(g, s, i, 1, 0);
        add_rib(g, m + n + n + i, t, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &vals[i]);
        int bits = __builtin_popcount(vals[i]);
        for (int j = 1; j <= m; j++) {
            add_rib(g, j, m + n + i, 1, bits);
            add_rib(g, m + i, m + n + n + j, 1, INF);
        }
        for (int j = 1; j < i; j++)
            add_rib(g, m + j, m + n + i, 1, (vals[i] == vals[j]? 0: bits));
        add_rib(g, s, m + i, 1, 0);
        add_rib(g, m + n + i, t, 1, 0);
    }
    int flow = 0, cost = 0;
    while (flow < n) {
        vector<int> id (N, 0);
        vector<int> d (N, INF);
        vector<int> q (N);
        vector<int> p (N);
        vector<size_t> p_rib (N);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == N)  qh = 0;
            for (size_t i=0; i<g[v].size(); ++i) {
                rib & r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == N)  qt = 0;
                    }
                    else if (id[r.b] == 2) {
                        if (--qh == -1)  qh = N-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_rib[r.b] = i;
                }
            }
        }
        if (d[t] == INF)  break;
        int addflow = n - flow;
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v];
            addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            cost += g[pv][pr].c * addflow;
        }
        flow += addflow;
    }
    for (int i = 1; i <= m; i++)
        pnt[i] = -1;
    for (int i = 1; i <= n; i++) {
        int v = m + n + i;
        for (int j = 0; j < g[v].size(); j++)
            if (g[v][j].b < v && g[v][j].f < g[v][j].u) {
                int u = g[v][j].b;
                my[i] = u > m? my[u - m]: u;
                break;
            }
        if (pnt[my[i]] != vals[i]) {
            res.push_back(ii(my[i], vals[i]));
            pnt[my[i]] = vals[i];
        }
        res.push_back(ii(my[i], -1));
    }
    printf("%d %d\n", int(res.size()), cost);
    for (int i = 0; i < res.size(); i++)
        if (res[i].second == -1) printf("print(%c)\n", res[i].first - 1 + 'a');
        else printf("%c=%d\n", res[i].first - 1 + 'a', res[i].second);
}