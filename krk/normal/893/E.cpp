#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;
const int mod = 1000000007;

int pw2[Maxn];
int fac[Maxn], inv[Maxn];
int mx[Maxn];
int q;

int Inv(int a)
{
	int res = 1;
	int p = mod - 2;
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

int main()
{
	pw2[0] = fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		pw2[i] = 2ll * pw2[i - 1] % mod;
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
		for (int j = i; j < Maxn; j += i) mx[j] = i;
	scanf("%d", &q);
	while (q--) {
		int x, y; scanf("%d %d", &x, &y);
		int res = pw2[y - 1];
		while (x > 1) {
			int cur = mx[x];
			int cnt = 0;
			while (x % cur == 0) { x /= cur; cnt++; }
			res = ll(res) * C(cnt + y - 1, y - 1) % mod;
		}
		printf("%d\n", res);
	}
	return 0;
}