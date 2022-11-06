#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 

long long a[201000], b[201000];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n / 2; i++) scanf("%lld", &b[i]);
	a[1] = 0, a[n] = b[1];
	for(int i = 2; i <= n / 2; i++)
	{
		a[i] = a[i - 1];
		a[n - i + 1] = b[i] - a[i];
		if(a[n - i + 1] > a[n - i + 2])
		{
			a[i] += a[n - i + 1] - a[n - i + 2];
			a[n - i + 1] = a[n - i + 2]; 
		}
	}
	for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
	return 0;
}