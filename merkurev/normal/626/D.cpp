#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 5005;
int q[N];
int cnt[N];
int cntGR[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i] );
	sort(q, q + n);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cnt[q[j] - q[i] ]++;

	for (int i = N - 2; i >= 0; i--)
	{
		cntGR[i] = cntGR[i + 1] + cnt[i + 1];
	}

	double ans = 0;
	for (int a = 1; a < N; a++)
		for (int b = 1; a + b < N; b++)
		{
			ans += (double) cnt[a] * (double) cnt[b] * (double) cntGR[a + b];
		}
	double x = (double) n * (double) (n - 1) / 2.;
	double xcnt = x * x * x;


	printf("%.10lf\n", ans / xcnt);

	return 0;
}