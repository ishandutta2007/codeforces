#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const int mod = 998244353;

int fac[Maxn], inv[Maxn];
int a, b, c;
int res1, res2, res3;

int Inv(int x)
{
	int res = 1;
	int p = mod - 2;
	while (p) {
		if (p & 1) res = ll(res) * x % mod;
		p >>= 1; x = ll(x) * x % mod;
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
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(fac[i - 1]) * i % mod;
		inv[i] = Inv(fac[i]);
	}
	cin >> a >> b >> c;
	for (int i = 0; i <= 5000; i++) {
		if (i <= a && i <= b) 
			res1 = (res1 + ll(C(a, i)) * C(b, i) % mod * fac[i]) % mod;
		if (i <= b && i <= c)
			res2 = (res2 + ll(C(b, i)) * C(c, i) % mod * fac[i]) % mod;
		if (i <= c && i <= a)
			res3 = (res3 + ll(C(c, i)) * C(a, i) % mod * fac[i]) % mod;
	}
	int res = ll(res1) * res2 % mod * res3 % mod;
	printf("%d\n", res);
	return 0;
}