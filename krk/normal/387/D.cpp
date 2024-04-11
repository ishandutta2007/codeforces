#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

struct edge {
	int a, b, c, f;
	edge(int a = 0, int b = 0, int c = 0, int f = 0): a(a), b(b), c(c), f(f) {}
};

int n, m;
vector <int> ne[Maxn], re[Maxn];
bool loop[Maxn];
int id[Maxn][Maxn];
int N;
vector <edge> E;
vector <int> neigh[Maxn];
bool flow[Maxn];
int par[Maxn];
int mf, f;
int res = Inf;

void addEdge(int a, int b, int c)
{
	id[a][b] = E.size(); 
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, 1));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0));
}

void Inc(int e) { E[e].f++; E[e ^ 1].f--; }

void delForw(int v)
{
	if (E[id[0][v]].f) {
		mf--;
		Inc(id[0][v] ^ 1);
		for (int i = 0; i < ne[v].size(); i++) {
			int u = ne[v][i];
			if (E[id[v][n + u]].f) {
				Inc(id[v][n + u] ^ 1);
				Inc(id[n + u][N - 1] ^ 1);
				break;
			}
		}
	}
	E[id[0][v]].c = 0;
}

void addForw(int v)
{
	E[id[0][v]].c = 1;
}

void delBack(int v)
{
	if (E[id[n + v][N - 1]].f) {
		mf--;
		Inc(id[n + v][N - 1] ^ 1);
		for (int i = 0; i < re[v].size(); i++) {
			int u = re[v][i];
			if (E[id[u][n + v]].f) {
				Inc(id[u][n + v] ^ 1);
				Inc(id[0][u] ^ 1);
				break;
			}
		}
	}
	E[id[n + v][N - 1]].c = 0;
}

void addBack(int v)
{
	E[id[n + v][N - 1]].c = 1;
}

void Delete(int v)
{
	delForw(v); delBack(v);
	if (loop[v] && E[id[v][n + v]].f) {
		E[id[v][n + v]].f--;
		mf++;
	}
}

int getFlow()
{
	fill(flow + 1, flow + N, false); flow[0] = true;
	priority_queue <int> Q; Q.push(0);
	while (!Q.empty()) {
		int v = Q.top(); Q.pop();
		if (v == N - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].f < E[e].c && !flow[E[e].b]) {
				flow[E[e].b] = true; par[E[e].b] = e;
				Q.push(E[e].b);
			}
		}
	}
	if (!flow[N - 1]) return 0;
	int v = N - 1;
	while (v) {
		int e = par[v];
		Inc(e);
		v = E[e].a;
	}
	return 1;
}

void incFlow()
{
	while ((f = getFlow()) != 0) mf += f;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if (a == b) loop[a] = true;
		else {
			ne[a].push_back(b);
			re[b].push_back(a);
		}
		addEdge(a, n + b, 1);
	}
	N = 2 * n + 2;
	for (int i = 1; i <= n; i++) {
		addEdge(0, i, 1);
		addEdge(n + i, N - 1, 1);
	}
	incFlow();
	for (int i = 1; i <= n; i++) {
		Delete(i);
		incFlow();
		int my = ne[i].size() + re[i].size() + loop[i];
		int cand = m - my - mf + n - 1 - mf + 2 * (n - 1) + 1 - my;
		res = min(res, cand);
		addForw(i); addBack(i);
	}
	printf("%d\n", res);
	return 0;
}