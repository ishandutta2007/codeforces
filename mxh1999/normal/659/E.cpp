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
int n,m;
struct Edge
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int f[maxn];
int mjy=0;
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
bool bo;
void dfs(int t,int fa)
{
	vis[t]=true;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa)
	{
		if (vis[e[i].v])	bo=false;
		if (!vis[e[i].v])	dfs(e[i].v,t);
	}
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++)	f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y);
		addedge(y,x);
		Union(x,y);
	}
	for (int i=1;i<=n;i++)
	if (f[i]==i)
	{
		bo=true;
		dfs(i,0);
		if (bo)	mjy++;
	}
	cout<<mjy<<endl;
	return 0;
}