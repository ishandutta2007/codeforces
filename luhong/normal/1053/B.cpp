#include <cstdio>
#include <iostream>

int a[301000];
int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		long long x; scanf("%lld", &x);
		for(int j = 60; j >= 0; j--)
			if((x >> j) & 1) a[i]++;
	}
	int s1 = 0, s2 = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & 1) std::swap(s1, s2), s1++;
		else s2++;
		ans += s2;
		int Max = -1, sum = 0;
		for(int j = 0; i - j >= 1 && j < 120; j++)
		{
			Max = std::max(Max, a[i - j]);
			sum += a[i - j];
			if(sum % 2 == 0 && Max > sum / 2) ans--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}