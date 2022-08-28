#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <map>
using namespace std;



double fpow(double x, int n)
{
	if (n == 0)
		return 1;
	double a = fpow(x, n >> 1);
	a *= a;
	if (n & 1)
		a *= x;
	return a;
}

const int maxn = 1e5 + 100;
double a[maxn];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	double ans = 0;
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		a[i] = fpow((double) i / (double) m, n);
		ans += i * (a[i] - a[i - 1] );
	}
	printf("%.10lf\n", ans);

	return 0;
}