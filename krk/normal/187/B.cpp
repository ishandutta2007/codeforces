#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 62;
const int Maxk = 100;

int n, m, r;
int M[Maxn][Maxn];
int D[Maxk][Maxn][Maxn];

int main()
{
	fill((int*)D, (int*)D + Maxk * Maxn * Maxn, Inf);
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				scanf("%d", &M[j][k]);
		for (int l = 1; l <= n; l++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					M[j][k] = min(M[j][k], M[j][l] + M[l][k]);
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				D[0][j][k] = min(D[0][j][k], M[j][k]);
	}
	for (int i = 1; i < Maxk; i++)
		for (int l = 1; l <= n; l++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					D[i][j][k] = min(D[i][j][k], D[i - 1][j][l] + D[0][l][k]);
	while (r--) {
		int s, t, k; scanf("%d %d %d", &s, &t, &k);
		printf("%d\n", D[min(k, Maxk - 1)][s][t]);
	}
	return 0;
}