#include <iostream>
#include <algorithm>
#include <cstdio>

int cnt[1010000];
int a[1010000], tot = 0;
int n, k;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == a[i - 1]) cnt[tot]++;
		else tot++, cnt[tot] = 1;
	}
	std::sort(cnt + 1, cnt + tot + 1);
	int Max = 0;
	for(int i = 1; i <= n; i++)
	{
		int sum = 0;
		int lst = 0;
		for(int j = i; j <= n; j *= 2)
		{
			lst = std::lower_bound(cnt + lst + 1, cnt + tot + 1, j) - cnt;
			if(lst != tot + 1) sum += j;
			else break;
		}
		Max = std::max(Max, sum);
	}
	printf("%d\n", Max);
	return 0;
}