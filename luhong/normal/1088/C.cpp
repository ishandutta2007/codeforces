#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

int n, a[1010000], k;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int t = 0;
	printf("%d\n", n + 1);
	for(int i = n; i >= 1; i--)
	{
		a[i] += t;
		printf("%d %d %d\n", 1, i, n - a[i] % n + i - 1);
		t += n - a[i] % n + i - 1;
	}
	printf("%d %d %d\n", 2, n, n);
	return 0;
}