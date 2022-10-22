#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int fac[Maxn], ifac[Maxn];
int T;
int n, k;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		ifac[i] = Inv(fac[i]);
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k); k--;
		int res = 0;
		for (int i = 1; i <= n && (i - 1) * k <= n; i++)
			res = (res + ll(C(n - (i - 1) * k, i)) * fac[i] % mod * fac[n - i]) % mod;
		res = ll(res) * ifac[n] % mod;
		res = (res + 1) % mod;
		printf("%d\n", res);
	}
    return 0;
}