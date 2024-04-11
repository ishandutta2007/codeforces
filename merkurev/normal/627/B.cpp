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

const int N = (int) 2e5 + 100;

int toa[N], tob[N];
long long fna[N], fnb[N];

void add(long long fn[], int pos, int val)
{
	for (; pos < N; pos = (pos | (pos - 1) ) + 1)
		fn[pos] += val;
}
long long sum(long long fn[], int pos)
{
	pos = min(pos, N - 1);
	long long ans = 0;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
		ans += fn[pos];
	return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n, k, a, b, q;
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	for (int it = 0; it < q; it++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int d, x;
			scanf("%d%d", &d, &x);
			int deltaa = min(x, a - toa[d] );
			int deltab = min(x, b - tob[d] );
			toa[d] += deltaa;
			tob[d] += deltab;
			add(fna, d, deltaa);
			add(fnb, d, deltab);
		}
		else
		{
			int d;
			scanf("%d", &d);
			long long suma = sum(fna, N - 1) - sum(fna, d + k - 1);
			long long sumb = sum(fnb, d - 1);
			printf("%lld\n", suma + sumb);
		}
	}



	return 0;
}