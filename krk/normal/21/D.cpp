#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 15;
const int Maxm = 2005;

int n, m;
int a[Maxm], b[Maxm], w;
int dist[Maxn][Maxn];
int deg[Maxn];
int res;
int D[1 << Maxn];

bool badCheck()
{
	for (int i = 1; i < n; i++)
		if (dist[0][i] == Inf && deg[i])
			return true;
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = (i != j) * Inf;
	while (m--) {
		int a, b, w; scanf("%d %d %d", &a, &b, &w); a--; b--; res += w;
		deg[a]++; deg[b]++;
		dist[a][b] = dist[b][a] = min(dist[a][b], w);
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	if (badCheck()) printf("-1\n");
	else {
		int mask = 0;
		for (int i = 0; i < n; i++)
			if (deg[i] % 2 == 0) mask |= 1 << i;
		fill(D, D + (1 << n), Inf); D[mask] = res;
		priority_queue <ii> Q; Q.push(ii(-D[mask], mask));
		while (!Q.empty()) {
			int v = Q.top().second, d = -Q.top().first; Q.pop();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) 
					if (i != j && dist[i][j] != Inf) {
						int u = v ^ 1 << i ^ 1 << j;
						if (d + dist[i][j] < D[u]) {
							D[u] = d + dist[i][j]; Q.push(ii(-D[u], u));
						}
					}
		}
		printf("%d\n", D[(1 << n) - 1]);
	}
	return 0;
}