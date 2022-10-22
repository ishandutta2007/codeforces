#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n;
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
	scanf("%d", &n);
	for (int r = 1; r < n; r += 2)
		res = (res + ll(C(r + 1, n - r - 1)) * fac[r]) % mod;
	res = ll(res) * 2 % mod * n % mod;
	printf("%d\n", res);
    return 0;
}