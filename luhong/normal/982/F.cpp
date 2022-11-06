#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 101000
#define MM 501000

int h[MN], nxt[MM], to[MM], K = 0;
bool vis[MN];
int Min[MN], Max[MN], id[MN], r[MN], len = 0;
int b[MN], o = 0;
int st[MN], top = 0; bool inq[MN];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(id[to[i]])
		{
			Min[x] = std::min(Min[x], id[to[i]]);
			Max[x] = std::max(Max[x], id[to[i]]); 
		}
		else
		{
			dfs(to[i]);
			Min[x] = std::min(Min[x], Min[to[i]]);
			Max[x] = std::max(Max[x], Max[to[i]]);
		}
	}
}

void dfs2(int x)
{
	vis[x] = 1; st[++top] = x; inq[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(len) return;
		if(!vis[to[i]]) dfs2(to[i]);
		else if(inq[to[i]])
		{
			do {
				++len; r[len] = st[top]; 
			} while(st[top--] != to[i]);
			std::reverse(r + 1, r + len + 1);
			for(int j = 1; j <= len; j++) id[r[j]] = j;
			return;
		}
	}
	if(len) return;
	inq[st[top--]] = 0;
}

void dfs3(int x, bool &ok)
{
	vis[x] = 1; inq[x] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(ok) return;
		if(!vis[to[i]]) dfs3(to[i], ok);
		else if(inq[to[i]]) {ok = 1; return;}
	}
	if(ok) return;
	inq[x] = 0;
}

int main()
{
	memset(Min, 0x3f, sizeof(Min));
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v);
	}
	for(int i = 1; i <= n; i++) 
		if(!vis[i]) 
		{
			dfs2(i);
			if(len) break; 
		}
		
	memset(inq, 0, sizeof(inq)); memset(vis, 0, sizeof(vis)); bool ok = 0;
	for(int i = 1; i <= len; i++) vis[r[i]] = 1;
	for(int i = 1; i <= n; i++)
		if(!vis[i]) 
		{
			dfs3(i, ok);
			if(ok) break; 
		}
	if(ok) return 0 * puts("-1");
	
	memset(vis, 0, sizeof(vis)); int st; 
	for(int i = 1; i <= len; i++)
	{
		dfs(r[i]); 
		if(Min[r[i]] <= i) {st = i; break;}
	}
	for(int i = st; i <= len; i++) b[++o] = r[i], id[r[i]] = o;
	for(int i = 1; i < st; i++) b[++o] = r[i], id[r[i]] = o;
	memcpy(r, b, sizeof(b));
	memset(Min, 0x3f, sizeof(Min)); memset(Max, 0, sizeof(Max));	
	
	memset(inq, 0, sizeof(inq)); memset(vis, 0, sizeof(vis)); ok = 0;
	vis[r[1]] = 1; 
	for(int i = 1; i <= n; i++)
		if(!vis[i]) 
		{
			dfs3(i, ok);
			if(ok) break; 
		}
	if(!ok) return 0 * printf("%d\n", r[1]); 
	
	memset(vis, 0, sizeof(vis));
	int now = 1;
	for(int i = 1; i <= len; i++)
	{
		if(now < i) return 0 * printf("%d\n", r[i]);
		dfs(r[i]);
		if(Min[r[i]] <= i) return 0 * puts("-1");
		now = std::max(now, Max[r[i]] - 1); 
	}
}