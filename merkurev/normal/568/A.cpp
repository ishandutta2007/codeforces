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


int _p[20];
bool isPal(int n)
{
	int sz = 0;
	while (n > 0)
	{
		_p[sz++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < sz; i++)
		if (_p[i] != _p[sz - 1 - i] )
			return false;
	return true;
}

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

const int maxx = (int) 2e6;

void solve()
{
	int p, q;
	scanf("%d%d", &p, &q);
	int cntPrime = 0, cntPal = 0;
	int ans = 0;
	for (int i = 1; i < maxx; i++)
	{
		if (isPrime(i) )
			cntPrime++;
		if (isPal(i) )
			cntPal++;
		if (cntPrime * 1LL * q <= cntPal * 1LL * p)
			ans = i;
	}
	printf("%d\n", ans);
//	eprintf("%d %d\n", cntPrime, cntPal);
}


int main(int , char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	solve();

	return 0;
}