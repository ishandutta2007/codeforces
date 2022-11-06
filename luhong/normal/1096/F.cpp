#include <cstdio>
#include <algorithm>
 
const int mod = 998244353;
bool used[201000];
int c[201000], a[201000], s[201000];
int n;

void add(int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
int query(int x) {int ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

int qpow(int x, int p)
{
    int ans = 1;
    while(p)
    {
        if(p & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod; p >>= 1;
    }
    return ans;
}

int main()
{
	scanf("%d", &n);
	int tot = 0;
	long long Ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == -1) tot++;
		else used[a[i]] = 1, Ans += query(n) - query(a[i]), add(a[i], 1);
	}
	Ans %= mod;
	int cnt = 1;
	for(int i = 1; i < tot; i++) cnt = 1ll * cnt * i % mod; 
	long long x = 1ll * tot * (tot - 1) / 2 % mod;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!used[i]) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != -1) sum = (sum + s[a[i]]) % mod;
		else ans = (ans + 1ll * sum * cnt % mod) % mod;
	}
	sum = 0;
	for(int i = n; i >= 1; i--)
	{
		if(a[i] != -1) sum = (sum + tot - s[a[i]]) % mod;
		else ans = (ans + 1ll * sum * cnt % mod) % mod;
	}
	for(int i = 1; i <= tot; i++) ans = ans * qpow(i, mod - 2) % mod;
	
	printf("%lld", (ans + Ans + 1ll * x * (mod + 1 >> 1) % mod) % mod);
}