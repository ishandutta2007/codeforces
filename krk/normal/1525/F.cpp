#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 105;
const int MAXN = 105;
const int INF = 1000000000;
 
struct edge {
	int a, b, cap, flow;
};
 
int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void Clear()
{
	for (int i = 0; i < N; i++)
		g[i].clear();
	e.clear();
}
 
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

int n, m, k;
vector <int> neigh[Maxn];
int bas;
int A[Maxn], B[Maxn];
vector <int> seq;
int X[Maxn], Y[Maxn];
ll dp[Maxn][Maxn];
int tk[Maxn][Maxn];

int Try()
{
	N = 2 * n + 2;
	s = 0, t = N - 1;
	Clear();
	for (int i = 1; i <= n; i++) {
		if (A[i]) add_edge(0, i, 1);
		if (B[i]) add_edge(n + i, N - 1, 1);
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			add_edge(i, n + u, 1);
		}
	}
	return n - dinic();
}

void getMore(int cur)
{
	for (int i = 1; i <= n; i++) if (A[i] == 1) {
		A[i] = 0;
		if (Try() > cur) { seq.push_back(i); return; }
		A[i] = 1;
	}
	for (int i = 1; i <= n; i++) if (B[i] == 1) {
		B[i] = 0;
		if (Try() > cur) { seq.push_back(-i); return; }
		B[i] = 1;
	}
	assert(false);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		A[i] = B[i] = 1;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
	}
	bas = Try();
	int cur = bas;
	while (cur < n) {
		getMore(cur);
		cur++;
	}
	for (int i = 0; i < k; i++)
		scanf("%d %d", &X[i], &Y[i]);
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, -Inf);
	dp[0][0] = 0;
	for (int i = 0; i < k; i++)
		for (int j = 0; j <= seq.size(); j++) if (dp[i][j] >= 0)
			for (int t = 0; j + t <= seq.size(); t++) if (bas + j + t > i + 1) {
				ll cand = dp[i][j] + max(0ll, ll(X[i]) - ll(Y[i]) * t);
				if (cand > dp[i + 1][j + t]) {
					dp[i + 1][j + t] = cand;
					tk[i + 1][j + t] = t;
				}
			}
	int bi = k, bj = 0;
	for (int j = 0; j <= seq.size(); j++)
		if (dp[bi][j] > dp[bi][bj]) bj = j;
	vector <int> ans;
	while (bi > 0) {
		ans.push_back(0);
		int t = tk[bi][bj];
		while (t--) {
			bj--;
			ans.push_back(seq[bj]);
		}
		bi--;
	}
	printf("%d\n", int(ans.size()));
	for (int i = int(ans.size()) - 1; i >= 0; i--)
		printf("%d%c", ans[i], i - 1 >= 0? ' ': '\n');
    return 0;
}