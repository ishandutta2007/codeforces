#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 105;
const int Maxm = Maxn * Maxn;
const int Inf = 1000000000;

int n, m;
int v[Maxm], u[Maxm];
int dist[Maxn][Maxn];
ld ways[Maxn][Maxn];
ld cways[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dist[i][j] = (i != j) * Inf;
			ways[i][j] = ld(i == j);
		}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v[i], &u[i]);
		dist[v[i]][u[i]] = dist[u[i]][v[i]] = 1;
		ways[v[i]][u[i]] = ways[u[i]][v[i]] = 1.0l;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) if (i != k)
			for (int j = 1; j <= n; j++) if (j != k) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) { dist[i][j] = dist[i][k] + dist[k][j]; ways[i][j] = 0.0l; }
				if (dist[i][k] + dist[k][j] == dist[i][j]) ways[i][j] += ways[i][k] * ways[k][j];
			}
	for (int i = 0; i < m; i++) {
		ld tways = 0.0l;
		if (dist[1][v[i]] + 1 + dist[u[i]][n] == dist[1][n]) tways += ways[1][v[i]] * ways[u[i]][n];
		if (dist[1][u[i]] + 1 + dist[v[i]][n] == dist[1][n]) tways += ways[1][u[i]] * ways[v[i]][n];
		cways[v[i]] += tways; cways[u[i]] += tways;
	}
	int bi = 1;
	for (int i = 2; i <= n; i++)
		if (cways[i] > cways[bi]) bi = i;
	cout << fixed << setprecision(16) << cways[bi] / ways[1][n] << endl;
	return 0;
}