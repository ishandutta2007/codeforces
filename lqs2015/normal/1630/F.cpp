#include<bits/stdc++.h>
using namespace std;
int head[222222],to[11111111],cap[11111111],dist[222222],nxt[11111111],cur[222222];
int n,m,s,t,cnt,x,y,z;
int test, a[55555], id[55555];
void addedge(int s,int t,int cp)
{
    cnt++;
    nxt[cnt]=head[s];head[s]=cnt;
    to[cnt]=t;cap[cnt]=cp;
}
void add(int x, int y)
{
	addedge(x, (n << 1) + y, 1);
	addedge((n << 1) + y, x, 0);
	addedge(n + x, (n << 1) + n + y, 1);
	addedge((n << 1) + n + y, n + x, 0);
}
void clear()
{
	for (int i = 1; i <= t; i++) head[i] = 0;
	for (int i = 1; i <= cnt; i++) nxt[i] = 0;
	cnt = 1;
}
void bfs()
{
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for (int i=head[x];i;i=nxt[i])
        {
            if (!cap[i]) continue;
            if (!~dist[to[i]])
            {
                dist[to[i]]=dist[x]+1;
                q.push(to[i]);
            }
        }
    }
}
int dfs(int i,int f)
{
    if (i==t) return f;
    int tmp=f;
    for (int &j=cur[i];j;j=nxt[j])
    {
        if (!cap[j] || dist[to[j]]!=dist[i]+1) continue;
        int d=dfs(to[j],min(cap[j],tmp));
        if (d)
        {
            cap[j]-=d;
            cap[j^1]+=d;
            tmp-=d;
            if (!tmp) break;
        }
        else dist[to[j]]=0;
    }
    return f-tmp;
}
int dinic()
{
    int res=0;
    while(1)
    {
		for (int i=1;i<=t;i++) cur[i]=head[i];
        bfs();
        if (!~dist[t]) break;
        res+=dfs(s,2e9);
    }
    return res;
}
int main()
{
    scanf("%d", &test);
    memset(id, -1, sizeof(id));
    while(test--)
    {
    	scanf("%d", &n);
    	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    	s = 4 * n + 1; t = s + 1;
    	clear();
    	for (int i = 1; i <= n; i++) id[a[i]] = i;
    	for (int i = 1; i <= n; i++)
    	{
    		x = sqrt(a[i]);
    		for (int j = 1; j <= x; j++)
    		{
    			if (a[i] % j == 0)
    			{
    				if (j != a[i] / j) 
    				{
    					if (~id[j] && j != a[i]) add(i, id[j]);
    					if (~id[a[i] / j] && j != 1) add(i, id[a[i] / j]);
					}
					else 
					{
						if (~id[j] && j != a[i]) add(i, id[j]);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) 
		{
			addedge(i, (n << 1) + n + i, 1);
			addedge((n << 1) + n + i, i, 0);
		}
		for (int i = 1; i <= (n << 1); i++)
		{
			addedge(s, i, 1);
			addedge(i, s, 0);
			addedge((n << 1) + i, t, 1);
			addedge(t, (n << 1) + i, 0);
		}
		printf("%d\n", dinic() - n);
		for (int i = 1; i <= n; i++) id[a[i]] = -1;
	}
    return 0;
}