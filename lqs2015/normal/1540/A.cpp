#include <bits/stdc++.h>
using namespace std;
int test, n, a[111111];
long long suf[111111], ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		suf[n + 1] = 0;
		for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
		ans = 0;
		for (int i = 1; i <= n - 2; i++)
		{
			ans += (suf[i + 2] - 1ll * a[i] * (n - 1 - i));
		}
		printf("%lld\n", -ans);
	}
	return 0;
}