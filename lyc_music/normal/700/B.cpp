#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define Min(x,y)((x)<(y)?x:y)
#define For(i,x,y)for(i=x;i<=(y);i++)
#define int long long
struct node
{
	int next,to;
}e[400005];
int head[N],siz[N],g,tot,n,k;
inline void add(int u,int v)
{
	e[++g].to=v;
	e[g].next=head[u];
	head[u]=g;
}
void dfs(int u,int fa)
{
	int i,v;
	for(i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	tot+=Min(siz[u],k-siz[u]);
}
int read()
{
	int A;
	bool K;
	char C;
	C=A=K=0;
	while(C<'0'||C>'9')K|=C=='-',C=getchar();
	while(C>'/'&&C<':')A=(A<<3)+(A<<1)+(C^48),C=getchar();
	return(K?-A:A);
}
signed main()
{
	int i,u,v;
	n=read(),k=read()<<1;
	For(i,1,k)siz[read()]=1;
	For(i,1,n-1)
	{
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	cout<<tot;
	return 0;
}