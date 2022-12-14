#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int test, ans1, ans2, n, x, a[333333], prime[222222], cnt, mx[1111111], lst, xr, num[1111111], zro, q;
long long w;
bool f[1111111], used[1111111];
void Init()
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!f[i])
		{
			prime[++cnt] = i;
			mx[i] = i;
		}
		for (int j = 1; j <= cnt && i * prime[j] <= maxn; j++)
		{
			f[i * prime[j]] = 1;
			mx[i * prime[j]] = prime[j];
		}
	}
}
int main()
{
	scanf("%d", &test);
	Init();
	while(test--)
	{
		scanf("%d", &n);
		ans1 = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			a[i] = 1;
			lst = -1;
			while(x > 1)
			{
				if (mx[x] != lst)
				{
					if (~lst && xr)
					{
						a[i] *= lst;
					} 
					xr = 0;
					lst = mx[x];
				}
				xr ^= 1;
				x /= mx[x];
			}
			if (~lst && xr) a[i] *= lst;
			num[a[i]] ++;
			ans1 = max(ans1, num[a[i]]);
		}
		ans2 = zro = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != 1 && (num[a[i]]&1)) ans2 = max(ans2, num[a[i]]);
			if (!used[a[i]])
			{
				used[a[i]] = 1;
				if (a[i] == 1 || !(num[a[i]]&1)) zro += num[a[i]];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			num[a[i]] = used[a[i]] = 0;
		}
		scanf("%d", &q);
		while(q--)
		{
			scanf("%lld", &w);
			if (w == 0) printf("%d\n", ans1);
			else printf("%d\n", max(ans2, zro));
		}
	}
	return 0;
}