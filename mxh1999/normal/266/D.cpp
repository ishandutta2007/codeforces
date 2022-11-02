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

#define maxn 210
double eps=1e-11;
int a[maxn][maxn];
struct Edge
{
	int x,y,w;
}	e[maxn*maxn];
int n,m;
double mjy;
pair<int,int>	q[maxn];
int mxh[maxn];

int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		read(x),read(y),read(w);
		e[i].x=x,e[i].y=y,e[i].w=w;
		a[x][y]=w;
		a[y][x]=w;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			if (i!=j)
			if (a[i][k] && a[k][j])
			if (!a[i][j] || a[i][j]>a[i][k]+a[k][j])	a[i][j]=a[i][k]+a[k][j];
	for (int i=1;i<=n;i++)
	{
		int mxh=0;
		for (int j=1;j<=n;j++)	mxh=max(mxh,a[i][j]);
		if (i==1 || mxh<mjy)	mjy=mxh;
	}
	for (int i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y;
		for (int j=1;j<=n;j++)	q[j]=mp(a[x][j],a[y][j]);
		sort(q+1,q+n+1);
		mxh[n+1]=0;
		for (int j=n;j;j--)	mxh[j]=max(mxh[j+1],q[j].se);
		for(int j=1;j<=n;j++)
		{
			int l=q[j].fi,r=mxh[j+1];
			if (l>r) swap(l,r);
			if (l+e[i].w>=r) mjy=min(mjy,(l+e[i].w+r)/2.0);
		}
	}
	printf("%.11lf\n",mjy);
	return 0;
}