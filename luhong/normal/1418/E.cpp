#include <cstdio>
#include <algorithm>
#define MN 201000
#define mod 998244353

int d[MN], s[MN];
int inv[MN];

int main()
{
	int n, q; scanf("%d%d", &n, &q);
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n + 1; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	std::sort(d + 1, d + n + 1);
	for(int i = 1; i <= n; i++) s[i] = (s[i - 1] + d[i]) % mod;
	for(int i = 1; i <= q; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		int p = std::lower_bound(d + 1, d + n + 1, b) - d;
		int w = n - p + 1;
		if(a >= w + 1) {puts("0"); continue;}
		int s1 = 1ll * (w - a + 1) * inv[w + 1] % mod * s[p - 1] % mod; 
		int s2 = 1ll * (w - a) * inv[w] % mod * (s[n] - s[p - 1] + mod) % mod;
		printf("%d\n", (s1 + s2) % mod);
	}
}