#include <cstdio>
#include <cstring>
#include <iostream>
#define mod 1000000007
#define MN 101000

int f[MN][2][2]; //0/11/ 
int id, t;
int g[2];
int u[MN], v[MN], tot = 0, d[MN];
int cnt0[MN], cnt1[MN];
bool vis[MN];
int h[MN], nxt[2 * MN], to[2 * MN], K = 1;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int Abs(int x) {return x > 0 ? x : -x;}

void rw(int &a, int b) {a = (a + b) % mod;}

void dfs(int x, int fa, int st)
{
	vis[x] = 1;
	memset(f[x], 0, sizeof(f[x]));
	bool ok = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(x != st && i / 2 == id)
		{
			for(int j = 0; j <= 1; j++)
			{
				if((t ^ (v[id] < 0)) || (j ^ (u[id] < 0))) f[x][j][1]++;
				else f[x][j][0]++;
			}
			ok = 1;
		}
		else if(i / 2 != fa)
		{
			dfs(to[i], i / 2, st);
			if(Abs(u[i / 2]) != x) std::swap(u[i / 2], v[i / 2]);
			for(int j = 0; j <= 1; j++)
				for(int k = 0; k <= 1; k++)
				{
					if((j ^ (u[i / 2] < 0)) || (k ^ (v[i / 2] < 0))) rw(f[x][j][0], f[to[i]][k][1]), rw(f[x][j][1], f[to[i]][k][0]);
					else rw(f[x][j][0], f[to[i]][k][0]), rw(f[x][j][1], f[to[i]][k][1]);
				}
			ok = 1;
		}
	}
	if(!ok) f[x][0][0]++, f[x][1][0]++;
	if(cnt0[x] == 1) std::swap(f[x][0][0], f[x][0][1]);
	if(cnt1[x] == 1) std::swap(f[x][1][0], f[x][1][1]);
}

int flag = 0; bool vis2[MN];
void dfs2(int x, int fa)
{
	if(vis2[x]) return;
	if(!vis2[x]) vis2[x] = 1;
	bool ok = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == fa) continue;
		dfs2(to[i], x); ok = 1;
	}
	if(!ok) flag = x;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int sum = 1;
	for(int i = 1; i <= n; i++)
	{
		int k; scanf("%d", &k);
		if(k == 1)
		{
			int v; scanf("%d", &v);
			if(v < 0) cnt0[-v]++;
			else cnt1[v]++;
		}
		else
		{
			int a, b; scanf("%d%d", &a, &b);
			if(Abs(a) == Abs(b))
			{
				if(a != b) sum ^= 1;
				else if(a < 0) cnt0[-a]++;
				else cnt1[a]++;
			}
			else
			{
				ins(Abs(a), Abs(b));
				ins(Abs(b), Abs(a));
				d[Abs(a)]++; d[Abs(b)]++;
				++tot; u[tot] = a; v[tot] = b;
			}
		}
	}
	g[0] = 1;
	for(int x = 1; x <= m; x++)
	{
		if(!vis[x])
		{
			int y = x; flag = 0;
			dfs2(x, 0);
			if(flag) x = flag;
			
			if(d[x] == 2)
			{
				int i = h[x]; 
				if(Abs(u[i / 2]) == x) std::swap(u[i / 2], v[i / 2]);
				
				id = i / 2; 
				int s0 = 0, s1 = 0;
				for(t = 0; t <= 1; t++)
				{
					dfs(x, i / 2, x);
					s0 += f[x][t][0]; s1 += f[x][t][1];
				}
				int o[2]; o[0] = (1ll * g[0] * s0 + 1ll * g[1] * s1) % mod;
				o[1] = (1ll * g[0] * s1 + 1ll * g[1] * s0) % mod;
				g[0] = o[0]; g[1] = o[1];
			}
			else
			{
				id = 0; dfs(x, 0, x);
				int o[2]; o[0] = (1ll * g[0] * (f[x][0][0] + f[x][1][0]) + 1ll * g[1] * (f[x][0][1] + f[x][1][1])) % mod;
				o[1] = (1ll * g[0] * (f[x][0][1] + f[x][1][1]) + 1ll * g[1] * (f[x][0][0] + f[x][1][0])) % mod;
				g[0] = o[0]; g[1] = o[1];
			}
			
			x = y;
		}
	}
	printf("%d\n", g[sum]);
}