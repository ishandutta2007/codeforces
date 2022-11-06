#include<iostream>
#include<cstdio>
using namespace std;
int h[301000],nxt[601000],K=0,to[601000];
int siz[301000],fa[301000];
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void dfs1(int x,int f)
{
	siz[x]=1;fa[x]=f;
	for(int i=h[x];i;i=nxt[i])if(to[i]!=f)dfs1(to[i],x),siz[x]+=siz[to[i]];
}
int check(int u,int v)
{
	for(int i=u;i;i=fa[i])if(i==v)return 1;
	for(int i=v;i;i=fa[i])if(i==u)return 2;
	return 0;
}bool OK=0;
void check2(int x,int f,int k)
{
	if(x==k)OK=1;
	for(int i=h[x];i;i=nxt[i])if(to[i]!=f)check2(to[i],x,k);
}
int main()
{
	int n,x,y;scanf("%d%d%d",&n,&x,&y);long long ans=(long long)n*(n-1);
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	dfs1(1,0);
	int o=check(x,y);
	if(o==0)ans-=(long long)siz[x]*siz[y];
	if(o==1)
	{
		for(int i=h[y];i;i=nxt[i])
			if(to[i]!=fa[y])
			{
				OK=0;check2(to[i],y,x);
				if(OK==1){ans-=(long long)(siz[1]-siz[to[i]])*siz[x];break;}
			}
	}
	if(o==2)
	{
		for(int i=h[x];i;i=nxt[i])
			if(to[i]!=fa[x])
			{
				OK=0;check2(to[i],x,y);
				if(OK==1){ans-=(long long)(siz[1]-siz[to[i]])*siz[y];break;}
			}
	}
	printf("%lld",ans);
	return 0;
}