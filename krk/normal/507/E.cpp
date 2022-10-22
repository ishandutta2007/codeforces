#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

struct edge {
	int a, b, st, id;
	edge(int a = 0, int b = 0, int st = 0, int id = 0): a(a), b(b), st(st), id(id) {}
};

int n, m;
int A[Maxn], B[Maxn], S[Maxn];
vector <edge> E;
vector <int> neigh[Maxn];
ii dist[Maxn];
int par[Maxn];
priority_queue <iii> Q;
bool tk[Maxn];
vector <int> res;

void addEdge(int a, int b, int st, int id)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, st, id));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, st, id));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, st; scanf("%d %d %d", &a, &b, &st);
		addEdge(a, b, st, i);
		A[i] = a; B[i] = b; S[i] = st;
	}
	fill((ii*)dist, (ii*)dist + Maxn, ii(Maxn, Maxn)); dist[1] = ii(0, 0);
	Q.push(iii(ii(0, 0), 1));
	while (!Q.empty()) {
		int v = Q.top().second; ii d = Q.top().first; Q.pop();
		d = ii(-d.first, -d.second);
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			ii cst = ii(d.first + 1, d.second + (E[e].st == 0));
			if (cst < dist[E[e].b]) {
				dist[E[e].b] = cst; par[E[e].b] = e;
				Q.push(iii(ii(-cst.first, -cst.second), E[e].b));
			}
		}
	}
	int v = n;
	while (v > 1) {
		int e = par[v];
		tk[E[e].id] = true;
		v = E[e].a;
	}
	for (int i = 1; i <= m; i++)
		if (S[i] == 1 && !tk[i] || S[i] == 0 && tk[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", A[res[i]], B[res[i]], !S[res[i]]);
	return 0;
}