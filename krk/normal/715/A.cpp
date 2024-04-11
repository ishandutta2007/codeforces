#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;

int main()
{
	scanf("%d", &n);
	printf("2\n");
	for (int i = 2; i <= n; i++)
		printf("%I64d\n", ll(i) * ll(i + 1) * ll(i + 1) - ll(i - 1));
	return 0;
}