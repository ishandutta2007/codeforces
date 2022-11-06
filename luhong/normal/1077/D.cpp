#include <iostream>
#include <algorithm>
#include <cstdio>

int cnt[1010000];
int a[1010000], tot = 0;
int n, k;

int check(int x)
{
	tot = 0;
	int sum = 0;
	for(int i = 1; i <= 200000; i++)
	{
		for(int j = x; j <= cnt[i]; j += x)
		{
			sum++; a[++tot] = i;
		}
	}
	return sum;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	int l = 1, r = n + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid) >= k) l = mid + 1;
		else r = mid;
	}
	check(r - 1);
	for(int i = 1; i <= k; i++) printf("%d ", a[i]);
	return 0;
}