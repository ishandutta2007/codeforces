#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <vector>

int n; 
int a[1010000];
typedef long long ll;

int d[1010000];

int main()
{
	int n, s; scanf("%d%d", &n, &s);
	for(int i = 1; i < n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		d[a]++; d[b]++;
	}
	int k = 0;
	for(int i = 1; i <= n; i++)
	{
		if(d[i] == 1) k++;
	}
	printf("%.15lf\n", s * 1.0 / k * 2);
}