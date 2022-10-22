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
	int res = n / 2;
	printf("%d\n", res);
	if (n % 2) printf("3");
	else printf("2");
	for (int i = 0; i < res - 1; i++)
		printf(" 2");
	printf("\n");
	return 0;
}