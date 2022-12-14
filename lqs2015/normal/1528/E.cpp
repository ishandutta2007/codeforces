#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod = 998244353, iv6 = (mod + 1) / 6;
int n, f[1111111], g[1111111], ans, hu[1111111], hd[1111111];
int main()
{
	scanf("%d", &n);
	f[0] = 2;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (1ll * f[i - 1] * (f[i - 1] + 1) / 2 + 1) % mod;
	}
	g[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		g[i] = 1ll * f[i - 1] * (f[i - 1] + 1) % mod * (f[i - 1] + 2) % mod * iv6 % mod;
	}
	for (int i = n; i >= 1; i--) g[i] = (g[i] - g[i - 1]) % mod;
	ans = (g[n] * 2 - 1) % mod;
	for (int i = 1; i <= n; i++) hu[i] = 1ll * (f[i - 1] - 1) * f[i - 1] / 2 % mod;
	for (int i = n; i >= 1; i--) hu[i] = (hu[i] - hu[i - 1]) % mod;
	for (int i = 1; i <= n; i++) hd[i] = (hd[i - 1] + hu[i]) % mod;
	for (int i = 1; i < n - 1; i++) ans = (1ll * hu[i] * hd[n - 1 - i] + ans) % mod; 
	printf("%d\n", (ans + mod) % mod);
	return Accepted;
}