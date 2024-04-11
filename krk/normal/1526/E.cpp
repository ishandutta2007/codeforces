#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500000;
const int mod = 998244353;

int fac[Maxn], ifac[Maxn];
int n, k;
int a[Maxn];
int ipos[Maxn];

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
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ipos[a[i]] = i;
	}
	ipos[n] = -1;
	int v = 0;
	for (int i = 0; i + 1 < n; i++)
		if (ipos[a[i] + 1] > ipos[a[i + 1] + 1])
			v++;
	printf("%d\n", C(k - 1 - v + n, n));
    return 0;
}