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
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int MaxN = 305;
const int Inf = 1000000000;

struct edge {
	int a, b, cap, cost;
	edge(int a = 0, int b = 0, int cap = 0, int cost = 0): a(a), b(b), cap(cap), cost(cost) {}
};

int n, q;
int N;
int L[MaxN], R[MaxN];
vector <edge> E;
vector <int> neigh[MaxN];
int dist[MaxN], par[MaxN];

void addEdge(int a, int b, int cap, int cost)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, cap, cost));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, -cost));
}

bool getFlow(int &res)
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].cap > 0 && d + E[e].cost < dist[E[e].b]) {
				dist[E[e].b] = d + E[e].cost; par[E[e].b] = e;
				Q.push(ii(-dist[E[e].b], E[e].b));
			}
		}
	}
	int v = N - 1;
	if (dist[v] >= Inf) return false;
	res = dist[v];
	while (v) {
		int e = par[v];
		E[e].cap--; E[e ^ 1].cap++;
		v = E[e].a;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &q); N = 2 + 2 * n;
	for (int i = 1; i <= n; i++)
		L[i] = 1, R[i] = n;
	while (q--) {
		int t, l, r, v; scanf("%d %d %d %d", &t, &l, &r, &v);
		if (t == 1)
			for (int i = l; i <= r; i++)
				L[i] = max(L[i], v);
		else for (int i = l; i <= r; i++)
				R[i] = min(R[i], v);
	}
	for (int i = 1; i <= n; i++) {
		addEdge(0, i, 1, 0);
		if (L[i] > R[i]) { printf("-1\n"); return 0; }
		for (int j = L[i]; j <= R[i]; j++)
			addEdge(i, n + j, 1, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			addEdge(n + i, N - 1, 1, 2 * j - 1);
	int res = 0, add;
	while (getFlow(add)) res += add;
	printf("%d\n", res);
	return 0;
}