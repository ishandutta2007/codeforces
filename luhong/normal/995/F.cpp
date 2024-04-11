#include <cstdio>
#include <iostream>
#define mod 1000000007

int n, d, fa[3010];
int f[3010][3010];
int g[3010];
int C[3010][3010];
int inv[3010];

int main()
{
	scanf("%d%d", &n, &d);
	
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 0; i <= n; i++) C[i][i] = C[i][0] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	
	for(int i = 2; i <= n; i++) scanf("%d", &fa[i]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) f[i][j] = 1;
	
	for(int i = n; i >= 2; i--)
	{
		int sum = 0;
		for(int j = 1; j <= n; j++)
		{
			sum = (sum + f[i][j]) % mod;
			f[fa[i]][j] = 1ll * f[fa[i]][j] * sum % mod;
		}
	}
	
	for(int i = 1; i <= n; i++) f[1][i] = (f[1][i] + f[1][i - 1]) % mod;
	if(d <= n) return 0 * printf("%d\n", f[1][d]);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if((i - j) & 1) g[i] = (g[i] - 1ll * C[i][j] * f[1][j] % mod + mod) % mod;
			else g[i] = (g[i] + 1ll * C[i][j] * f[1][j]) % mod;
		}
		int c = 1;
		for(int j = d; j >= d - i + 1; j--) c = 1ll * c * j % mod;
		for(int j = 1; j <= i; j++) c = 1ll * c * inv[j] % mod;
		ans = (ans + 1ll * c * g[i]) % mod;
	}
	printf("%d\n", ans);
}

/*f[i][j]ij
g[k]1

f[j] = sigma k=0~j g[k] * C(j, k)
 g[k] = sigma j=0~k (-1)^(k-j)*C(k,j)*f[j]
*/