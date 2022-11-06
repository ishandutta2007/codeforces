#include <iostream>
#include <cstdio>
#define mod 1000000007
#define MN 201000 
 
int f[MN][2][2][2];
int n, p, mi[MN];
 
void rw(int &a, int b) {if((a += b) >= mod) a -= mod;}
 
int main()
{
	scanf("%d%d", &n, &p);
	mi[0] = 1; for(int i = 1; i <= n; i++) mi[i] = 2 * mi[i - 1] % mod;
	f[0][0][0][0] = 1; 
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		for(int a = 0; a < 2; a++)
			for(int b = 0; b < 2; b++)
				for(int c = 0; c < 2; c++)
				{
					if(x == 1 || x == -1)
					{
						if(b == 0) rw(f[i][1][b][c ^ 1], 1ll * f[i - 1][a][b][c] * mi[i - 1] % mod);
						else if(i > 1)
						{
							rw(f[i][1][b][c ^ 1], 1ll * f[i - 1][a][b][c] * mi[i - 2] % mod);
							rw(f[i][a][b][c], 1ll * f[i - 1][a][b][c] * mi[i - 2] % mod);
						}
					}
					if(x == 0 || x == -1)
					{
						if(a == 0) rw(f[i][a][1][c ^ 1], 1ll * f[i - 1][a][b][c] * mi[i - 1] % mod);
						else if(i > 1)
						{
							rw(f[i][a][1][c ^ 1], 1ll * f[i - 1][a][b][c] * mi[i - 2] % mod);
							rw(f[i][a][b][c], 1ll * f[i - 1][a][b][c] * mi[i - 2] % mod);
						}
					}
				}
	}
	int ans = 0;
	for(int a = 0; a < 2; a++)
		for(int b = 0; b < 2; b++)
			rw(ans, f[n][a][b][p]);
	printf("%d\n", ans);
}