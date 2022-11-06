#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
struct eg{int to;eg*nx;}e[4000100],*la[2001000],*la1[2001000],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
inline void addE1(re int a,re int b)
{
	*++cnt=(eg){b,la1[a]};la1[a]=cnt;
	*++cnt=(eg){a,la1[b]};la1[b]=cnt;
}
int low[1001000],dfn[1001000],sta[1001000],nwdfn,ta,cnt1,n;
void dfs(re int a)
{
	re int b;
	low[a]=dfn[a]=++nwdfn;
	sta[++ta]=a;
	for(re eg*i=la[a];i;i=i->nx)
	{
		b=i->to;
		if(!dfn[b])
		{
			dfs(b);
			low[a]=min(low[b],low[a]);
			if(dfn[a]<=low[b])
			{
				cnt1++;
				for(;sta[ta]!=b;ta--)addE1(sta[ta],cnt1);
				addE1(b,cnt1);ta--;
				addE1(a,cnt1);
			}
		}
		else low[a]=min(dfn[b],low[a]);
	}
}
int a,b,nk;
int dfs1(re int x,re int fa)
{
	re int sz=(x<=n);
	for(re eg*i=la1[x];i;i=i->nx)if(i->to!=fa)
	{
		sz+=dfs1(i->to,x);
	}
	if(x==b)nk=sz-1;
	return sz;
}
int main()
{
	re int t,m,x,y;
	scanf("%d",&t);
	for(;t--;)
	{
		cnt=e;ta=0;nwdfn=0;
		scanf("%d%d%d%d",&n,&m,&a,&b);cnt1=n;
		for(re int i=1;i<=m;i++)scanf("%d%d",&x,&y),addE(x,y);
		dfs(1);nk=0;
		dfs1(a,0);x=nk;nk=0;
		swap(a,b);
		dfs1(a,0);
		printf("%lld\n",(long long)x*nk);
		for(re int i=1;i<=cnt1;i++)la[i]=la1[i]=0,dfn[i]=0;
	}
}