#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 5005;

int C[Maxn][Maxn];
int n, k;
int val[Maxn];
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

int Inv(int x)
{
	return toPower(x, mod - 2);
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d %d", &n, &k);
	int cur = 1;
	for (int i = 1; i <= k && i <= n; i++) {
		cur = ll(cur) * Inv(i) % mod * (n - i + 1) % mod;
		val[i] = toPower(i, k);
		for (int j = 1; j < i; j++)
			val[i] = (val[i] - ll(val[j]) * C[i][j] % mod + mod) % mod;
		res = (res + ll(val[i]) * cur % mod * toPower(2, n - i)) % mod;
	}
	printf("%d\n", res);
	return 0;
}