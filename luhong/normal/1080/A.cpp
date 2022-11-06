#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <set> 
#define MN

int n, k;
int main()
{
	scanf("%d%d", &n, &k);
	int a = 2 * n, b = 5 * n, c = 8 * n;
	printf("%d\n", a / k + (a % k > 0) + b / k + (b % k > 0) + c / k + (c % k > 0) );
	return 0;
}