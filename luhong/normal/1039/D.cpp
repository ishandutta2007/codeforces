#include <cstdio>
#include <iostream>
#include <cstring> 

int dp[101000], Ans[101000], dfn[101000], rdfn[101000], fa[101000], d = 0;
int f[101000], g[101000];
int h[101000], nxt[201000], K = 0, to[201000];
int mid, ans = 0, n;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int f)
{
	fa[x] = f; dfn[x] = ++d; rdfn[d] = x;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(to[i] == f) continue;
		dfs(to[i], x);
	}
}

void DP(int x)
{
	for(int j = n; j >= 1; j--)
	{
		int i = rdfn[j];
		if(f[i] + g[i] + 1 >= mid) ans++, dp[i] = 0;
		else dp[i] = f[i] + 1;
		int x = fa[i];
		if(dp[i] > f[x]) g[x] = f[x], f[x] = dp[i]; 
		else g[x] = std::max(dp[i], g[x]);
	}
}

int get_ans()
{
	if(Ans[mid]) ans = Ans[mid];
	else {memset(dp, 0, sizeof(dp)); memset(f, 0, sizeof(dp)); memset(g, 0, sizeof(dp)); DP(1);}
	Ans[mid] = ans;
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
	{
		mid = i, ans = 0;
		int v = get_ans();
		int L = i, R = n + 1;
		while(L < R)
		{
			mid = L + R >> 1, ans = 0;
			if(get_ans() == v) L = mid + 1;
			else R = mid;
		}
		for(int j = i; j < L; j++) Ans[j] = v, printf("%d\n", v);
		i = L - 1; 
	}
	return 0;
}