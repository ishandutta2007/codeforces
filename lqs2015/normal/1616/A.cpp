#include <bits/stdc++.h>
using namespace std;
int test, n, a[111], cnt[111], ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i] = abs(a[i]);
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) cnt[a[i]] ++;
		if (cnt[0]) ans = 1;
		else ans = 0;
		for (int i = 1; i <= 100; i++)
		{
			if (cnt[i] >= 2) ans += 2;
			else if (cnt[i]) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}