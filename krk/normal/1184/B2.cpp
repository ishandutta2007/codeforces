#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Inf = 1000000000;

int n, m;
int dist[Maxn][Maxn];
int S, B, K, H;
int ax[Maxn], ay[Maxn], az[Maxn];
int bx[Maxn], by[Maxn];

const int MAXN = 2005;
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

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) dist[i][j] = Inf;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a != b) dist[a][b] = dist[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    scanf("%d %d %d %d", &S, &B, &K, &H);
    N = 2 + S + B; s = 0, t = N - 1;
    for (int i = 0; i < S; i++)
        scanf("%d %d %d", &ax[i], &ay[i], &az[i]);
    for (int i = 0; i < B; i++)
        scanf("%d %d", &bx[i], &by[i]);
    for (int i = 0; i < S; i++) {
        add_edge(0, 1 + i, 1);
        for (int j = 0; j < B; j++)
            if (dist[ax[i]][bx[j]] <= az[i] && ay[i] >= by[j])
                add_edge(1 + i, 1 + S + j, 1);
    }
    for (int j = 0; j < B; j++)
        add_edge(1 + S + j, N - 1, 1);
    int got = dinic();
    ll res = ll(got) * K;
    int lft = S - got;
    for (int i = 1; i <= got; i++)
        res = min(res, ll(lft + i) * H + ll(got - i) * K);
    cout << res << endl;
    return 0;
}