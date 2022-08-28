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


const int N = 105;
int a[N];
//const int K = (int) 1e6 + 100;
//const int X = (int) 10;
//const int BL = 10;
const int K = (int) 5e5 + 100;
const int X = (int) 5e5 + 100;
const int BL = 2005;
int v[K];
int sz;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);
	
	long long Xover = 0;
	long long Xsum = 0;
	long long ans = 1;
	for (int d = 1; d <= X; d++)
	{
		long long sum = 0;
		long long over = 0;
		for (int i = 0; i < n; i++)
		{
			int rem = a[i] % d;
			if (rem != 0)
				over += d - rem;
			sum += (a[i] + d - 1) / d;
		}
		if (over <= k)
			ans = d;
		Xover = over;
		Xsum = sum;
	}
//	eprintf("%d %d\n", a[0], a[n - 1] );
//	eprintf("X = %d, Xover = %lld\n", X, Xover);
	
	for (int i = 0; i < n; i++)
		for (int x = 1; x <= BL; x++)
		{
			int c = (a[i] + x - 1) / x;
			if (c > X) v[sz++] = c;
		}
	sort(v, v + sz);
	long long cur = X;
	
	for (int it = 0; it <= sz; it++)
	{
		if (Xover <= k)
		{
			long long add = (k - Xover) / Xsum;
//			eprintf("it = %d, cur = %lld, Xover = %lld, add = %lld\n", it, cur, Xover, add);
//			eprintf("Xsum = %lld\n", Xsum);
			ans = cur + add;
		}
		if (it == sz) break;
//		eprintf("%d\n", v[it]);
		Xover += (v[it] - cur) * Xsum;
		cur = v[it];
		Xover -= cur;
		Xsum--;
	}
	printf("%lld\n", ans);

	return 0;
}