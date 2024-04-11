#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 101000
#define MM 201000
#define mod 1000000007

long long d[64], cnt = 0;
long long w[MN];
int f[MN][64][2];
long long sum[64], cost[2 * MM];
int bl = 0; 
bool vis[MN];
int h[MN], nxt[2 * MM], to[2 * MM], K = 0;

void ins(int u, int v, long long c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

void add(long long x)
{
	for(int i = 61; i >= 0; i--)
	{
		if((x >> i) & 1)
		{
			if(!d[i]) d[i] = x, cnt++;
			x ^= d[i];
			if(!x) return;
		}
	}
}

void dfs(int x, int fa)
{
	vis[x] = 1; bl++;
	for(int i = 0; i <= 61; i++) f[x][i][0] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(!vis[to[i]])
		{
			w[to[i]] = w[x] ^ cost[i];
			dfs(to[i], x);
			for(int j = 0; j <= 61; j++)
			{
				int A = f[to[i]][j][0], B = f[to[i]][j][1];
				if((cost[i] >> j) & 1) std::swap(A, B);
				sum[j] += 1ll * A * f[x][j][1] + 1ll * B * f[x][j][0];
				f[x][j][0] += A; f[x][j][1] += B;
			}
		}
		else add(w[x] ^ w[to[i]] ^ cost[i]);
	}
}

int qpow(int x, int p) {int ans = 1; for(; p; p >>= 1, x = 1ll * x * x % mod) if(p & 1) ans = 1ll * x * ans % mod; return ans;}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b; long long c; scanf("%d%d%lld", &a, &b, &c);
		ins(a, b, c); ins(b, a, c);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		memset(d, 0, sizeof(d)); bl = 0;
		memset(sum, 0, sizeof(sum)); cnt = 0;
		if(!vis[i])
		{
			dfs(i, 0);
			for(int j = 0; j <= 61; j++)
			{
				bool ok = 0;
				if(d[j]) ans = (ans + 1ll * bl * (bl - 1) / 2 % mod * qpow(2, cnt - 1) % mod * ((1ll << j) % mod)) % mod;
				else
				{
					for(int k = 0; k <= 61; k++) ok |= (d[k] >> j) & 1;
					if(ok) ans = (ans + 1ll * bl * (bl - 1) / 2 % mod * qpow(2, cnt - 1) % mod * ((1ll << j) % mod)) % mod;
					else ans = (ans + sum[j] % mod * qpow(2, cnt) % mod % mod * ((1ll << j) % mod)) % mod;
				}
			}
		}
	}
	printf("%lld\n", ans);
}