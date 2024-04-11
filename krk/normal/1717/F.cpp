#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int MAXN = 20005;
const int INF = 1000000000;
 
struct edge {
    int a, b, cap, flow;
};
 
int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}
 
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, N * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
 
int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, N * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int n, m;
int spec[MAXN];
int a[MAXN];
int X[MAXN], Y[MAXN];
vector <int> neigh[MAXN];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &spec[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    N = n + m + 2;
    s = 0, t = N - 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        a[X[i]]++; a[Y[i]]++;
        neigh[X[i]].push_back(n + i);
        neigh[Y[i]].push_back(n + i);
        add_edge(n + i, t, 1);
    }
    for (int i = 1; i <= n; i++)
        if (spec[i] == 0)
            add_edge(s, i, INF);
        else {
            if (a[i] < 0 || a[i] % 2 != 0) {
                printf("NO\n");
                return 0;
            }
            a[i] /= 2;
            add_edge(s, i, a[i]);
        }
    for (int i = 1; i <= n; i++)
        if (spec[i] == 1)
            for (int j = 0; j < neigh[i].size(); j++)
                add_edge(i, neigh[i][j], 1);
    dinic();
    for (int i = 0; i < g[s].size(); i++) {
        int ind = g[s][i];
        if (spec[e[ind].b] == 1 && e[ind].flow != e[ind].cap) {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
        if (spec[i] == 0)
            for (int j = 0; j < neigh[i].size(); j++)
                add_edge(i, neigh[i][j], 1);
    dinic();
    for (int i = 0; i < g[t].size(); i++) {
        int ind = (g[t][i] ^ 1);
        if (e[ind].flow != e[ind].cap) {
            printf("NO\n");
            return 0;
        }
    }
    for (int i = n + 1; i <= n + m; i++)
        for (int j = 0; j < g[i].size(); j++) {
            int ind = (g[i][j] ^ 1);
            if (e[ind].a >= 1 && e[ind].a <= n && e[ind].flow == e[ind].cap)
                if (e[ind].a == X[i - n]) swap(X[i - n], Y[i - n]);
        }
    printf("YES\n");
    for (int i = 1; i <= m; i++)
        printf("%d %d\n", X[i], Y[i]);
    return 0;
}