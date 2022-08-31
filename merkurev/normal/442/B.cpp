#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxn = 105;
double p[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i] );

	double ans1 = 0, ans0 = 1;
	sort(p, p + n);
	reverse(p, p + n);
	for (int i = 0; i < n; i++)
	{
		double nans0 = ans0 * (1. - p[i] );
		double nans1 = ans1 * (1. - p[i] ) + ans0 * p[i];
		if (nans1 < ans1)
			break;
		ans1 = nans1;
		ans0 = nans0;
	}
	printf("%.12lf\n", ans1);

	return 0;
}