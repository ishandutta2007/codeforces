#include <cstdio>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int fact[Maxn], inv[Maxn];
int n, m, g;
int res;

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * ll(a) % ll(mod);
		p >>= 1; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

void getOne(int n, int m);

void getNil(int n, int m)
{
	if (n == 1 && m == 0) res = (res + 1) % mod;
	if (m >= 1 && n + m > 1) res = (res + ll(fact[n + m - 1]) * ll(inv[n]) % ll(mod) * ll(inv[m - 1]) % ll(mod)) % mod;
	if (n >= 1 && n + m > 1) getOne(n - 1, m);
}

void getOne(int n, int m)
{
	if (n == 0 && m == 1) res = (res + 1) % mod;
	if (n >= 1 && n + m > 1) getNil(n - 1, m);
}

int main()
{
	fact[0] = 1; inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fact[i] = ll(fact[i - 1]) * ll(i) % ll(mod);
		inv[i] = Inv(fact[i]);
	}
	scanf("%d %d %d", &n, &m, &g);
	if (g == 0) getNil(n, m);
	else getOne(n, m);
	printf("%d\n", res);
	return 0;
}