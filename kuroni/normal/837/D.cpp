#include <iostream>
#include <cstdio>
using namespace std;

const int INF = 1e9;
int f[2][205][2605], a[205], b[205], n, k, i, j, l, ans = 0, cur = 0;
long long t;

int main()
{
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &t);
		while (t % 2 == 0)
		{
			t /= 2;
			++a[i];
		}
		while (t % 5 == 0)
		{
			t /= 5;
			++b[i];
		}
	}
	for (i = 0; i < 2; i++)
		for (j = 0; j <= k; j++)
			for (l = 0; l <= 2600; l++)
				f[i][j][l] = -INF;
	f[0][0][0] = f[1][0][0] = 0;
	for (i = 1; i <= n; i++)
	{
		cur += b[i];
		for (j = 1; j <= k; j++)
		{
			for (l = b[i]; l <= cur; l++)
				f[i % 2][j][l] = f[1 - i % 2][j - 1][l - b[i]] + a[i];
			for (l = 0; l <= cur; l++)
				f[i % 2][j][l] = max(f[i % 2][j][l], f[1 - i % 2][j][l]);
		}
		
	}
	for (i = 0; i <= cur; i++)
		ans = max(ans, min(i, f[n % 2][k][i]));
	printf("%d", ans);
}