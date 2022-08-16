#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=810;
const int INF=1000000000;

int n;
int x[MaxN],y[MaxN];
int ux[MaxN],uy[MaxN],mx[MaxN],my[MaxN];
ld vx[MaxN],vy[MaxN],F[MaxN][MaxN],slack[MaxN];
int root;

bool find(int x)
{
	ux[x]=1;
	for (int i=1;i<=n*2;++i)
	{
		ld tmp=vx[x]+vy[i]-F[x][i];
		if (!uy[i]&&tmp<1e-10)
		{
			uy[i]=1;
			if (!my[i]||find(my[i]))
			{
				mx[x]=i;
				my[i]=x;
				return true;
			}
		}
		else if (!uy[i]&&tmp>0)
			slack[i]=min(slack[i],tmp);
	}
	return false;
}

void work()
{
	for (int i=1;i<=n;++i)
	{
		vx[i]=-INF;
		for (int j=1;j<=n*2;++j)
			vx[i]=max(vx[i],F[i][j]);
	}
	for (int i=1;i<=n;++i) if (i!=root)
		while (1)
		{
			for (int j=1;j<=n*2;++j)
			{
				ux[j]=uy[j]=0;
				slack[j]=INF;
			}
			if (find(i)) break;
			ld d=INF;
			for (int j=1;j<=n*2;++j)
				if (!uy[j]) d=min(d,slack[j]);
			for (int j=1;j<=n*2;++j)
			{
				if (ux[j]) vx[j]-=d;
				if (uy[j]) vy[j]+=d;
			}
		}
	ld ans=0;
	for (int i=1;i<=n;++i)
	{
		if (i==root) continue;
		if (!mx[i])
		{
			puts("-1");
			return;
		}
		ans+=F[i][mx[i]];
	}
	if (-ans>=INF)
		puts("-1");
	else
		printf("%.20lf\n",-ans);
}

ld getdis(ld x1,ld y1,ld x2,ld y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void addedge(int x,int y,ld t)
{
	F[x][y]=t;
}

int main()
{
	cin>>n;
	root=1;
	for (int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
		if (y[i]>y[root]) root=i;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			F[i][j*2-1]=F[i][j*2]=-INF;
	for (int i=1;i<=n;++i) if (i!=root)
		for (int j=1;j<=n;++j)
			if (y[i]<y[j])
			{
				ld t=-getdis(x[i],y[i],x[j],y[j]);
				addedge(i,j*2-1,t);
				addedge(i,j*2,t);
			}
	work();
	return 0;
}