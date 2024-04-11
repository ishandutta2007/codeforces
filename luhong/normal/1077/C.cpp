#include <iostream>
#include <algorithm>
#include <cstdio>

long long a[1010000];
int ans[1010000], tot = 0;
int main()
{
	long long Max = 0, cMax = 0, sum = 0;
	
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(a[i] > Max) cMax = Max, Max = a[i];
		else cMax = std::max(cMax, a[i]); 
		sum += a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == Max)
		{
			if(sum - a[i] -cMax == cMax) ans[++tot] = i;
		}
		else
		{
			if(sum - a[i] -Max == Max) ans[++tot] = i;
		}
	}
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++) printf("%d ", ans[i]);
	return 0;
}