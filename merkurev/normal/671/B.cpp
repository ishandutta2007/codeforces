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

const int N = (int) 5e5 + 100;
const int INT_INF = (int) 1e9 + 100;
//const long long INF = (long long) 1e18 + 100;
long long c[N];
int n, k;

long long getMin()
{
	long long rem = k;
	long long cur = 0;
	for (int i = 0; i < n; i++)
	{
		long long d = c[i] - cur;
		if (rem < d * i)
		{
			return cur + rem / i;
		}
		rem -= d * i;
		cur = c[i];
	}
	return cur;
}

long long getMax()
{
	reverse(c, c + n);
	for (int i = 0; i < n; i++)
		c[i] = INT_INF - c[i];
	long long ans = getMin();
	reverse(c, c + n);
	for (int i = 0; i < n; i++)
		c[i] = INT_INF - c[i];
	return INT_INF - ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%lld", &c[i] );
	sort(c, c + n);
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += c[i];

	long long a = getMin();
	long long b = getMax();

	long long ans = max(b - a, (sum % n) ? 1LL : 0LL);
	printf("%lld\n", ans);

	return 0;
}