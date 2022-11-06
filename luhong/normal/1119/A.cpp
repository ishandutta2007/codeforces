#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

int a[301000];
int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != a[n]) ans = std::max(ans, n - i);
		if(a[i] != a[1]) ans = std::max(ans, i - 1);
	}
	printf("%d\n", ans);
}