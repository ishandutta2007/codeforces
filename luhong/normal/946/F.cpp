#include <iostream>
#include <cstdio>
#define mod 1000000007
#define MN 110

int f[MN][MN][MN];
char s[MN];
int mi[MN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0') f[0][i][i] = 1;
		else f[1][i][i] = 1;
	}
	mi[0] = mi[1] = 2; for(int i = 2; i <= m; i++) mi[i] = 1ll * mi[i - 1] * mi[i - 2] % mod;
	for(int i = 2; i <= m; i++)
	{
		for(int l = 1; l <= n; l++)
			for(int r = l; r <= n; r++)
				for(int mid = l - 1; mid <= r; mid++)
					if(mid == l - 1) f[i][l][r] = (f[i][l][r] + 1ll * (l == 1 ? mi[i - 1] : 1) * f[i - 2][l][r]) % mod;
					else if(mid == r) f[i][l][r] = (f[i][l][r] + 1ll * (r == n ? mi[i - 2] : 1) * f[i - 1][l][r]) % mod;
					else f[i][l][r] = (f[i][l][r] + 1ll * f[i - 1][l][mid] * f[i - 2][mid + 1][r]) % mod;
	}
	printf("%d\n", f[m][1][n]);
}