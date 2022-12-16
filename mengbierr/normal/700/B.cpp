#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
struct node
{
	int from;
	int to;
	int next;
}edge[500005];
int tot,head[200005];
int n,m;
int size[500005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int fa[500005];
void dfs(int x)
{
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(fa[x]==edge[i].to) continue;
		fa[edge[i].to]=x;
		dfs(edge[i].to);
		size[x]+=size[edge[i].to];
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();m=read();
	for(int i=1;i<=2*m;i++)
	{
		size[read()]=1;
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1);
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=min(size[i],2*m-size[i]);
	}
	cout<<ans;
}