#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

int n, h, a[1010];

int main()
{
	scanf("%d%d", &n, &h);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		std::sort(a + 1, a + i + 1);
		long long sum = 0, sum2 = 0;
		for(int j = 1; j <= i; j += 2)
		{
			if(j == i) sum += a[j];
			else sum += a[j + 1];
		}
		for(int j = i; j >= 1; j -= 2)
		{
			sum2 += a[j];
		}
		if(std::min(sum, sum2) > h) return 0 * printf("%d\n", i - 1); 
	}
	printf("%d\n", n);
}