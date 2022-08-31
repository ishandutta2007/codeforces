#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=110;

int n;
long double xs,ys,xt,yt;
long double x[MaxN],y[MaxN];
vector<pair<int,pair<long double,long double> > > v;

void init()
{
	cin>>xs>>ys>>xt>>yt>>n;
	for (int i=0;i<n;++i)
		cin>>x[i]>>y[i];
	x[n]=x[0];
	y[n]=y[0];
}

long double getdis(long double x1,long double y1,long double x2,long double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(long double a,long double b,long double c,long double d,long double e,long double f,long double &x,long double &y)
{
	x=(c*e-b*f)/(a*e-b*d);
	y=(c*d-a*f)/(b*d-a*e);
}

bool cross(long double ax1,long double ay1,long double ax2,long double ay2,long double bx1,long double by1,long double bx2,long double by2,long double &px,long double &py)
{
	long double ax=ax2-ax1,ay=ay2-ay1;
	long double bx=bx2-bx1,by=by2-by1;
	if (ax*by==ay*bx) return false;
	solve(ax,-bx,bx1-ax1,ay,-by,by1-ay1,px,py);
	if (0<=px&&px<1&&0<=py&&py<1)
	{
		long double t=px;
		px=ax1+t*ax;
		py=ay1+t*ay;
		return true;
	}
	return false;
}

void work()
{
	for (int i=0;i<n;++i)
	{
		long double px,py;
		if (cross(xs,ys,xt,yt,x[i],y[i],x[i+1],y[i+1],px,py))
			v.push_back(make_pair(i,make_pair(px,py)));
	}
	if (v.size()<=1)
		printf("%.9lf\n",(double)getdis(xs,ys,xt,yt));
	else
	{
		long double sum=0;
		for (int i=0;i<n;++i)
			sum+=getdis(x[i],y[i],x[i+1],y[i+1]);
		if (getdis(xs,ys,v[0].second.first,v[0].second.second)>getdis(xs,ys,v[1].second.first,v[1].second.second))
			swap(v[0],v[1]);
		long double get=0;
		for (int i=(v[0].first+1)%n;i!=v[1].first;i=(i+1)%n)
			get+=getdis(x[i],y[i],x[i+1],y[i+1]);
		get+=getdis(v[0].second.first,v[0].second.second,x[(v[0].first+1)%n],y[(v[0].first+1)%n]);
		get+=getdis(v[1].second.first,v[1].second.second,x[v[1].first],y[v[1].first]);
		get=min(2*getdis(v[0].second.first,v[0].second.second,v[1].second.first,v[1].second.second),min(sum-get,get));
		printf("%.9lf\n",(double)(get+getdis(xs,ys,v[0].second.first,v[0].second.second)+getdis(xt,yt,v[1].second.first,v[1].second.second)));
	}
}

int main()
{
	init();
	work();
	return 0;
}