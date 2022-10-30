#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[300005],b[300005],f[300005];

int check(int x)
{
	for (int i = 1; i <= n; i++)
	{
		b[i] = (a[i] + x) % m;
		f[i] = b[i] >= a[i];
	}
	int last;
	if (f[1]) last = a[1];
	else last = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!f[i])
		{
			if (last <= b[i]) continue;
			if (last < a[i]) last = a[i];
			continue;
		}
		if (last > b[i]) return 0;
		if (last < a[i])
		{
			last = a[i];
			continue;
		}
	}
	return 1;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
	}
	int l = 0,r = m - 1,ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	return 0;
}