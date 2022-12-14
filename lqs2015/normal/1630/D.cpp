#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}
int test, n, m, x, y, a[1111111], pos, num[1111111], lst[1111111], cc, mn, cnt;
long long ans, e1, e2;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		scanf("%d", &x);
		for (int i = 1; i < m; i++)
		{
			scanf("%d", &y);
			x = gcd(x, y);
		}
		ans = 0;
		/*for (int i = 0; i < x; i++) num[i] = 0;
		lst[0] --;
		for (int i = 1; i <= n; i++)
		{
			pos = arr[i].second;
			lst[pos % x] --;
			assert(lst[pos % x] >= 0);
			if (lst[pos % x])
			{
				ans += arr[i].first;
				num[pos % x] ^= (a[pos] < 0);
			}
			else
			{
				if (cc == -1 || cc == (num[pos % x] ^ (a[pos] < 0))) 
				{
					num[pos % x] ^= (a[pos] < 0);
					cc = num[pos % x];
					ans += arr[i].first;
				}
				else ans -= arr[i].first;
			}
		}*/
		for (int i = 1; i <= n; i++) ans += abs(a[i]);
		e1 = e2 = 0;
		for (int i = 1; i <= x; i++)
		{
			cnt = 0; mn = 2e9;
			for (int j = i; j <= n; j += x)
			{
				if (a[j] < 0) 
				{
					cnt ++;
				}
				mn = min(mn, abs(a[j]));
			}
			if (cnt & 1) 
			{
				e1 += (2 * mn);
			}
			else e2 += (2 * mn);
		}
		printf("%lld\n", max(ans - e1, ans - e2));
	}
	return 0;
}