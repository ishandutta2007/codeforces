#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,a,b;
long long f[50005][505],ans;
struct node
{
	int from;
	int to;
	int next;
}edge[100005];
int head[50005],tot;
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
void dfs(int x,int p)
{
	f[x][0]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==p)
		continue;
		dfs(y,x);
		for(int j=1;j<=k;j++)
		f[x][j]+=f[y][j-1];
	}
}
void dfs2(int x,int p)
{
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==p)
		continue;
		for(int j=k;j;j--)
		{
			f[y][j]+=f[x][j-1];
			if(j>1)
			f[y][j]-=f[y][j-2];
		}
		dfs2(y,x);
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		a=read(),b=read();
		add(a,b);
		add(b,a);
	}
	dfs(1,-1);
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
	ans+=f[i][k];
	cout<<ans/2LL;
}