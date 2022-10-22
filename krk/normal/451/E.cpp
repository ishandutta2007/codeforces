#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 20;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n;
ll s;
ll f[Maxn];
int ways;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int getInv(int a) { return toPower(a, mod - 2); }

int Solve(int n, ll s)
{
	if (s < 0) return 0;
	int res = 1;
	for (ll cur = s + 1; cur <= s + n - 1; cur++)
		res = ll(res) * (cur % mod) % mod;
	res = ll(res) * inv[n - 1] % mod;
	return res;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(fac[i - 1]) * i % mod;
		inv[i] = getInv(fac[i]);
	}
	scanf("%d %I64d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &f[i]);
	ways = Solve(n, s);
	for (int i = 1; i < 1 << n; i++) {
		int bts = 0;
		ll lft = s;
		for (int j = 0; j < n; j++)
			if (i & 1 << j) {
				bts++;
				lft -= f[j] + 1;
			}
		if (bts % 2) ways = (ways - Solve(n, lft) + mod) % mod;
		else ways = (ways + Solve(n, lft)) % mod;
	}
	printf("%d\n", ways);
	return 0;
}