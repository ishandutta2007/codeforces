#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MaxN = 10005;
const int INF = 1000000000;

int n, m;
int A[MaxN], B[MaxN];
int deg[MaxN];
int N;

struct edge {
	int a, b, cap, flow;
};

int s, t, d[MaxN], ptr[MaxN], q[MaxN];
vector<edge> e;
vector<int> g[MaxN];
 
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
	s = 0, t = N - 1;
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, N * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

void Construct(int allow)
{
	e.clear();
	for (int i = 0; i < N; i++)
		g[i].clear();
	for (int i = 0; i < m; i++) {
		add_edge(0, i + 1, 1);
		add_edge(i + 1, 1 + m + A[i], 1);
		add_edge(i + 1, 1 + m + B[i], 1);
	}
	for (int i = 0; i < n; i++)
		add_edge(1 + m + i, N - 1, allow);
}

int main()
{
	scanf("%d %d", &n, &m); N = 2 + n + m;
	if (m == 0) { printf("0\n"); return 0; }
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &A[i], &B[i]); A[i]--; B[i]--;
		deg[A[i]]++; deg[B[i]]++;
	}
	int mx = 0;
	for (int i = 0; i < n; i++)
		mx = max(mx, deg[i]);
	int lef = 1, rig = mx / 2 + 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		Construct(mid);
		if (dinic() < m) lef = mid + 1;
		else rig = mid - 1; 
	}
	rig++; printf("%d\n", rig);
	Construct(rig);
	dinic();
	for (int i = 0; i < e.size(); i++)
		if (1 <= e[i].a && e[i].a <= m && 1 + m <= e[i].b && e[i].b <= m + n && e[i].flow > 0) {
			int ind = e[i].a - 1;
			int v = e[i].b - (1 + m);
			int u = A[ind] == v? B[ind]: A[ind];
			printf("%d %d\n", v + 1, u + 1);
		}
	return 0;
}