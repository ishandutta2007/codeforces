#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MN 301000

int h[MN], nxt[2 * MN], to[2 * MN], K = 0;
int q[MN], H = 0, T = 0; 
std::vector<int> v1[MN], v2[MN];
int b[MN], d[MN], ans[MN];
int st[MN], top = 0;
int ok[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); d[v]++;
		v1[v].push_back(u);
		v2[u].push_back(v); 
	}
	for(int i = 1; i <= n; i++) if(!d[i]) q[T++] = i;
	while(H < T)
	{
		int u = q[H++]; b[H] = u;
		for(int i = h[u]; i; i = nxt[i])
		{
			if(--d[to[i]] == 0) q[T++] = to[i];
		}
	}
	memset(d, 0, sizeof(d)); int sum = 0; top = 0;
	for(int o = 1; o <= n; o++)
	{
		int i = b[o];
		st[++top] = i; sum++;
		int S = v1[i].size();
		for(int j = 0; j < S; j++)
		{
			if(d[v1[i][j]] == 0) sum--;
			d[v1[i][j]]++;
			if(d[v1[i][j]] == 1) ok[i]++;
			if(d[v1[i][j]] == 2)
			{
				int u = v1[i][j];
				int SS = v2[u].size();
				for(int k = 0; k < SS; k++)
				{
					if(ok[v2[u][k]] && v2[u][k] != i) ok[v2[u][k]]--;
				}
			}
		}
		if(sum <= 2)
		{
			int j = 1;
			for(int k = 1; k <= top; k++)
			{
				if(d[st[k]] == 0) st[j] = st[k], j++;
			}
			top = j - 1;
			if(sum == 1) ans[i] = 1;
			if(sum == 2)
			{
				int u = st[1];
				if(!ok[u]) ans[i] = 2;
			}
		}
	}
	memset(d, 0, sizeof(d)); sum = 0; top = 0; memset(ok, 0, sizeof(ok));
	int Ans = 0;
	for(int o = n; o >= 1; o--)
	{
		int i = b[o];
		st[++top] = i; sum++;
		int S = v2[i].size();
		for(int j = 0; j < S; j++)
		{
			if(d[v2[i][j]] == 0) sum--;
			d[v2[i][j]]++;
			if(d[v2[i][j]] == 1) ok[i]++;
			if(d[v2[i][j]] == 2)
			{
				int u = v2[i][j];
				int SS = v1[u].size();
				for(int k = 0; k < SS; k++)
				{
					if(ok[v1[u][k]] && v1[u][k] != i) ok[v1[u][k]]--;
				}
			}
		}
		if(sum <= 2)
		{
			int j = 1;
			for(int k = 1; k <= top; k++)
			{
				if(d[st[k]] == 0) st[j] = st[k], j++;
			}
			top = j - 1;
			if(sum == 1 && ans[i] != 0) Ans++;
			if(sum == 2 && ans[i] == 1)
			{
				int u = st[1];
				if(!ok[u]) Ans++;
			}
		}
	}
	printf("%d\n", Ans);
	return 0; 
}
//
//0
//semi-important000
//