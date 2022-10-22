#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 82;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

struct edge {
	int a, b, f, c, cst;
	edge(int a = 0, int b = 0, int f = 0, int c = 0, int cst = 0): a(a), b(b), f(f), c(c), cst(cst) { }
};

int n, m;
int B[Maxn][Maxn];
int N;
vector <edge> E;
vector <int> neigh[Maxm];
int dist[Maxm], par[Maxm];
int res;

void Add(int a, int b, int c, int cst)
{
	neigh[a].push_back(E.size()); E.push_back(edge(a, b, 0, c, cst));
	neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, 0, -cst));
}

bool getFlow(int &add)
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		if (d == 0 && v == N - 1) break;
		for (int i = 0; i < neigh[v].size(); i++) {
			int e = neigh[v][i];
			if (E[e].f < E[e].c && d + E[e].cst < dist[E[e].b]) {
				dist[E[e].b] = d + E[e].cst; par[E[e].b] = e;
				Q.push(ii(-dist[E[e].b], E[e].b));
			}
		}
	}
	if (dist[N - 1] == Inf) return false;
	add = dist[N - 1];
	int v = N - 1;
	while (v) {
		int e = par[v];
		E[e].f++; E[e ^ 1].f--;
		v = E[e].a;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	N = n * m + 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((i + j) % 2) {
				int v = i * m + j + 1;
				Add(0, v, 1, 0);
				for (int d = 0; d < Maxd; d++) {
					int ni = i + dy[d], nj = j + dx[d];
					if (0 <= ni && ni < n && 0 <= nj && nj < m) {
						int u = ni * m + nj + 1;
						Add(v, u, 1, B[i][j] != B[ni][nj]);
					}
				}
			} else {
				int v = i * m + j + 1;
				Add(v, N - 1, 1, 0);
			}
	int add;
	while (getFlow(add)) res += add;
	printf("%d\n", res);
	return 0;
}