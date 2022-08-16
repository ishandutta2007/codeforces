#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=100010;
const double g=9.8;
const double INF=1e20;

int n,m;
double v;

struct point
{
	double a;
	int p;
	double x,y;
}q[MaxN];

bool cmp_a(point A,point B)
{
	return A.a>B.a;
}

bool cmp_p(point A,point B)
{
	return A.p<B.p;
}

struct node
{
	double x,y,tg;
	void init()
	{
		scanf("%lf%lf",&x,&y);
		double a=g*x*x/2/v/v;
		double b=-x;
		double c=y+a;
		double s=b*b-4*a*c;
		if (s<=0)
			tg=INF;
		else
			tg=(-b-sqrt(s))/2/a;
	}
	bool operator < (node A) const
	{
		return tg>A.tg;
	}
}p[MaxN];

void init()
{
	cin>>n>>v;
	for (int i=1;i<=n;++i)
	{
		scanf("%lf",&q[i].a);
		q[i].a=tan(q[i].a);
		q[i].p=i;
	}
	sort(q+1,q+n+1,cmp_a);
	cin>>m;
	for (int i=1;i<=m;++i)
		p[i].init();
	sort(p+1,p+m+1);
}

void work()
{
	int j=1;
	double x=INF;
	for (int i=1;i<=n;++i)
	{
		while (j<=m)
		{
			if (p[j].tg<q[i].a) break;
			x=min(x,p[j++].x);
		}
		double y=x*q[i].a-g*x*x*(q[i].a*q[i].a+1)/2/v/v;
		if (y<0)
		{
			q[i].x=2*v*v*q[i].a/g/(q[i].a*q[i].a+1);
			q[i].y=0;
		}
		else
		{
			q[i].x=x;
			q[i].y=y;
		}
	}
	sort(q+1,q+n+1,cmp_p);
	for (int i=1;i<=n;++i)
		printf("%.9lf %.9lf\n",q[i].x,q[i].y);
}

int main()
{
	init();
	work();
	return 0;
}