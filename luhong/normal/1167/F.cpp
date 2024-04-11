#include <cstdio>
#include <iostream> 
#include <algorithm>
#define MN 501000
#define mod 1000000007

typedef long long ll;
int c1[MN], c2[MN];
int n, b[MN], a[MN]; 

void add(int *c, int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] = (c[i] + v) % mod;}
int query(int *c, int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans = (ans + c[i]) % mod; return ans;}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
	std::sort(b + 1, b + n + 1); int N = std::unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= n; i++) add(c2, std::lower_bound(b + 1, b + n + 1, a[i]) - b, 1ll * a[i] * (n - i + 1) % mod); 
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
		
		ans = (ans + 1ll * i * (query(c2, n) - query(c2, x - 1) + mod)) % mod;
		add(c2, x, (-1ll * a[i] * (n - i + 1) % mod + mod) % mod);
		
		ans = (ans + 1ll * (n - i + 1) * (query(c1, n) - query(c1, x - 1) + mod)) % mod;
		add(c1, x, 1ll * a[i] * i % mod);
	}
	printf("%lld\n", ans); return 0;
}