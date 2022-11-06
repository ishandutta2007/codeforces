#include <cstdio>
#include <iostream>
#include <algorithm>

int a[200100], p[201000];
long long f[200100], g[201000];
int tag[201000];

bool cmp(int x, int y)
{
	return a[x] < a[y];
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = i;
	}
	std::sort(p + 1, p + n + 1, cmp);
	long long Min = 1e18; int id = 0;
	f[0] = 0; f[1] = f[2] = 1e18;
	for(int i = 3; i <= n; i++)
	{
		if(f[i - 3] - a[p[i - 2]] < Min) id = i - 3, Min = f[i - 3] - a[p[i - 2]];
		g[i] = id;
		f[i] = Min + a[p[i]];
	}
	int tot = 0;
	int k = n;
	while(k)
	{
		++tot;
		for(int i = g[k] + 1; i <= k; i++)
			tag[p[i]] = tot;
		k = g[k];
	}
	printf("%lld %d\n", f[n], tot);
	for(int i = 1; i <= n; i++)
		printf("%d ", tag[i]);
}