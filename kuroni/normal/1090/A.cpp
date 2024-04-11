#include <cstdio>

int main()
{
	int n; scanf("%d", &n);
	long long res = 0;
	int cnt = 0, max = 0;
	for (int i = 1; i <= n; ++i)
	{
		int m; scanf("%d", &m);
		int tmax = 0;
		for (int i = 1; i <= m; ++i)
		{
			int tmp; scanf("%d", &tmp);
			if (tmp > tmax)
				tmax = tmp;
		}
		if (tmax > max)
		{
			res += 1LL * cnt * (tmax - max);
			max = tmax;
		}
		else 
			res += 1LL * m * (max - tmax);
		cnt += m;
	}
	printf("%lld", res);
	return 0;
}