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

const int Maxn = 500005;
const int mod = 1000000007;

int fac[Maxn], inv[Maxn];
char str[Maxn];
int slen;
int L[Maxn], R;
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

int Get(int k, int n)
{
	if (k <= 0) return 0;
	return C(n + k - 1, k - 1);
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fac[i] = ll(fac[i - 1]) * i % mod;
		inv[i] = Inv(fac[i]);
	}
	scanf("%s", str); slen = strlen(str);
	int cur = 0;
	for (int i = 0; i < slen; i++) {
		cur += str[i] == '(';
		L[i] = cur;
	}
	R = 1;
	for (int i = slen - 1; i >= 1; i--)
		if (str[i] == ')' && L[i - 1] > 0) {
			R++;
			int got = (Get(R, L[i - 1]) - Get(R - 1, L[i - 1]) + mod) % mod;
			res = (res + got) % mod;
		}
	printf("%d\n", res);
	return 0;
}