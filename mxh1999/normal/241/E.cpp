//This is meng meng da mjy>_<
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

#define maxn 1010
#define maxm 5010
struct Edge
{
	int u,v;
}	a[maxm];
bool b[maxn][maxn];
queue<int>	Q;
bool vis1[maxn],vis2[maxn];
int dis[maxn];
bool vis[maxn];
int num[maxn];

struct Edge2
{
	int v,len,next;
}	e[maxm<<1];
int g[maxn],tot;
void add(int x,int y,int len)
{
	tot++;e[tot].v=y;e[tot].len=len;e[tot].next=g[x];g[x]=tot;
}
int n,m;
int main()
{
	read(n),read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		a[i].u=x,a[i].v=y;
		b[x][y]=true;
	}
	Q.push(1);
	vis1[1]=1;
	while (!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for (int j=1;j<=n;j++)
		if (b[u][j] && !vis1[j])	vis1[j]=true,Q.push(j);
	}
	Q.push(n);
	vis2[n]=1;
	while (!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for (int j=1;j<=n;j++)
		if (b[j][u] && !vis2[j])	vis2[j]=true,Q.push(j);
	}
	for (int i=1;i<=m;i++)
	if (vis1[a[i].u] && vis2[a[i].u] && vis1[a[i].v] && vis2[a[i].v])
	{
		add(a[i].u,a[i].v,-1);
		add(a[i].v,a[i].u,2);
	}
	for (int i=1;i<=n;i++)	dis[i]=1<<30;
	dis[n]=0;
	num[n]=1;
	vis[n]=true;
	Q.push(n);
	while (!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		vis[u]=false;
		if (num[u]>n)	{printf("No\n");return 0;}
		for (int i=g[u];i;i=e[i].next)
		if (dis[e[i].v]>dis[u]+e[i].len)
		{
			dis[e[i].v]=dis[u]+e[i].len;
			if (!vis[e[i].v])
			{
				vis[e[i].v]=true;
				num[e[i].v]++;
				Q.push(e[i].v);
			}
		}
	}
	printf("Yes\n");
	for (int i=1;i<=m;i++)
	if (vis1[a[i].u] && vis2[a[i].u] && vis1[a[i].v] && vis2[a[i].v])
		printf("%d\n",dis[a[i].u]-dis[a[i].v]);
	else printf("1\n");
	return 0;
}