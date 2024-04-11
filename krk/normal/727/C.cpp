#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 5005;

int n;
int x, y, z;
int a[Maxn];

int Ask(int i, int j)
{
	printf("? %d %d\n", i, j); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d", &n);
	x = Ask(1, 2);
	y = Ask(1, 3);
	z = Ask(2, 3);
	a[1] = (x + y - z) / 2;
	a[2] = x - a[1];
	a[3] = y - a[1];
	for (int i = 4; i <= n; i++) {
		int sum = Ask(1, i);
		a[i] = sum - a[1];
	}
	printf("!");
	for (int i = 1; i <= n; i++)
		printf(" %d", a[i]);
	printf("\n"); fflush(stdout);
	return 0;
}