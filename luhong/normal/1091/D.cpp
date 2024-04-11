#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>
#define mod 998244353

long long fac[1010000], inv[1010000];

long long C(int a, int b) {return fac[a] * inv[b] % mod * inv[a - b] % mod;}

int main()
{
	int n; scanf("%d", &n);
	fac[0] = inv[0] = inv[1] = 1;
	for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
	for(int i = 2; i <= n; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) inv[i] = inv[i] * inv[i - 1] % mod;
	long long Ans = 0; 
	for(int i = 1; i < n; i++) Ans = (Ans + C(n, i) * fac[n - i]) % mod;
	printf("%lld\n", ((n * fac[n] - Ans) % mod + mod) % mod);
}