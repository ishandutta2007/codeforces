#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 300000005;
const int MAXN = 605;
const int INF = 1000000000;
 
struct edge {
    int a, b, cap, flow;
};

int n;
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
 
ll dinic() {
    ll flow = 0;
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
    scanf("%d", &n);
    N = 2 * n + 2;
    s = 0, t = N - 1;
    ll res = -ll(n) * Inf;
    for (int i = 1; i <= n; i++)
        add_edge(n + i, N - 1, Inf);
    for (int i = 1; i <= n; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int u; scanf("%d", &u);
            add_edge(i, n + u, 3 * Inf);
        }
    }
    for (int i = 1; i <= n; i++) {
        int c; scanf("%d", &c);
        if (c >= 0) {
            add_edge(0, i, Inf);
            add_edge(i, N - 1, c);
        } else {
            res += c;
            c = -c;
            add_edge(0, i, Inf + c);
        }
    }
    res += dinic();
    cout << res << endl;
    return 0;
}