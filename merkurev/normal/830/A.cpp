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

const long long INF = (long long) 1e18;
const int N = 5005;
long long a[N], b[N];



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	long long p;
	scanf("%d%d%lld", &n, &k, &p);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i] );
	for (int i = 0; i < k; i++)
		scanf("%lld", &b[i] );
	sort(a, a + n);
	sort(b, b + k);
	long long ans = INF;

	for (int f = 0; f + n <= k; f++)
	{
		long long cur = 0;
		for (int i = 0; i < n; i++)
			cur = max(cur, abs(a[i] - b[i + f] ) + abs(p - b[i + f] ) );
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);


	return 0;
}