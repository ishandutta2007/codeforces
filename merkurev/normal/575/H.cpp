#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const ll MOD = (ll)1e9 + 7;
ll sum(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	return sum(x, MOD - y);
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2) return mult(x, x);
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}



int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int n;
	cin >> n;
	n++;
	ll res = 1;
	for (int i = n + 1; i <= 2 * n; i++)
		res = mult(res, i);
	ll x = 1;
	for (int i = 1; i <= n; i++)
		x = mult(x, i);
	res = mult(res, rev(x));
	res = sub(res, 1);
	cout << res << endl;

	return 0;
}