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
const int maxc = (int) 1e7 + 100;
const int mod = (int) 1e9 + 7;

int a[maxn];
int cnt[maxc];
int ck[maxc];
int deg2[maxn];

int divs[maxn];
int sz;


int mul(int _a, int b)
{
	return (_a * 1LL * b) % mod;
}
void add(int &_a, int b)
{
	_a += b;
	if (_a < 0)
		_a += mod;
	if (_a >= mod)
		_a -= mod;
}
int sum(int _a, int b)
{
	add(_a, b);
	return _a;
}


void precalcDeg2()
{
	deg2[0] = 1;
	for (int i = 1; i < maxn; i++)
		deg2[i] = mul(deg2[i - 1], 2);
}

int answer = 0;
int oneAns = 0;

void addToAns(int pos = 0, int val = 1, int k = 0)
{
	if (pos == sz)
	{
		if (val == 1)
			return;
		int x = deg2[cnt[val] ];
		add(x, -1);
		if (k % 2 == 1)
			add(oneAns, x);
		else 
			add(oneAns, -x);
		return;
	}
	addToAns(pos + 1, val, k);
	addToAns(pos + 1, val * divs[pos], k + 1);
}

void addDivs(int pos = 0, int val = 1, int k = 0)
{
	if (pos == sz)
	{
		ck[val] = k;
		cnt[val]++;	
		return;
	}
	addDivs(pos + 1, val, k);
	addDivs(pos + 1, val * divs[pos], k + 1);
}

void precalc(int x)
{
	sz = 0;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i != 0)
			continue;
		while (x % i == 0)
			x /= i;
		divs[sz++] = i;
	}
	if (x != 1)
		divs[sz++] = x;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	precalcDeg2();

	for (int i = 0; i < n; i++)
	{
		precalc(a[i] );
		addDivs();
	}
	int numAll = 0;
	for (int i = 2; i < maxc; i++)
	{
		if (cnt[i] == 0)
			continue;
		int x = deg2[cnt[i] ];
		add(x, -1);
		if (ck[i] % 2 == 1)
			add(numAll, x);
		else
			add(numAll, -x);
	}

	for (int i = 0; i < n; i++)
	{
		oneAns = 0;
		precalc(a[i] );
		addToAns();

		int x = numAll;
		add(x, -oneAns);
		add(answer, x);
	}

	printf("%d\n", answer);

	return 0;
}