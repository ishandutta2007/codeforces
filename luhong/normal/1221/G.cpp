#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 40

typedef long long ll;

int n, m;
int Div = 1;
int col[MN], bl = 0;
ll Ans[MN];
int ok[MN];
bool mp[MN][MN];
bool flag = 1;
int f[1 << 20][2], g[1 << 20][2];

int h[MN], nxt[5010], to[5010], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x)
{
	for(int i = h[x]; i; i = nxt[i])
	{
		if(col[to[i]] == -1)
		{
			col[to[i]] = col[x] ^ 1;
			dfs(to[i]);
		}
		else if(col[to[i]] != col[x] ^ 1) flag = 0;
	}
}

int main()
{
	memset(col, -1, sizeof(col));
	scanf("%d%d", &n, &m);
	if(n & 1) n++, Div = 2;
	int N = n / 2;
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		x--; y--; ins(x, y); ins(y, x);
		mp[x][y] = mp[y][x] = 1;
		if(x > y) std::swap(x, y);
		if(x < N && y >= N) ok[x] |= (1 << (y - N));
	}
	
	for(int i = 0; i < n; i++)
		if(col[i] == -1) col[i] = 0, dfs(i), bl++;
	
	Ans[1] = 1; Ans[2] = flag * (1ll << bl); Ans[4] = 1;
	Ans[1 ^ 4] = 1ll << bl; Ans[1 ^ 2 ^ 4] = 1ll << n;
	if(m == 0) Ans[0] = 1ll << n;
	
	for(int i = 0; i < n; i++)
	{
		bool ok = 0;
		for(int j = 0; j < n; j++)
			if(mp[i][j]) ok = 1;
		if(!ok) Ans[1] *= 2, Ans[4] *= 2;
	}
	
	for(int S = 0; S < (1 << N); S++)
	{
		bool okk[3]; okk[0] = okk[1] = okk[2] = 0;
		for(int i = 0; i < N; i++)
			for(int j = i + 1; j < N; j++)
				if(mp[i][j]) okk[((S >> i) & 1) + ((S >> j) & 1)] = 1;
		if(!okk[2]) f[S][0]++;
		if(!okk[0]) f[S][1]++;
	}
	
	for(int S = 0; S < (1 << N); S++)
	{
		bool okk[3]; okk[0] = okk[1] = okk[2] = 0;
		for(int i = N; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(mp[i][j]) okk[((S >> (i - N)) & 1) + ((S >> (j - N)) & 1)] = 1;
		if(!okk[2]) g[S][0]++;
		if(!okk[0]) g[S][1]++;
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < (1 << N); j++)
		{
			if((j >> i) & 1) g[j][0] += g[j ^ (1 << i)][0];
			if(!((j >> i) & 1)) g[j][1] += g[j ^ (1 << i)][1];
		}
	
	for(int S = 0; S < (1 << N); S++)
	{
		int T = (1 << N) - 1;
		for(int i = 0; i < N; i++)
			if((S >> i) & 1) T &= (ok[i] ^ ((1 << N) - 1));
			
		Ans[1 ^ 2] += f[S][0] * g[T][0];
		
		T = 0;
		for(int i = 0; i < N; i++)
			if(!((S >> i) & 1)) T |= ok[i];
		
		Ans[2 ^ 4] += f[S][1] * g[T][1];
	}
	
	printf("%lld\n", (Ans[1 ^ 2 ^ 4] - Ans[1 ^ 2] - Ans[2 ^ 4] - Ans[1 ^ 4] + Ans[1] + Ans[2] + Ans[4] - Ans[0]) / Div);
}