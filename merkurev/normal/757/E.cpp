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

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}
int add(int a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}
int sub(int a, int b)
{
	a -= b;
	if (a < 0)
		a += MOD;
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
	if (n == 0) return 1;
	int a = fpow(x, n >> 1);
	a = mul(a, a);
	if (n & 1) a = mul(a, x);
	return a;
}
int rev(int x)
{
	return fpow(x, MOD - 2);
}
int divide(int a, int b)
{
	return mul(a, rev(b) );
}

const int N = (int) 1e6 + 100;


const int LOG = 21;
int falpha[N][LOG];
int md[N];

void era()
{
	memset(md, -1, sizeof md);
	for (int i = 2; i < N; i++)
	{
		if (md[i] != -1) continue;
		for (int j = i; j < N; j += i)
			if (md[j] == -1) md[j] = i;
	}
}

void alpha()
{
	falpha[0][0] = 1;
	for (int i = 1; i < LOG; i++)
		falpha[0][i] = 2;

	for (int i = 0; i + 1 < N; i++)
	{
		for (int a = 0; a < LOG; a++)
			for (int b = 0; a + b < LOG; b++)
				sadd(falpha[i + 1][a + b], falpha[i][a] );
	}
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	alpha();
	era();
	int q;
	scanf("%d", &q);
	for (int it = 0; it < q; it++)
	{
		int r, n;
		scanf("%d%d", &r, &n);
		int ans = 1;
		while (n != 1)
		{
			int x = md[n];
			int xcnt = 0;
			while (md[n] == x)
			{
				n /= x;
				xcnt++;
			}
			ans = mul(ans, falpha[r][xcnt] );
		}
		printf("%d\n", ans);
	}

	return 0;
}