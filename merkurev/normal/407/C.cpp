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

const int mod = (int) 1e9 + 7;

void sub(int &a, int b)
{
	a -= b;
	if (a < 0)
		a += mod;
}
void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
int sum(int a, int b)
{
	return (a + b) % mod;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

int fpow(int x, int n)
{
	if (n == 0)
		return 1;
	int a = fpow(x, n >> 1);
	a = mul(a, a);
	if (n & 1)
		a = mul(a, x);
	return a;
}

int rev(int x)
{
	return fpow(x, mod - 2);
}

const int maxn = (int) 1e5 + 200;
int fact[maxn];
int rfact[maxn];


void init()
{
	fact[0] = 1;
	rfact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = mul(i, fact[i - 1] );
		rfact[i] = rev(fact[i] );
	}
}

int getC(int n, int k)
{
	if (k < 0 || k > n)
		return 0;
	return mul(fact[n], mul(rfact[n - k], rfact[k] ) );
}

const int maxk = 105;
int dp[maxn][maxk];
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	init();

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
	}
	for (int it = 0; it < m; it++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l--;
		
		for (int i = 0; i <= k; i++)
		{
			add(dp[l][i], getC(k, k - i) );
			sub(dp[r][i], getC(k + r - l, k - i) );
		}
	}
	for (int i = 0; i < n; i++)
	{
		add(a[i], dp[i][0] );
		printf("%d ", a[i] );
		for (int j = 0; j + 1 < maxk; j++)
		{
			add(dp[i][j], dp[i][j + 1] );
			add(dp[i + 1][j], dp[i][j] );
		}
	}



	return 0;
}