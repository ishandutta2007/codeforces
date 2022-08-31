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
	if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
	sadd(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}
int fpow(int x, long long n)
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
int divi(int a, int b)
{
	return mul(a, rev(b) );
}

const int N = (int) 2e5 + 100;
int fact[N], rfact[N], ri[N];

void init()
{
	fact[0] = 1;
	rfact[0] = 1;
	ri[1] = 1;

	for (int i = 1; i < N; i++)
	{
		fact[i] = mul(fact[i - 1], i);
		if (i > 1) ri[i] = mul(MOD / i, MOD - ri[MOD % i] );
		rfact[i] = mul(rfact[i - 1], ri[i] );
	}

//	for (int i = 0; i < 10; i++)
//		eprintf("%d %d %d\n", fact[0], ri[i], rfact[i] );
}

int C(int n, int k)
{
//	eprintf("n = %d, k = %d\n", n, k);
	if (n < 0 || k < 0 || k > n) return 0;
	int ans = mul(fact[n], mul(rfact[k], rfact[n - k] ) );
//	eprintf("(%d, %d) = %d\n", n, k, ans);
	return ans;
}
int CNT(int n, int k)
{
	if (k == 0 && n > 0) return 0;
	if (k == 0 && n == 0) return 1;
	return C(n + k - 1, n);
}

int solve(int f, int w, int h)
{
	int ans = 0;
	for (int kf = 0; kf <= f; kf++)
	{
		long long takef = kf;
		long long remf = f - takef;
		if (remf < 0) continue;

		for (int kw = kf - 1; kw <= kf + 1; kw++)
		{
			if (kw < 0 || kw > w) continue;
			long long takew = kw * 1LL * (h + 1);
			long long remw = w - takew;
			if (remw < 0) continue;

			int Cf = CNT(remf, kf);
			int Cw = CNT(remw, kw);

			int cur = mul(Cf, Cw);
//			eprintf("kf = %d, kw = %d, cur = %d\n", kf, kw, cur);
//			eprintf("remf = %lld, kf = %d, remw = %lld, kw = %d\n", remf, kf, remw, kw);
//			eprintf("Cf = %d, Cw = %d\n\n", Cf, Cw);
			sadd(ans, cur);
			if (kf == kw)
				sadd(ans, cur);
		}
	}
	return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	init();

	int f, w, h;
	scanf("%d%d%d", &f, &w, &h);

	int good = solve(f, w, h);
	int all = solve(f, w, 0);

//	eprintf("good = %d, all = %d\n", good, all);

	int ans = divi(good, all);

	printf("%d\n", ans);

	return 0;
}