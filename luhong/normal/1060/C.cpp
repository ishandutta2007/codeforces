#include <cstdio>
#include <iostream>
#include <algorithm>

long long a[2010], b[2010];
long long c[2010], d[2010];

using namespace std;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] = a[i - 1] + a[i], c[i] = 1e18;
	for(int i = 1; i <= m; i++) scanf("%lld", &b[i]), b[i] = b[i - 1] + b[i], d[i] = 1e18;
	long long x; scanf("%lld", &x);
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			c[j - i + 1] = min(c[j - i + 1], a[j] - a[i - 1]); 
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			d[j - i + 1] = min(d[j - i + 1], b[j] - b[i - 1]); 
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(c[i] * d[j] <= x)
			{
				ans = max(ans, i * j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}