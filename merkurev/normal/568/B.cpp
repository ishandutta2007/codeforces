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

const int mod = (int) 1e9 + 7;
void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
}
int sum(int a, int b)
{
	add(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

const int maxn = 4005;
int C[maxn][maxn];

int cntAll[maxn];

void solve()
{
	for (int i = 0; i < maxn; i++)
	{
		C[i][0] = C[i][i]  = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j] );
		}
	}
	int n;
	scanf("%d", &n);

	cntAll[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int sz = 1; sz <= i; sz++)
		{
			add(cntAll[i], mul(cntAll[i - sz], C[i - 1][sz - 1] ) );
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		add(ans, mul(cntAll[i], C[n][i] ) );
	}
	printf("%d\n", ans);
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	solve();

	return 0;
}