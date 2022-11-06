#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int n;
int a[20];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int S = 0; S < (1 << n); S++)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if((S >> i) & 1) sum += a[i];
			else sum -= a[i];
		}
		if(sum % 360 == 0) return 0 * puts("YES");
	}
	puts("NO");
}