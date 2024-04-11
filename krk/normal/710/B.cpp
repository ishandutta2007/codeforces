#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 300005;

int n;
int x[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	sort(x, x + n);
	printf("%d\n", x[(n - 1) / 2]);
	return 0;
}