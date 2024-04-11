#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 52;

struct edge {
	int a, b, f, c, cost;
	edge(int a = 0, int b = 0, int f = 0, int c = 0, int cost = 0): a(a), b(b), f(f), c(c), cost(cost) { }
};

int n, k;
vector <edge> E;
vector <int> neigh[Maxn];
int flow[Maxn], par[Maxn];
int dist[Maxn];
int res;

void addEdge(int a, int b, int c, int cost)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, 0, c, cost));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, 0, -cost));
}

int nilFlow()
{
	fill(flow, flow + n + 1, 0); flow[1] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 1));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (f != flow[v]) continue;
		if (v == n) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].cost) continue;
			if (min(f, E[e].c - E[e].f) > flow[E[e].b]) {
				flow[E[e].b] = min(f, E[e].c - E[e].f); par[E[e].b] = e;
				Q.push(ii(flow[E[e].b], E[e].b));
			}
		}
	}
	int res = flow[n];
	if (!res) return 0;
	int v = n;
	while (v != 1) {
		int e = par[v];
		E[e].f += res; E[e ^ 1].f -= res;
		v = E[e].a;
	}
	return res;
}

int oneFlow()
{
	fill(dist, dist + n + 1, Inf); dist[1] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[1], 1));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].c - E[e].f > 0 && d + E[e].cost < dist[E[e].b]) {
				dist[E[e].b] = d + E[e].cost; par[E[e].b] = e;
				Q.push(ii(-dist[E[e].b], E[e].b));
			}
		}
	}
	if (dist[n] > k) return 0;
	k -= dist[n];
	int v = n;
	while (v != 1) {
		int e = par[v];
		E[e].f++; E[e ^ 1].f--;
		v = E[e].a;
	}
	return 1;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a; scanf("%d", &a);
			if (a > 0) { addEdge(i, j, a, 0); addEdge(i, j, k, 1); }
		}
	int flow;
	while ((flow = nilFlow()) != 0) res += flow;
	while ((flow = oneFlow()) != 0) res += flow;
	printf("%d\n", res);
	return 0;
}