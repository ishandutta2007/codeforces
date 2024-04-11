#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct bbian
{
	int u,v;
	bool ts;
}b[800004];
vector<int>v[200005];
int fa[200005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int cf[200005];
int dfn[200005],siz[200005],cnt;
int bf[200005][20],dep[200005];
void dfs(int x,int f)
{
	bf[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=19;i++)bf[x][i]=bf[bf[x][i-1]][i-1];
	dfn[x]=++cnt;
	siz[x]=1;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]==f)continue;
		dfs(v[x][i],x);
		siz[x]+=siz[v[x][i]];
	}
}
int findfx(int x,int y)
{
	if(dfn[y]<dfn[x]||dfn[y]>=dfn[x]+siz[x])return bf[x][0];
	for(int i=19;i>=0;i--)
	{
		if(dep[bf[y][i]]>dep[x])y=bf[y][i];
	}
	return y;
}
signed main()
{
	int n,m,x,y;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		b[i].u=x;
		b[i].v=y;
		b[i].ts=false;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=findf(b[i].u);
		y=findf(b[i].v);
		if(x==y)continue;
		b[i].ts=true;
		fa[x]=y;
		v[b[i].u].push_back(b[i].v);
		v[b[i].v].push_back(b[i].u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		if(b[i].ts)continue;
		cf[1]++;
		x=findfx(b[i].u,b[i].v);
		if(x==bf[b[i].u][0])
		{
			cf[dfn[b[i].u]]--;
			cf[dfn[b[i].u]+siz[b[i].u]]++;
		}
		else
		{
			cf[1]--;
			cf[dfn[x]]++;
			cf[dfn[x]+siz[x]]--;
		}
		x=findfx(b[i].v,b[i].u);
		if(x==bf[b[i].v][0])
		{
			cf[dfn[b[i].v]]--;
			cf[dfn[b[i].v]+siz[b[i].v]]++;
		}
		else
		{
			cf[1]--;
			cf[dfn[x]]++;
			cf[dfn[x]+siz[x]]--;
		}
	}
	for(int i=2;i<=n;i++)cf[i]+=cf[i-1];
	for(int i=1;i<=n;i++)
	{
		if(cf[dfn[i]]>0)printf("0");
		else printf("1");
	}
	printf("\n");
	return 0;
}