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

const int mod = 1000000007;
const int Maxn = 1000005;

int fac[Maxn], inv[Maxn];
int n, k;
int sum[Maxn];
int sol[Maxn];

int Inv(int x)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * x % mod;
		p >>= 1; x = ll(x) * x % mod;
	}
	return res;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(i) * fac[i - 1] % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%d %d", &n, &k);
	sum[1] = 1; sol[1] = 1;
	for (int i = 2; i <= n; i++) {
		sol[i] = sum[i - 1];
		int j = max(0, i - k - 1);
		sol[i] = (sol[i] - sum[j] + mod) % mod;
		sol[i] = ll(sol[i]) * fac[i - 2] % mod;
		sum[i] = (sum[i - 1] + ll(sol[i]) * inv[i - 1]) % mod;
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		res = (res + ll(fac[n - 1]) * inv[n - 1 - i] % mod * sol[n - i]) % mod;
	res = (fac[n] - res + mod) % mod;
	printf("%d\n", res);
	return 0;
}