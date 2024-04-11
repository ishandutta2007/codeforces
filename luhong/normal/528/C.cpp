#include <iostream>
#include <cstdio>
#define MN 401000

int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
bool used[MN];
int u[MN], v[MN], d[MN];
int st[MN], top = 0;
int x[MN], y[MN], tot = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x) 
{
	int &i = h[x]; 
	while(1)
	{
		while(i && used[i / 2]) i = nxt[i];
		if(!i)
		{
			if(!top) return;
			int j = st[top--];
			++tot; ::x[tot] = u[j]; y[tot] = v[j];
			if(y[tot] != x) std::swap(::x[tot], y[tot]); 
			return;
		}
		used[i / 2] = 1; st[++top] = i / 2;
		dfs(to[i]);
	}
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		ins(u[i], v[i]); ins(v[i], u[i]);
		d[u[i]]++; d[v[i]]++;
	}
	int lst = 0;
	for(int i = 1; i <= n; i++)
	{
		if(d[i] & 1)
		{
			if(lst) 
			{
				m++; u[m] = lst; v[m] = i;
				ins(u[m], v[m]); ins(v[m], u[m]);
				lst = 0;
			}
			else lst = i;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int o = tot; dfs(i); 
		if((tot - o) & 1)
		{
			++tot; x[tot] = i; y[tot] = i;
		}
		for(int j = o + 1; j <= tot; j++)
			if((j - o) & 1) {std::swap(x[j], y[j]);}
	}
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++) printf("%d %d\n", x[i], y[i]);
}