#include <bits/stdc++.h>
using namespace std;

const int Maxd = 205;
const int MAXN = 2 + 2 * Maxd * Maxd;
const int INF = 1000000000;
 
struct edge {
	int a, b, cap, flow;
};

int n, m;
char B[Maxd][Maxd];
int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
bool col[MAXN];
 
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

int From(int r, int c) { return r * m + c + 1; }

int To(int r, int c) { return 1 + n * m + r * m + c; }

void Fill(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '.') return;
	B[r][c] = '.';
	if (r + 1 < n && B[r + 1][c] == '#' && col[From(r, c)])
		Fill(r + 1, c);
	if (r - 1 >= 0 && B[r - 1][c] == '#' && col[From(r - 1, c)])
		Fill(r - 1, c);
	if (c + 1 < m && B[r][c + 1] == '#' && !col[To(r, c)])
		Fill(r, c + 1);
	if (c - 1 >= 0 && B[r][c - 1] == '#' && !col[To(r, c - 1)])
		Fill(r, c - 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	N = 2 + 2 * n * m;
	s = 0, t = N - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && B[i][j] == '#' && B[i + 1][j] == '#')
				add_edge(0, From(i, j), 1);
			if (j + 1 < m && B[i][j] == '#' && B[i][j + 1] == '#')
				add_edge(To(i, j), N - 1, 1);
			if (i + 1 < n && j > 0 && B[i][j] == '#' && B[i + 1][j] == '#' && B[i + 1][j - 1] == '#')
				add_edge(From(i, j), To(i + 1, j - 1), 1);
			if (i + 1 < n && j + 1 < m && B[i][j] == '#' && B[i + 1][j] == '#' && B[i + 1][j + 1] == '#')
				add_edge(From(i, j), To(i + 1, j), 1);
			if (i + 1 < n && j > 0 && B[i][j] == '#' && B[i + 1][j] == '#' && B[i][j - 1] == '#')
				add_edge(From(i, j), To(i, j - 1), 1);
			if (i + 1 < n && j + 1 < m && B[i][j] == '#' && B[i + 1][j] == '#' && B[i][j + 1] == '#')
				add_edge(From(i, j), To(i, j), 1);
		}
	dinic();
	queue <int> Q; Q.push(0);
	col[0] = true;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < g[v].size(); i++) {
			int ind = g[v][i];
			if (e[ind].flow < e[ind].cap) {
				int u = e[ind].b;
				if (!col[u]) {
					col[u] = true;
					Q.push(u);
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] == '#') {
			res++;
			Fill(i, j);
		}
	printf("%d\n", res);
    return 0;
}