#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
struct Edge
{
	int u,v,w;
}	e[maxn];
int f[maxn],size[maxn],fandui[maxn];
int vis[maxn];
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
int n,m;
void Union(int x,int y)
{
	if (x==0 || y==0)	return;
	x=fa(x),y=fa(y);
	if (x==y)	return;
	if (size[x]>size[y])	swap(x,y);
	f[x]=y,size[y]+=size[x];
	return;
}
int doit(int w)
{
	for (int i=1;i<=n;i++)	f[i]=i,size[i]=1,fandui[i]=0;
	for (int i=1;i<=m;i++)
	if (e[i].w==w)	Union(e[i].u,e[i].v);
	for (int i=1;i<=m;i++)
	if (e[i].w!=w)
	{
		int u=e[i].u,v=e[i].v;
		u=fa(u),v=fa(v);
		if (u==v)	return n+1;
		int qu=fandui[u],qv=fandui[v];
		Union(qu,v),Union(qv,u);
		u=fa(u),v=fa(v);
		fandui[u]=v;
		fandui[v]=u;
	}
	int mjy=0;
	for (int i=1;i<=n;i++)	vis[i]=false;
	for (int i=1;i<=n;i++)
	if (f[i]==i && !vis[i])
	{
		if (fandui[i]==0)	{vis[i]=3;continue;}
		int u=i,v=fandui[i];
		if (size[u]>size[v])	swap(u,v);
		mjy+=size[u];
		vis[u]=1,vis[v]=2;
	}
	return mjy;
}
int main()
{
	read(n),read(m);
	for (int i=1;i<=m;i++)
	{
		read(e[i].u),read(e[i].v);
		char ch=getchar();
		while (ch!='B' && ch!='R')	ch=getchar();
		if (ch=='B')	e[i].w=1;else e[i].w=0;
	}
	int mjy=n+1,zxo=0;
	int mxh=doit(0);
	if (mxh<mjy)	mjy=mxh,zxo=0;
	mxh=doit(1);
	if (mxh<mjy)	mjy=mxh,zxo=1;
	if (mjy==n+1)	printf("-1\n");else
	{
		printf("%d\n",mjy);
		doit(zxo);
		for (int i=1;i<=n;i++)
		if (vis[fa(i)]==1)	printf("%d ",i);
	}
	return 0;
}