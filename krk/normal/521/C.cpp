#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
int n, k;
char str[Maxn];
int res;

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(fac[i - 1]) * i % mod;
		inv[i] = toPower(fac[i], mod - 2);
	}
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += str[i] - '0';
	int mult = 1;
	for (int i = n - 1; i >= 0; i--) {
		sum -= str[i] - '0';
		int add = (ll(sum) * C(i - 1, k - 1) + ll(str[i] - '0') * C(i, k)) % mod * ll(mult) % mod;
		res = (res + add) % mod;
		mult = ll(mult) * 10 % mod;
	}
	printf("%d\n", res);
	return 0;
}