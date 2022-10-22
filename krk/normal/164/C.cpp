#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2010;
const int Inf = 2000000000;

struct edge {
	int a, b, f, c, cost;
	edge(int a = 0, int b = 0, int f = 0, int c = 0, int cost = 0): a(a), b(b), f(f), c(c), cost(cost) { }
};

int n, k;
int s[Maxn], e[Maxn], c[Maxn];
vector <int> un;
int N;
vector <edge> E;
vector <int> neigh[Maxn];
int has[Maxn];
int dist[Maxn], par[Maxn];

void addEdge(int a, int b, int c, int cost)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, 0, c, cost));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, 0, -cost));
}

bool getFlow()
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].f < E[e].c && dist[v] + E[e].cost < dist[E[e].b]) {
				dist[E[e].b] = dist[v] + E[e].cost; par[E[e].b] = e;
				Q.push(ii(-dist[E[e].b], E[e].b));
			}
		}
	}
	int v = N - 1;
	if (dist[v] == Inf) return false;
	while (v) {
		int e = par[v];
		E[e].f++; E[e ^ 1].f--;
		v = E[e].a;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &s[i], &e[i], &c[i]); e[i] += s[i];
		un.push_back(s[i]);
	}
	un.push_back(Inf);
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	N = un.size() + 1;
	addEdge(0, 1, k, 0);
	for (int i = 0; i + 1 < un.size(); i++) addEdge(i + 1, i + 2, Inf, 0);
	for (int i = 0; i < n; i++) {
		int l = lower_bound(un.begin(), un.end(), s[i]) - un.begin() + 1;
		int r = lower_bound(un.begin(), un.end(), e[i]) - un.begin() + 1;
		has[i] = E.size();
		addEdge(l, r, 1, -c[i]);
	}
	while (getFlow()) ;
	for (int i = 0; i < n; i++)
		printf("%d%c", E[has[i]].f == E[has[i]].c, i + 1 < n? ' ': '\n');
	return 0;
}