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


const int maxn = (int) 5e5 + 100;
int a[maxn];
bool used[maxn];
int val[maxn];

int d[maxn];
bool isP[maxn];


long long ans = 0;
int p[20];
int psz = 0;

void gen(int cur, int gk, int k, int x)
{
	if (cur == -1)
	{
		if (gk == 1)
		{
			ans += k * val[x];
			val[x] ++;
		}
		else
		{
			val[x] --;
			ans += k * val[x];
		}
		return;
	}
	gen(cur - 1, gk, k, x);
	gen(cur - 1, gk, -k, x * p[cur] );
}

void add(int i, int k)
{
	psz = 0;
	while (i != 1)
	{
		if (psz == 0 || p[psz - 1] != d[i] )
			p[psz++] = d[i];
		i /= d[i];
	}
	gen(psz - 1, k, k, 1);
}


int main(int, char **)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	memset(isP, true, sizeof isP);
	for (int i = 2; i < maxn; i++)
	{
		if (!isP[i] )
			continue;
		d[i] = i;
		for (long long j = i * 1LL * i; j < maxn; j += i)
		{
			if (isP[j] )
			{
				isP[j] = false;
				d[j] = i;
			}
		}
	}

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		if (used[x] )
		{
			used[x] = false;
			add(a[x], -1);
		}
		else
		{
			used[x] = true;
			add(a[x], 1);
		}
		printf("%lld\n", ans);
	}


	return 0;
}