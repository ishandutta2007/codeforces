#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, iv = (mod + 1) / 2;
const int maxn = 2000;
int n, m, k, c[2222][2222], test;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
		{
			c[i][0] = 1ll * i * k % mod;
			for (int j = 1; j <= i; j++) c[i][j] = 1ll * (c[i - 1][j - 1] + c[i - 1][j]) * iv % mod;
		}
		printf("%d\n", c[n][n - m]);
	}
	return 0;
}