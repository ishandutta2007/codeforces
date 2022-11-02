//mjy.. good luck ..
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

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

#define maxn 2510
int a[maxn][maxn];
int c[maxn][maxn];
int n,m;
int f[maxn];
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
struct Edge
{
	int v,cost,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,int cost)
{
	e[++tot].v=y;e[tot].cost=cost;e[tot].next=g[x];g[x]=tot;
}
struct Edge2
{
	int x,y,num;
}	b[maxn*maxn];
int cnt;

bool cmp(Edge2 a,Edge2 b)
{
	return a.num<b.num;
}
void dfs(int from,int t,int fa)
{
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa)
	{
		c[from][e[i].v]=max(c[from][t],e[i].cost);
		dfs(from,e[i].v,t);
	}
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)	read(a[i][j]);
	for (int i=1;i<=n;i++)
	if (a[i][i]!=0)	{printf("NOT MAGIC\n");return 0;}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			b[++cnt].x=i;b[cnt].y=j;b[cnt].num=a[i][j];
			if (a[i][j]!=a[j][i])	{printf("NOT MAGIC\n");return 0;}
		}
	sort(b+1,b+cnt+1,cmp);
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=cnt;i++)
	{
		int u=fa(b[i].x),v=fa(b[i].y);
		if (u!=v)	addedge(b[i].x,b[i].y,b[i].num),addedge(b[i].y,b[i].x,b[i].num),f[u]=v;
	}
	for (int i=1;i<=n;i++)	dfs(i,i,0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[i][j]>c[i][j])	{printf("NOT MAGIC\n");return 0;}
	printf("MAGIC\n");
	return 0;
}