#include <bits/stdc++.h>
using namespace std;

const int INF = 1000*1000*1000;
const int Maxn = 505;

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

int n, root[2];
int a[Maxn];
int sum;
vector <int> neigh[2][Maxn];
int req[2][Maxn];
int all[2][Maxn];
int my[2][Maxn];
bool fall;

void Traverse(int t, int v, int p, int lst)
{
    if (lst != v && req[t][v] != -1) {
        req[t][lst] -= req[t][v];
        if (req[t][lst] < 0) fall = true;
        lst = v;
    }
    all[t][lst]++;
    my[t][v] = lst;
    for (int i = 0; i < neigh[t][v].size(); i++) {
        int u = neigh[t][v][i];
        if (u == p) continue;
        Traverse(t, u, v, lst);
    }
}

int main()
{
    scanf("%d %d %d", &n, &root[0], &root[1]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int t = 0; t < 2; t++)
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[t][a].push_back(b);
            neigh[t][b].push_back(a);
        }
    fill((int*)req, (int*)req + 2 * Maxn, -1);
    for (int t = 0; t < 2; t++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int v, val; scanf("%d %d", &v, &val);
            req[t][v] = val;
        }
    }
    if (req[0][root[0]] != req[1][root[1]]) {
        printf("-1\n");
        return 0;
    }
    int m = n - req[0][root[0]];
    Traverse(0, root[0], -1, root[0]);
    Traverse(1, root[1], -1, root[1]);
    int N = 2 * n + 2;
    vector <vector <rib> > g(N);
    int s = 0, t = N - 1;
    for (int i = 1; i <= n; i++) {
        if (req[0][i] != -1)
            if (req[0][i] > all[0][i]) fall = true;
            else add_rib(g, 0, i, all[0][i] - req[0][i], 0);
        if (req[1][i] != -1)
            if (req[1][i] > all[1][i]) fall = true;
            else add_rib(g, n + i, N - 1, all[1][i] - req[1][i], 0);
    }
    if (fall) { printf("-1\n"); return 0; }
    for (int i = 1; i <= n; i++)
        add_rib(g, my[0][i], n + my[1][i], 1, a[i]);
    int flow = 0, cost = 0;
    while (flow < m) {
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
        if (d[t] == INF)  { printf("-1\n"); return 0; }
        int addflow = m - flow;
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
  /*  for (int i = 0; i < N; i++)
        for (int j = 0; j < g[i].size(); j++)
            if ((i == 0 || g[i][j].b == N - 1) && g[i][j].f > g[i][j].u) {
                printf("-1\n");
                return 0;
            }*/
    cout << sum - cost << endl;
    return 0;
}