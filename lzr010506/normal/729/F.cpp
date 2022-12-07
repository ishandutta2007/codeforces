#include <bits/stdc++.h>
using namespace std;
#define N 4010
int f[N][N], g[N][N], F[N][N], G[N][N], s[N], n, ss;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", s + i), s[i] += s[i - 1];
	while (ss * (ss + 1) / 2 <= n) ss ++;
	for (int i = ss; i != 0; i --)
	{
		for (int j = n; ~j; j --)
		{
			for (int k = min(j + i - 1, n - j); k >= j; k--)
				if (j + k + i > n) F[j][k] = s[j] + s[n - k] - s[n];
				else if (j + k + i == n) F[j][k] = G[j + i][k];
				else F[j][k] = max(G[j + i][k], g[j + i + 1][k]);
			for (int k = min(j - 1, n - j); k >= j - i && k >= 0; k--)
				if (j + k + i > n) G[j][k] = s[j] + s[n - k] - s[n];
				else if (j + k + i == n) G[j][k] = F[j][k + i];
				else G[j][k] = min(F[j][k + i], f[j][k + i + 1]);
		}
		for (int j = n; ~j; j --)
		{
			for (int k = min(j + i - 1, n - j); k >= j; k --) f[j][k] = F[j][k];
			for (int k = min(j - 1, n - j); k >= j - i && k >= 0; k --) g[j][k] = G[j][k];
		}
	}
	printf("%d\n", f[0][0]);
	return 0;
}