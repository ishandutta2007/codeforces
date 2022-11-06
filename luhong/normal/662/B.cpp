#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MN 101000

int h[MN], nxt[2 * MN], to[2 * MN], K = 1;
int col[MN], tmp[MN], cnt = 0, mn = 0;
bool vis[MN]; int c;
int ans = 0, ans2 = 0;
std::vector<int> cur, Ans, Min, Ans2;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void rev(int x)
{
	cnt++; cur.push_back(x);
	for(int i = h[x]; i; i = nxt[i])
		col[i >> 1] ^= 1;
}

void init(int x)
{
	if(!vis[x]) return;
	vis[x] = 0;
	for(int i = h[x]; i; i = nxt[i])
	{
		col[i >> 1] = tmp[i >> 1];
		init(to[i]);
	}
}

void dfs(int x)
{
	vis[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(vis[to[i]])
		{
			if(col[i >> 1] != c) cnt = 1e9;
			continue;
		}
		if(col[i >> 1] != c) rev(to[i]);
	}
	for(int i = h[x]; i; i = nxt[i])
		if(!vis[to[i]]) dfs(to[i]); 
}
 
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; char c[2];
		scanf("%d%d%s", &u, &v, c);
		col[i] = c[0] == 'B';
		ins(u, v); ins(v, u);
	}
	memcpy(tmp, col, sizeof(col));
	for(c = 0; c <= 1; c++)
	{
		memset(vis, 0, sizeof(vis));
		memcpy(col, tmp, sizeof(tmp));
		
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i])
			{
				cur.clear(); cnt = 0; dfs(i); Min = cur; mn = cnt;
				init(i); cur.clear(); cnt = 0; rev(i); dfs(i); if(cnt < mn) Min = cur, mn = cnt;
				
				ans += mn; 
				if(mn >= 1e9) break;
				while(!Min.empty()) Ans.push_back(Min.back()), Min.pop_back();
			}
		}
		if(c == 0) ans2 = ans, Ans2 = Ans, ans = 0, Ans.clear();
		else if(ans2 < ans) ans = ans2, Ans = Ans2;
	}
	
	if(ans >= 1e9) return 0 * puts("-1");
	printf("%d\n", ans);
	while(!Ans.empty()) printf("%d ", Ans.back()), Ans.pop_back();
}