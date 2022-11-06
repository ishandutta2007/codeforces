#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

int n, a[1010000], k;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int j = 1;
	int lst = 0;
	for(int i = 1; i <= k; i++)
	{
		while(j <= n && a[j] == a[j + 1]) j++;
		if(j > n) puts("0");
		else
		{
			printf("%d\n", a[j] - lst);
			lst = a[j];
			j++;
		}
		
	}
	return 0;
}