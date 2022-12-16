#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
struct node
{
	int from;
	int to;
	int next;
}edge[200005];
int fa[100005],n,m,a[100005];
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int head[100005],tot;
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=f)
		dfs(edge[i].to,x);
	}
}
int query(int x)
{
	int now=fa[x];
	while(now)
	{
		if(gcd(a[now],a[x])!=1) return now;
		now=fa[now];
	}
	return -1;
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==2)
		{
			int x=read(),y=read();
			a[x]=y;
		}
		else
		{
			int x=read();
			printf("%d\n",query(x));
		}
		
	}
}