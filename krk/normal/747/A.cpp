#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	int a = 1;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) a = i;
	printf("%d %d\n", a, n / a);
	return 0;
}