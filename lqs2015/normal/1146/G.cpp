#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int inf=1e9;
int head[222222],to[222222],cap[222222],dist[222222],nxt[222222],cur[222222];
int n,m,s,t,cnt,x,y,z,h,ans,l,r,c;
void addedge(int s,int t,int cp)
{
    cnt++;
    nxt[cnt]=head[s];head[s]=cnt;
    to[cnt]=t;cap[cnt]=cp;
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
        res+=dfs(s,1e9);
    }
    return res;
}
int get(int x,int y)
{
	return (x-1)*h+y;
}
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	s=n*h+m+1;t=s+1;cnt=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=h;j++)
		{
			ans+=(j*2-1);
			addedge(s,get(i,j),j*2-1);
			addedge(get(i,j),s,0);
		}
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&l,&r,&x,&c);
		addedge(n*h+i,t,c);
		addedge(t,n*h+i,0);
		for (int j=l;j<=r;j++)
		{
			for (int k=x+1;k<=h;k++)
			{
				addedge(get(j,k),n*h+i,inf);
				addedge(n*h+i,get(j,k),0);
			}
		}
	}
	printf("%d\n",ans-dinic());
	return Accepted;
}