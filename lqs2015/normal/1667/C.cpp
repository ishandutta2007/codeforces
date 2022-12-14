#include <bits/stdc++.h>
using namespace std;
int n, l, r, mid;
int main()
{
	scanf("%d", &n);
	l = 1; r = n;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if (mid >= 2 * (n - mid) - 1) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", l);
	for (int i = 1; i <= n - l; i++)
	{
		printf("%d %d\n", i,  n - l + 1 - i);
	}
	for (int i = n - l + 1; i <= 2 * (n - l) - 1; i++)
	{
		printf("%d %d\n", i, (n - l + 1) + (2 * (n - l) - 1) - i);
	}
	for (int i = max(2 * (n - l), 1); i <= l; i++) printf("%d %d\n", i, i);
	return 0;
}