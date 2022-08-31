#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=200010;
const int INF=1000000000;

int n;
pdd p[MaxN];
ld tot;

ld det(pdd a,pdd b)
{
	return a.X*b.Y-a.Y*b.X;
}

ld det(pdd a,pdd b,pdd c)
{
	return a.X*b.Y-b.X*a.Y+b.X*c.Y-c.X*b.Y+c.X*a.Y-a.X*c.Y;
}

int Lx[2000010],Rx[2000010],d[2000010];

ld solve()
{
	p[n+1]=p[1];
	ld area=0;
	for (int i=1;i<=n;++i)
		area+=det(p[i],p[i+1]);
	if (area<0)
		reverse(p+1,p+n+1);
	for (int i=1;i<=n;++i)
		p[i+n]=p[i];
	int s=min_element(p+1,p+n+1)-p;
	int t=max_element(p+1,p+n+1)-p;
	for (int i=0;i<=2*1e6;++i)
	{
		Lx[i]=INF;
		Rx[i]=-INF;
	}
	for (int i=s;i!=t&&i!=n+t;++i)
	{
		Lx[(int)p[i].X]=min(Lx[(int)p[i].X],(int)p[i].Y);
		Rx[(int)p[i].X]=max(Rx[(int)p[i].X],(int)p[i].Y);
		if (p[i].X!=p[i+1].X)
		{
			ld k=(p[i+1].Y-p[i].Y)/(p[i+1].X-p[i].X);
			ld b=p[i].Y-k*p[i].X;
			for (int j=p[i].X+1;j<p[i+1].X;++j)
			{
				int t=k*j+b;
				while (det(p[i],p[i+1],pii(j,t))<0) ++t;
				Lx[j]=min(Lx[j],t);
			}
		}
	}
	for (int i=t;i!=s&&i!=n+s;++i)
	{
		Lx[(int)p[i].X]=min(Lx[(int)p[i].X],(int)p[i].Y);
		Rx[(int)p[i].X]=max(Rx[(int)p[i].X],(int)p[i].Y);
		if (p[i].X!=p[i+1].X)
		{
			ld k=(p[i+1].Y-p[i].Y)/(p[i+1].X-p[i].X);
			ld b=p[i].Y-k*p[i].X;
			for (int j=p[i].X-1;j>p[i+1].X;--j)
			{
				int t=k*j+b;
				while (det(p[i],p[i+1],pii(j,t))<0) --t;
				Rx[j]=max(Rx[j],t);
			}
		}
	}
	ld x=0,sx=0;
	tot=0;
	for (int i=0;i<=2*1e6;++i)
	{
		d[i]=max(Rx[i]-Lx[i]+1,0);
		tot+=d[i];
	}
	for (int i=0;i<=2*1e6;++i)
	{
		x+=(ld)d[i]*i/tot;
		sx+=(ld)d[i]*i*i/(tot-1);
	}
	return sx-x*x/(tot-1)*tot;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		p[i].X=x;
		p[i].Y=y;
	}
	ld x=INF,y=INF;
	for (int i=1;i<=n;++i)
	{
		x=min(x,p[i].X);
		y=min(y,p[i].Y);
	}
	for (int i=1;i<=n;++i)
	{
		p[i].X-=x;
		p[i].Y-=y;
	}
	ld ans=0;
	ans+=solve();
	for (int i=1;i<=n;++i)
		swap(p[i].X,p[i].Y);
	ans+=solve();
	printf("%.20lf\n",(double)ans);
	return 0;
}