#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 4005;
const int Maxm = 1000000;
const int Inf = 1000000000;

struct edge {
	int a, b, cap, id;
	edge(int a = 0, int b = 0, int cap = 0, int id = 0): a(a), b(b), cap(cap), id(id) {}
};

int n1, n2, m;
int N;
int deg[Maxn];
bool tk[Maxn];
vector <edge> E;
vector <int> neigh[Maxn];
vector <int> res[Maxn];
int flow[Maxn], par[Maxn];
int seq[Maxm], slen;

void addEdge(int a, int b, int cap, int id)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, cap, id));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, id));
}

int getFlow()
{
	for (int i = 0; i < slen; i++)
		flow[seq[i]] = 0;
	slen = 0;
	flow[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 0));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (flow[v] != f) continue;
		if (v == N - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (min(flow[v], E[e].cap) > flow[E[e].b]) {
				seq[slen++] = E[e].b;
				flow[E[e].b] = min(flow[v], E[e].cap);
				par[E[e].b] = e;
				Q.push(ii(flow[E[e].b], E[e].b));
			}
		}
	}
	int v = N - 1;
	int res = flow[v];
	if (res == 0) return res;
	while (v) {
		int e = par[v];
		E[e].cap -= res; E[e ^ 1].cap += res; tk[E[e].id] ^= true;
		v = E[e].a;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n1, &n2, &m);
	N = 2 + n1 + n2;
	int mn = Maxn;
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		addEdge(a, n1 + b, 1, i);
		deg[a]++; deg[n1 + b]++;
	}
	for (int i = 1; i <= n1 + n2; i++)
		mn = min(mn, deg[i]);
	for (int i = 1; i <= n1; i++)
		addEdge(0, i, deg[i] - mn, 0);
	for (int i = 1; i <= n2; i++)
		addEdge(n1 + i, N - 1, deg[n1 + i] - mn, 0);
	for (int i = mn; i >= 0; i--) {
		while (getFlow()) ;
		for (int j = 1; j <= m; j++)
			if (!tk[j]) res[i].push_back(j);
		for (int j = 0; j < E.size(); j++)
			if (E[j].a == 0 && E[j].b <= n1 || E[j].a > n1 && E[j].b == N - 1)
				E[j].cap++;
	}
	for (int i = 0; i <= mn; i++) {
		printf("%d", int(res[i].size()));
		for (int j = 0; j < res[i].size(); j++)
			printf(" %d", res[i][j]);
		printf("\n");
	}
	return 0;
}