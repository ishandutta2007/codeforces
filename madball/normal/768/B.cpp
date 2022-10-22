#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e+9 + 7;
const ld eps = 1e-7;

#ifdef LOCAL
//#define STRESS
#endif


ll gget(ll n, ll len, ll i)
{
	if (i == len / 2 + 1)
		return n % 2;
	if (i > len / 2)
		i -= len / 2 + 1;
	return gget(n / 2, len / 2, i);
}

void solve()
{
	ll n, len;
	ll l, r;
	scanf("%lld %lld %lld", &n, &l, &r);
	for (len = 1; len <= n; len *= 2);
	--len;
	ll res = 0;
	for (; l <= r; ++l)
		res += gget(n, len, l);
	printf("%lld", res);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}