#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


const int mod = (int) 1e9 + 7;
const int maxn = 100500;
char str[maxn];
int fact[maxn];
int rfact[maxn];

int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}
int add(int a, int b)
{
	return (a + b) % mod;
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

void init()
{
	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = mul(fact[i - 1], i);
	for (int i = 0; i < maxn; i++)
		rfact[i] = rev(fact[i] );
}

int getC(int n, int m)
{
	if (m < 0 || m > n)
		return 0;
	return mul(fact[n], mul(rfact[m], rfact[n - m] ) );
}

int p[maxn];

int st2(int n)
{
	int ans = 0;
	int deg = 1;

	for (int i = n - 1; i >= 0; i--)
	{
		if (p[i] == 1)
			deg = 1;

		ans = add(ans, mul(str[i] - '0', deg) );

		deg = mul(deg, 10);
	}
	return ans;
}

int stupid(int n, int k)
{
	for (int i = 0; i < n; i++)
		p[i] = 0;
	for (int i = 0; i < k; i++)
		p[i] = 1;
	sort(p, p + n - 1);


	int ans = 0;
	do
	{
		ans = add(ans, st2(n) );
	}
	while (next_permutation(p, p + n - 1) );
	
	return ans;
}

int solve(int n, int k)
{
	int mult = 0;
	int deg10 = 1;
	int mdeg10 = 0;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int curX = mul(deg10, getC(n - i - 1, k) );
			
		int cur = mul(mdeg10, getC(n - i - 1, k - 1) );
		mult = add(mult, cur);
		curX = add(curX, mult);
		
		ans = add(ans, mul(curX, str[n - i - 1] - '0') );
		
		mdeg10 = mul(mdeg10, 10);
		deg10 = mul(deg10, 10);
		if (i == 0)
			mdeg10 = 1;
	}
	return ans;
}

void stress2(int n, int k)
{
	int alt = stupid(n, k);
	int ans = solve(n, k);
	if (alt != ans)
	{
		fprintf(stderr, "%d %d\n", alt, ans);
		throw 42;
	}
	printf("%d\n", ans);

}
void stress()
{
	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 5 + 2;
		int k = rand() % n;
		for (int j = 0; j < n; j++)
			str[j] = rand() % 10 + '0';
		stress2(n, k);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	init();

	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str);

//	stress();

	int ans = solve(n, k);
	printf("%d\n", ans);

	return 0;
}