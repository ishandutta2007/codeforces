#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

int n, a[1010000];
int A, B, C, D;

int main()
{
	scanf("%d", &n);
	for(int a = 1; a <= n; a++)
		for(int b = 1; b <= n; b++)
		{
			if(a % b == 0)
			{
				if(a / b < n && a * b > n) return 0 * printf("%d %d\n", a, b);
			}
		}
	puts("-1");
	return 0;
}