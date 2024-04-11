#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 998244353;

int fac[Maxn], inv[Maxn];
int res;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	int n; scanf("%d", &n);
	int cur = 1; 
	int mult = toPower(3, n);
	int cont = (mult - 3 + mod) % mod;
	for (int i = 1; i <= n; i++) {
		res = (res + 3ll * ll(cur) % mod * toPower(mult, n - i)) % mod;
		cur = ll(cur) * cont % mod;
	}
	res = ll(res) * 2 % mod;
	for (int i = 1; i <= n; i++) {
		int r = n - i;
		int pw = toPower(3, r);
		int mymult = (toPower(pw, n) - toPower((pw - 1 + mod) % mod, n) + mod) % mod;
		int add = ll(C(n, i)) * 3ll % mod * mymult % mod;
		if (i % 2) res = (res - add + mod) % mod;
		else res = (res + add) % mod;
	}
	printf("%d\n", res);
	return 0;
}