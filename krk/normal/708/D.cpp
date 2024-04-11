#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int INF = 1000*1000*1000;
const int Maxn = 105;

struct rib {
    int b, u, c, f;
    size_t back;
};

int n, m;
vector <vector <rib> > g(Maxn);
int col[Maxn];
int dist[Maxn];
ii par[Maxn];
int res;

void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
    rib r1 = { b, u, c, 0, g[b].size() };
    rib r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int minCostMaxFlow()
{
    int s = 0, t = n - 1;
    int flow = 0,  cost = 0;
    while (true) {
        vector<int> id (n, 0);
        vector<int> d (n, INF);
        vector<int> q (n);
        vector<int> p (n);
        vector<size_t> p_rib (n);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)  qh = 0;
            for (size_t i=0; i<g[v].size(); ++i) {
                rib & r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == n)  qt = 0;
                    }
                    else if (id[r.b] == 2) {
                        if (--qh == -1)  qh = n-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_rib[r.b] = i;
                }
            }
        }
        if (d[t] == INF)  break;
        int addflow = INF;
        int addcost = 0;
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v];
            addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            addcost += g[pv][pr].c * addflow;
        }
        if (addcost >= 0) break;
        flow += addflow;
        cost += addcost;
    }
    return cost;
}

void Traverse(int v, int c)
{
    if (col[v]) return;
    col[v] = c;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].f < g[v][i].u)
            Traverse(g[v][i].b, c);
}

void processCycle(const deque <ii> &cycle)
{
    int cost = 0, mn = INF;
    for (int i = 0; i < cycle.size(); i++) {
        int v = cycle[i].first, ind = cycle[i].second;
        mn = min(mn, g[v][ind].u - g[v][ind].f);
        cost += g[v][ind].c;
    }
    assert(cost < 0);
    res += cost * mn;
    for (int i = 0; i < cycle.size(); i++) {
        int v = cycle[i].first, ind = cycle[i].second;
        int u = g[v][ind].b, ind2 = g[v][ind].back;
        g[v][ind].f += mn;
        g[u][ind2].f -= mn;
    }
}

bool cancelCycle()
{
    for (int i = 0; i < n; i++)
        dist[i] = col[i] == i + 1? 0: INF;
    for (int t = 0; t < n - 1; t++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < g[i].size(); j++) if (g[i][j].f < g[i][j].u) {
                int u = g[i][j].b;
                if (col[i] == col[u] && dist[i] + g[i][j].c < dist[u]) {
                    dist[u] = dist[i] + g[i][j].c;
                    par[u] = ii(i, j);
                }
            }
    vector <int> tk(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++) if (g[i][j].f < g[i][j].u) {
            int u = g[i][j].b;
            if (col[i] == col[u] && dist[i] + g[i][j].c < dist[u]) {
                deque <ii> cycle;
                int num = u;
                while (!tk[num]) {
                    cycle.push_back(par[num]);
                    tk[num] = cycle.size();
                    num = par[num].first;
                }
                int el = tk[num] - 1;
                while (el--) cycle.pop_front();
                processCycle(cycle);
                return true;
            }
        }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c, f; scanf("%d %d %d %d", &u, &v, &c, &f);
        u--; v--;
        res += f;
        if (f <= c) {
            add_rib(g, u, v, f, -1);
            add_rib(g, u, v, c - f, 1);
            add_rib(g, u, v, 1000000, 2);
        } else {
            add_rib(g, u, v, c, -1);
            add_rib(g, u, v, f - c, 0);
            add_rib(g, u, v, 1000000, 2);
        }
    }
    for (int i = 0; i < n; i++)
        Traverse(i, i + 1);
    while (cancelCycle()) ;
    res += minCostMaxFlow();
    cout << res << endl;
    return 0;
}