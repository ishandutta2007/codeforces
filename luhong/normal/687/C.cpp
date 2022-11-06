#include <cstdio>
#define MN 510

bool f[MN][MN][MN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= m; k++)
			{
				f[i][j][k] |= f[i - 1][j][k];
				if(j >= x) f[i][j][k] |= f[i - 1][j - x][k];
				if(j >= x && k >= x) f[i][j][k] |= f[i - 1][j - x][k - x];
			}
	}
	int ans = 0;
	for(int i = 0; i <= m; i++) if(f[n][m][i]) ans++;
	printf("%d\n", ans);
	for(int i = 0; i <= m; i++) if(f[n][m][i]) printf("%d ", i);
}