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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;
const int maxn = 205;
int f[maxn];
int timer = 146;
int used[maxn];
bool onC[maxn];

bool dfs(int v, int to)
{
	if (used[v] == timer)
	{
		return v == to;
	}
	used[v] = timer;
	return dfs(f[v], to);
}

int dfsLen(int v)
{
	if (used[v] == timer)
		return 0;
	used[v] = timer;
	return 1 + dfsLen(f[v] );
}

int dfsC(int v)
{
	if (onC[v] )
		return 0;
	return 1 + dfsC(f[v] );
}

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &f[i] );
		f[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		timer++;
		if (dfs(i, i) )
			onC[i] = true;
	}
	long long len = 1;
	for (int i = 0; i < n; i++)
	{
		timer++;
		if (onC[i] )
		{
			long long cur = dfsLen(i);
			len = lcm(len, cur);
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		if (!onC[i] )
		{
			mx = max(mx, dfsC(i) );
		}
	}
	for (long long k = 1; ; k++)
	{
		long long ans = len * k;
		if (ans >= mx)
		{
			printf("%lld\n", ans);
			return 0;
		}
	}

	return 0;
}