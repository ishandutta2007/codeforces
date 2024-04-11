#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int f[200005][3],tot,fa[200005],head[200005],n;
ll ans;
struct node
{
	int from;
	int to;
	int next;
}edge[400005];
void add(int u,int v)
{
	edge[tot].from=u;
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int x)
{
	f[x][0]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)
	{
		if(edge[i].to!=fa[x])
		{
			fa[edge[i].to]=x;
			dfs(edge[i].to);
		}
	}
	//cout<<x<<endl;
	ans+=1LL*f[x][0]*(n-f[x][0]-f[x][1]);
	ans-=1LL*f[x][0]*f[fa[x]][1];
	f[fa[x]][0]+=f[x][1];
	f[fa[x]][1]+=f[x][0];
}
int main()
{
	memset(head,-1,sizeof(head));
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1);
	cout<<ans;
}