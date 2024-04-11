#include <bits/stdc++.h>
using namespace std;
int test, n, ans[111111], lt, lp, hig, flg;
long long pw[111111], k, lst;
long long get(int k)
{
	if (k < 0) return 1;
	return pw[k];
}
int main()
{
	pw[0] = 1;
	for (int i = 1; i <= 100; i++) pw[i] = (pw[i - 1] + pw[i - 1]) ;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%lld", &n, &k);
		lst = k;
		lt = 0; lp = 0;
		hig = 1;
		flg = 0;
		for (int i = 1; i <= n; i++)
		{
			if (lt > lp)
			{
				lt--;
				ans[i] = lt;
				continue;
			}
			lp = hig;
			ans[i] = 0;
			for (int j = hig; j <= n; j++)
			{
				if (n - j - 1 <= 60 && get(n - j - 1) < lst)
				{
					lst -= get(n - j - 1);
				}
				else
				{
					ans[i] = lt = j;
					hig = j + 1;
					break;
				}
			}
			if (!ans[i]) 
			{
				flg = 1;
				break;
			}
		}
		if (!flg)
		{
			for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}