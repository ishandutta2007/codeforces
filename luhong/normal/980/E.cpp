#include<iostream>
#include<cstdio>
using namespace std;
int st[1000100][22],dep[1010000],fa[1000100];
int h[1001000],nxt[2001000],to[2001000],K=0;
bool used[1001000];
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void dfs(int x,int f,int d)
{
	fa[x]=f;dep[x]=d;
	for(int i=h[x];i;i=nxt[i])
		if(to[i]!=f)dfs(to[i],x,d+1);
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);int u,v;int last=n-k-1;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),ins(u,v),ins(v,u);
	dfs(n,0,1);
	for(int i=1;i<=n;i++)st[i][0]=fa[i];
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			st[j][i]=st[st[j][i-1]][i-1];
		}
	}used[0]=1;used[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(used[i])continue;
		int cur=i;
		for(int j=20;j>=0;j--)
		{
			if(!used[st[cur][j]])cur=st[cur][j];
		}
		if(last>=(dep[i]-dep[cur]+1))
		{
			last-=dep[i]-dep[cur]+1;
			for(int j=i;j!=fa[cur];j=fa[j])
			{
				used[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)if(!used[i])printf("%d ",i);
	return 0;
}