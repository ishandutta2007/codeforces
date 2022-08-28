#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


int mul(int x, int y, int mod)
{
	return (x * 1LL * y) % mod;
}

int fpow(int x, int n, int mod)
{
	if (n == 0)
		return 1;
	int a = fpow(x, n >> 1, mod);
	a = mul(a, a, mod);
	if (n & 1)
		a = mul(a, x, mod);
	return a;
}

int rev(int x, int mod)
{
	return fpow(x, mod - 2, mod);
}


const int maxn = 1e5 + 100;
int ans[maxn];
bool used[maxn];


int solve(int n)
{
	if (n == 2)
	{
		printf("YES\n1\n2\n");
		return 0;
	}
	if (n == 4)
	{
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	
	memset(used, 0, sizeof used);
	for (int i = 2; i < n; i++)
		if (n % i == 0)
		{
			printf("NO\n");
			return 0;
		}
	used[1] = true;
	ans[0] = 1;
	for (int i = 1; i < n - 1; i++)
	{
		ans[i] = mul(rev(i + 1, n), i, n);
		if (used[ans[i] ] )
			throw 42;
		used[ans[i] ] = true;
	}
	ans[n - 1] = n;

	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i] );

	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	solve(n);
//	for (int i = 1; i < 10000; i++)
//		solve(i);
	return 0;
}