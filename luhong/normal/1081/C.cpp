#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 
#define mod 998244353

int f[2010][2010];
int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	f[1][0] = m;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= k; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j) f[i][j] = (f[i][j] + 1ll * f[i - 1][j - 1] * (m - 1)) % mod;
		}
	printf("%d\n", f[n][k]);
}