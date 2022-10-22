#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int MAXN = 1015;
const int INF = 1000000000;

int n, m;
char B[Maxn][Maxn];
bool inv[Maxn];
bool tk[Maxn][Maxn];
int res;

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

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    for (int i = n - 1; i >= 0; i--) {
        bool cur = false;
        for (int j = m - 1; j >= 0; j--) {
            cur ^= inv[j];
            if ((B[i][j] == 'B') ^ cur) {
                inv[j] ^= true;
                cur ^= true;
                tk[i][j] = true;
                res++;
            }
        }
    }
    N = n + m + 2;
    s = 0, t = N - 1;
    for (int i = 0; i < n - 1; i++) if (tk[i][m - 1])
        add_edge(s, 1 + i, 1);
    for (int j = 0; j < m - 1; j++) if (tk[n - 1][j])
        add_edge(1 + n + j, t, 1);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) if (tk[i][j])
            add_edge(1 + i, 1 + n + j, 1);
    res -= (dinic() + int(tk[n - 1][m - 1])) / 2 * 2;
    printf("%d\n", res);
    return 0;
}