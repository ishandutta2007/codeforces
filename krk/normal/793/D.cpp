#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 85;
const int Inf = 1000000000;

int n, k;
int m;
int dist[Maxn][Maxn];
int dp[Maxn][Maxn][Maxn][2];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%d", &m);
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * 2, Inf);
	for (int i = 1; i <= n; i++)
		dp[1][0][i][1] = dp[1][i][n + 1][0] = 0;
	for (int i = 1; i < k; i++)
		for (int l = 0; l <= n + 1; l++)
			for (int r = l; r <= n + 1; r++) 
				for (int f = 0; f < 2; f++) if (dp[i][l][r][f] < Inf) {
					int v = f == 0? l: r;
					for (int z = l + 1; z < r; z++)
						if (dist[v][z] < Inf) {
							dp[i + 1][l][z][1] = min(dp[i + 1][l][z][1], dp[i][l][r][f] + dist[v][z]);
							dp[i + 1][z][r][0] = min(dp[i + 1][z][r][0], dp[i][l][r][f] + dist[v][z]);
						}
				}
	int res = Inf;
	for (int l = 0; l <= n + 1; l++)
		for (int r = l; r <= n + 1; r++)
			res = min(res, min(dp[k][l][r][0], dp[k][l][r][1]));
	if (res >= Inf) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}