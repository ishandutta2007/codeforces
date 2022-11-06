#include<bits/stdc++.h>
using namespace std;
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
#define re register
long long f[100100],g[100100];
int sz[100100],gg[100100],ins[100100],tot,p[1000100],qq[100100],num;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
}
void dfs(re int a)
{
	re long long x=0,y=0;
	sz[a]=1;
	for(re eg*i=la[a];i;i=i->nx)
	{
		dfs(i->to);
		g[a]+=g[i->to]+1;
		if(g[i->to]-f[i->to]+1>x)x=g[i->to]-f[i->to]+1,y=i->to;
	}
	gg[y]=1;
	f[a]=g[a]-x;
}
void sol1(re int a,re int ta)
{
	ins[++tot]=a;
	for(re eg*i=la[a];i;i=i->nx)
	{
		re int y;
		if(i->nx)y=i->nx->to;
		else y=ta;
		sol1(i->to,y);
		p[++num]=y; 
	}
}
void sol(re int a)
{
	ins[++tot]=a;
	re int ta=0;
	for(re eg*i=la[a];i;i=i->nx)if(!gg[i->to])
	{
		qq[++ta]=i->to;
	}
	for(re eg*i=la[a];i;i=i->nx)if(gg[i->to])
	{
		qq[++ta]=i->to;
	}
	for(re int i=1;i<ta;i++)sol1(qq[i],qq[i+1]),p[++num]=qq[i+1];
	if(ta)sol(qq[ta]);
}
int main()
{
	re int n,x;
	scanf("%d",&n);
	for(re int i=2;i<=n;i++)scanf("%d",&x),addE(x+1,i);
	dfs(1);
	sol(1);
	for(re int i=1;i<=n;i++)printf("%d ",ins[i]-1);puts("");
	printf("%d\n",num);
	for(re int i=1;i<=num;i++)printf("%d ",p[i]-1);
}