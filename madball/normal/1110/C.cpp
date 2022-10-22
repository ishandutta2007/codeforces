#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

unordered_map<int, int> cache;
int doit(int a)
{
	if (a == 1048575) return 349525;
	if (a == 2097151) return 299593;
	if (a == 4194303) return 1398101;
	if (a == 8388607) return 178481;
	if (a == 16777215) return 5592405;
	if (a == 33554431) return 1082401;
	auto it = cache.find(a);
	if (it != cache.end())
		return it->second;
	int res = -1;
	if (a < 5 || (a & (a + 1)) == 0)
	{
		for (int b = 1; b < a; ++b)
			res = max(res, gcd(a ^ b, a & b));
	}
	else
	{
		res = 1;
		while (res <= a)
			res <<= 1;
		--res;
	}
	cache[a] = res;
	return res;
}

void solve()
{
	int q;
	cin >> q;
	For(test, q)
	{
		int a;
		cin >> a;
		cout << doit(a) << '\n';
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
#ifdef LOCAL
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}