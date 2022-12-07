#include <bits/stdc++.h>
#define N 200005
#define inf 1000000000
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int tot = 1,n,m;  
int dfsclk,fst[N],pnt[N],bian,e[N][2],blg[N],edg[N],fa[N],len[N],gol,sum[N],ss[N],c[N],ans;
bool bo[N]; int nxt[N],d[N],h[N],cnt,vis[N]; bool ok[N];

void add(int x,int y,int z)
{
	pnt[++ tot] = y; 
	nxt[tot] = fst[x]; 
	len[tot] = z; 
	fst[x] = tot;
}
void dfs(int x,int last)
{
	vis[x] = ++ dfsclk;
	for (int i = fst[x]; i; i = nxt[i]) 
		if (i != (last ^ 1))
		{
			int y = pnt[i];
			if (!vis[y])
				fa[y] = x, edg[y] = i, dfs(y,i);
		}
	for (int i = fst[x]; i; i = nxt[i]) 
		if (i != (last ^ 1))
		{
			int y = pnt[i];
			if (fa[y] != x && vis[x] < vis[y])
			{
				blg[i >> 1] = ++ cnt;
				for (; y != x; y = fa[y])
					blg[edg[y] >> 1] = cnt;
			}
	}
}

bool bfs()
{  
    int l = 0, r = 1; h[1] = 0;  
    memset(d,-1,sizeof(d)); 
    d[0] = 1;  
    while (l < r)
    {  
        int x = h[++ l], p;  
        for (p = fst[x]; p; p = nxt[p]) 
        	if (len[p])
        	{  
        	    int y = pnt[p];  
    	        if (d[y] == -1)
    	        { 
    	        	d[y] = d[x] + 1; 
    	        	h[++ r] = y; 
    	        }  
 	        }  
    }  
    return d[gol] != -1;  
}  
int dfs1(int x,int rst)
{  
    if (x == gol || !rst) return rst; 
    int p,flow = 0;  
    for (p = fst[x]; p; p = nxt[p]) 
    	if (len[p])
    	{  
        	int y = pnt[p]; 
        	if (d[x] + 1 != d[y]) continue;  
        	int tmp = dfs1(y, min(rst, len[p])); 
        	if (!tmp) continue;  
       		flow += tmp; 
       		len[p] -= tmp;  
        	len[p ^ 1] += tmp; 
        	rst -= tmp; if (!rst) break;   
    	}  
    if (!flow) d[x] = -1; 
    return flow;  
}  

void dinic(int x)
{
	while(bfs())
		ans += dfs1(0, 1e9);
}

int main()
{
	n = read();
	m = read();
	int x,y,z;
	for (int i = 1; i <= m; i ++)
	{
		x = read();
		y = read();
		z = read();
		c[i] = z; 
		add(x, y, 0); 
		add(y, x, 0);
		if (!vis[z])
		{ 
			vis[z] = 1; 
			ans ++; 
		}
	}
	memset(vis, 0, sizeof(vis));
	dfs(1, 0);
	memset(fst, 0, sizeof(fst));
	for (int i = 1; i <= m; i ++) 
		if (!blg[i]) ok[c[i]] = 1; 
		else nxt[i] = fst[blg[i]], fst[blg[i]] = i;
	for (int i = 1; i <= cnt; i ++) 
	{
		for (int j = fst[i]; j; j = nxt[j])
		{
			sum[c[j]] ++;
			if (sum[c[j]] == 2 || ok[c[j]]) { bo[i] = 1; break; }
		}
		for (int j = fst[i]; j; j = nxt[j]) sum[c[j]]=0;
		if (!bo[i])
		{
			ans --;
			for (int j = fst[i]; j; j = nxt[j])
			{
				ss[c[j]] ++;
				e[++ bian][0] = i; 
				e[bian][1] = c[j] + cnt;
			}
		} 
		else
		for (int j = fst[i]; j; j = nxt[j])
			if (ss[c[j]] < inf) ss[c[j]] = inf;
		
	}
	memset(fst, 0, sizeof(fst)); 
	tot = 1;
	for (int i = 1; i <= bian; i ++)
		add(e[i][0],e[i][1],1), add(e[i][1],e[i][0],0);
	
	for (int i = 1; i <= cnt; i ++) 
		if (!bo[i])
			add(0, i, 1), add(i,0,0);
	gol = cnt + m + 1;
	for (int i = 1; i <= m; i ++) 
		if (ss[i] > 1)
			add(i + cnt, gol, ss[i] - 1), add(gol, i + cnt, 0);
	while (bfs()) ans += dfs1(0, inf);
	printf("%d\n", ans);
	return 0;
}