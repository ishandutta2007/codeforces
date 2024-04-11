#include <iostream>
#include <algorithm> 
#include <cstdio>
#define MN 1010
#define mod 998244353

int f[MN][MN];
int n, k;
int a[MN];

int solve(int x)
{
	f[0][0] = 1;
	int lst = 0;
	for(int i = 1; i <= n; i++)
	{
		while(a[i] - a[lst + 1] >= x) lst++;
		for(int j = 0; j <= k; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j) f[i][j] = (f[i][j] + f[lst][j - 1]) % mod;
		}
	}
	return f[n][k];
}
 
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= 100000 / (k - 1); i++)
		ans = (ans + solve(i)) % mod;
	printf("%d\n", ans);
}
//min|bi-bj|<=ai/(k-1)xk