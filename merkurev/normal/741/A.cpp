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
int k[N];

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}
int a[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i]--;
	}

	for (int i = 0; i < n; i++)
	{
		int v = i;
		for (int j = 0; j < n; j++)
		{
			v = a[v];
			if (v == i)
			{
				k[i] = j + 1;
				break;
			}
		}
		if (k[i] == 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	long long ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (k[i] % 2 == 0)
			ans = lcm(ans, k[i] / 2);
		else
			ans = lcm(ans, k[i] );
	}
	printf("%lld\n", ans);


	return 0;
}