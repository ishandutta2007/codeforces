#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000003;

ll n, k;

int toPower(int a, ll p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

ll Get(ll cur)
{
	if (cur == 0) return (k - 1) / mod;
	ll newk = k - 1 - cur;
	return newk >= 0? newk / mod + 1: 0;
}

ll Away(ll newk)
{
	ll res = 0;
	for (ll cur = 2; cur <= newk; cur *= 2)
		res += newk / cur;
	return res;
}

int main()
{
	scanf("%I64d %I64d", &n, &k);
	if (n <= 60 && (1ll << ll(n)) < k) { printf("1 1\n"); return 0; }
	int cur = toPower(2, n);
	int tot = toPower(cur, k - 1);
	int a = 1;
	for (int i = 0; i < mod; i++)
		a = ll(a) * toPower((cur - i + mod) % mod, Get(i)) % mod;
	int g = toPower(2, Away(k - 1));
	a = ll(a) * Inv(g) % mod;
	tot = ll(tot) * Inv(g) % mod;
	printf("%d %d\n", (tot - a + mod) % mod, tot);
	return 0;
}