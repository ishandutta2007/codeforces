#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int mod = 1000000007;

vector <int> dv[Maxn];
int val[Maxn];
int fac[Maxn], inv[Maxn];
int n, k, q;
int cnt[Maxn];
int res;

int Inv(int a)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int C(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return ll(fac[n]) * inv[k] % mod * inv[n - k] % mod;
}

void Update(int x)
{
	for (int i = 0; i < dv[x].size(); i++) {
		int u = dv[x][i];
		res = (res - ll(val[u]) * C(cnt[u], k) % mod + mod) % mod;
		res = (res + ll(val[u]) * C(++cnt[u], k)) % mod;
	}
}

int main()
{
	for (int i = 1; i < Maxn; i++) {
		for (int j = i; j < Maxn; j += i)
			dv[j].push_back(i);
		val[i] = i;
		for (int j = 0; j + 1 < dv[i].size(); j++)
			val[i] = (val[i] - val[dv[i][j]] + mod) % mod;
	}
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d %d %d", &n, &k, &q);
	while (n--) {
		int a; scanf("%d", &a);
		Update(a);
	}
	while (q--) {
		int a; scanf("%d", &a);
		Update(a);
		printf("%d\n", res);
	}
	return 0;
}