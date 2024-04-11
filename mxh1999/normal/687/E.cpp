#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
#define maxn 5010
struct Edge
{
	int v,next;
}	e[maxn];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int b[maxn][maxn];
int cir[maxn];
int que[maxn];
int n,m,mjy;
void bfs(int t)
{
	for (int i=1;i<=n;i++)	b[t][i]=n+1;
	cir[t]=n+1;
	b[t][t]=0;
	int l=1,r=1;
	que[r]=t;
	while (l<=r)
	{
		int u=que[l++];
		for (int i=g[u];i;i=e[i].next)
		{
			if (e[i].v==t)	cir[t]=min(cir[t],b[t][u]+1);
			if (b[t][e[i].v]>b[t][u]+1)
			{
				b[t][e[i].v]=b[t][u]+1;
				que[++r]=e[i].v;
			}
		}
	}
}
int f[maxn];
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
void Union(int x,int y)
{
	x=fa(x),y=fa(y);
	f[x]=y;
}
bool vis[maxn];
int main()
{
	read(n),read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y);
	}
	for (int i=1;i<=n;i++)	bfs(i);
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		if (b[i][j]<=n && b[j][i]<=n)	Union(i,j);
	for (int i=1;i<=n;i++)
		for (int j=g[i];j;j=e[j].next)
		if (fa(i)!=fa(e[j].v))	vis[fa(i)]=true;
	for (int i=1;i<=n;i++)
	if (fa(i)==i)
	{
		if (vis[i])
		{
			for (int j=1;j<=n;j++)
			if (fa(j)==i)	mjy++;
		}	else
		{
			int mxh=0;
			int minx=n+1;
			for (int j=1;j<=n;j++)	
			if (fa(j)==i)
			{
				mxh++;
				if (cir[j]<minx)	minx=cir[j];
			}
			if (mxh==1)	mjy+=1;else	mjy+=minx*999+1+mxh-minx;
		}
	}
	printf("%d\n",mjy);
	return 0;
}