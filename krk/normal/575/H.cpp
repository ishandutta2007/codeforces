#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 2000005;

int fac[Maxn], inv[Maxn];
int n;
int res;

int Inv(int a, int p = mod - 2)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int C(int n, int k) 
{
	if (k > n || k < 0) return 0;
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
	int leaves = 1;
	for (int i = 0; i <= 2 * n; i++) {
		res = (res + leaves) % mod;
		int sub = 2 * C(i, n) % mod;
		int rem = (leaves - sub + mod) % mod;
		leaves = (ll(rem) * 2 % mod + sub) % mod;
	}
	printf("%d\n", res);
	return 0;
}