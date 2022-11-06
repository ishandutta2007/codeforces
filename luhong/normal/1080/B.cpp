#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <set> 
#define MN 501000

long long solve(int x)
{
	if(x & 1) return x / 2 - x;
	else return x / 2;
}
int main()
{
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int l, r; scanf("%d%d", &l, &r);
		printf("%lld\n", solve(r) - solve(l - 1));
	}
	return 0;
}