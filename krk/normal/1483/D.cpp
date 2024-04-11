#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 605;
const int Maxm = Maxn * Maxn;

int n, m;
int a[Maxm], b[Maxm], c[Maxm];
ll dist[Maxn][Maxn];
int q;
ll mx[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = (i != j) * Inf;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], ll(c[i]));
		dist[b[i]][a[i]] = min(dist[b[i]][a[i]], ll(c[i]));
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	scanf("%d", &q);
	while (q--) {
		int u, v, l; scanf("%d %d %d", &u, &v, &l);
		mx[u][v] = max(mx[u][v], ll(l));
		mx[v][u] = max(mx[v][u], ll(l));
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				mx[i][k] = max(mx[i][k], mx[i][j] - dist[k][j]);
				mx[k][j] = max(mx[k][j], mx[i][j] - dist[i][k]);
			}
	int res = 0;
	for (int i = 0; i < m; i++)
		res += mx[a[i]][b[i]] >= c[i];
	printf("%d\n", res);
    return 0;
}