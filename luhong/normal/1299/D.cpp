#include <iostream>
#include <cstring>
#include <cstdio>
#define MN 101000
#define mod 1000000007

struct xxx{
	int d[6];
};
int n, m;
int id[1 << 15], tot = 0;
xxx rid[375];
int t[375][375];
int s[MN]; int dfn[MN], D = 0; bool ok[MN]; int w[MN];
int h[MN], nxt[2 * MN], to[2 * MN], cost[2 * MN], K = 0;
int A[MN], B[MN], C[MN];
int a[MN], b[MN], c[MN];
int f[MN][375];

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}
int inc(int a, int b) {return (a += b) >= mod ? a - mod : a;}

void ins(xxx &a, int x)
{
	for(int i = 4; i >= 0; i--)
	{
		if((x >> i) & 1)
		{
			if(a.d[i]) x ^= a.d[i];
			else {a.d[i] = x; return;} 
		}
	}
	a.d[5] = 1;
}

xxx mul(xxx a, xxx b)
{
	b.d[5] |= a.d[5];
	for(int i = 0; i <= 4; i++)
		if(a.d[i]) ins(b, a.d[i]);
	return b;
}

xxx trans(xxx a)
{
	for(int i = 4; i >= 0; i--)
		if(a.d[i])
			for(int j = 4; j > i; j--)
				if((a.d[j] ^ a.d[i]) < a.d[j])
					a.d[j] ^= a.d[i];
	return a;
}

int hash(xxx a)
{
	int s = 0, sum = 0;
	for(int i = 0; i <= 4; i++, s += i)
		sum += a.d[i] << s;
	return sum;
}

void Find(xxx now, int T)
{
	if(T == 5)
	{
		now = trans(now);
		int s = hash(now);
		if(!id[s]) id[s] = ++tot, rid[tot] = now;
		return;
	}
	now.d[T] = 0; Find(now, T + 1);
	for(int i = 1 << T; i < (1 << T + 1); i++) now.d[T] = i, Find(now, T + 1);
}

void dfs(int x, int fa, xxx &now)
{
	dfn[x] = ++D;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == 1 || to[i] == fa) continue;
		if(!dfn[to[i]]) s[to[i]] = s[x] ^ cost[i], dfs(to[i], x, now);
		else if(dfn[to[i]] < dfn[x]) ins(now, s[x] ^ s[to[i]] ^ cost[i]);
	}
}

int main()
{
	xxx o; o.d[5] = 0; Find(o, 0);
	for(int i = 1; i <= tot; i++)
		for(int j = 1; j <= tot; j++)
		{
			xxx now = trans(mul(rid[i], rid[j]));
			if(now.d[5] == 1) t[i][j] = -1;
			else t[i][j] = id[hash(now)];
		}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		ins(A[i], B[i], C[i]);
		ins(B[i], A[i], C[i]);
	}
	for(int i = h[1]; i; i = nxt[i]) ok[to[i]] = 1, w[to[i]] = cost[i];
	int tt = 0;
	for(int i = 1; i <= m; i++)
	{
		if(ok[A[i]] && ok[B[i]])
		{
			++tt; 
			a[tt] = A[i]; 
			b[tt] = B[i]; 
			c[tt] = C[i] ^ w[A[i]] ^ w[B[i]];
			ok[A[i]] = ok[B[i]] = 0;
		}
	}
	for(int i = 1; i <= n; i++) if(ok[i]) a[++tt] = i;
	f[0][id[0]] = 1; 
	for(int i = 1; i <= tt; i++)
	{
		xxx now; memset(now.d, 0, sizeof(now.d));
		dfs(a[i], 0, now);
		now = trans(now);
		int k = id[hash(now)];
		for(int j = 1; j <= 374; j++)
		{
			if(!f[i - 1][j]) continue;
			f[i][j] = inc(f[i][j], f[i - 1][j]); 
			int u = t[k][j];
			if(!now.d[5] && u != -1) 
			{
				f[i][u] = inc(f[i][u], f[i - 1][j]);
				if(b[i])
				{
					f[i][u] = inc(f[i][u], f[i - 1][j]);
					xxx g; memset(g.d, 0, sizeof(g.d));
					ins(g, c[i]);
					int v = id[hash(g)];
					if(!g.d[5] && t[u][v] != -1)
						f[i][t[u][v]] = inc(f[i][t[u][v]], f[i - 1][j]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 374; i++) ans = inc(ans, f[tt][i]);
	printf("%d\n", ans);
}