#define _CRT_SECURE_NO_WARNINGS

#ifndef ONLINE_JUDGE
#pragma comment(linker, "/STACK:100500500")
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


#ifndef ONLINE_JUDGE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define epritnf(...) 42;
#endif

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}

const int K = 2;

struct Matr
{
	int a[K][K];
	Matr() : a() {}

	static Matr ONE()
	{
		Matr ans = Matr();
		for (int i = 0; i < K; i++)
			ans.a[i][i] = 1;
		return ans;
	}

	Matr operator * (const Matr &A) const
	{
		Matr ans = Matr();
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				ans.a[i][j] = (a[i][0] * 1LL * A.a[0][j] + a[i][1] * 1LL * A.a[1][j] ) % MOD;
		return ans;
	}

	Matr fpow(long long n)
	{
		Matr ans = ONE();
		Matr cur = *this;
		for (int i = 0; i < 60; i++)
		{
			if (n & (1LL << i))
				ans = ans * cur;
			cur = cur * cur;
		}
		return ans;
	}
};


int fpow(int x, long long n)
{
	if (n == 0) return 1;
	int a = fpow(x, n >> 1);
	a = mul(a, a);
	if (n & 1) a = mul(a, x);
	return a;
}
int rev(int a)
{
	return fpow(a, MOD - 2);
}
int divi(int a, int b)
{
	return mul(a, rev(b) );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("errput.txt", "w", stderr);
#endif

	int k;
	scanf("%d", &k);
	
	Matr up = Matr();
	long long down = 2;

	up.a[0][0] = 1;
	up.a[1][0] = 2;
	up.a[0][1] = 1;
	up.a[1][1] = 0;



	for (int i = 0; i < k; i++)
	{
		long long x;
		scanf("%lld", &x);
		up = up.fpow(x);
		down = fpow(down, x);
	}
	printf("%d/%d\n", divi(up.a[1][1], 2), divi(down, 2) );

	return 0;
}