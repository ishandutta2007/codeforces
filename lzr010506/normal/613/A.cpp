#include <bits/stdc++.h>
#define N 100010
using namespace std;
const long double pi = acos(-1.0);
struct Point
{
	long double x, y;
	Point(){}
	Point(long double a,long double b):x(a),y(b){}
	Point operator +(const Point &a)const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator -(const Point &a)const
	{
		return Point(x - a.x, y - a.y);
	}
	long double operator *(const Point &a)const
	{
		return x * a.y - y * a.x;
	}
	Point operator *(long double k)const
	{
		return Point(x * k, y * k);
	}
}a,p[N];

struct Line
{
	Point p,v;
	long double alp;
	Line(){}
	Line(Point a,Point b):p(a),v(b){alp = atan2(v.y, v.x);}
};
Point inter(Line l1,Line l2)
{
	Point u = l1.p - l2.p;
	long double tmp = (l2.v * u) / (l1.v * l2.v);
	return l1.p + l1.v * tmp;
}
long double mx,mn = 10000000000000000ll;
Point rotate(Point p,long double alp)
{
	return Point(p.x * cos(alp) - p.y * sin(alp), p.x * sin(alp) + p.y * cos(alp));
}
long double dot(Point a)
{
	return a.x * a.x + a.y * a.y;
}
long double dot(Point a,Point b)
{
	return a.x * b.x + a.y * b.y;
}
int n;double f,g;
int main()
{
	cin>>n>>a.x>>a.y;
	for(int i = 1; i <= n + 1; i ++)
	{
		if(i <= n) scanf("%lf%lf",&f,&g), p[i].x = f, p[i].y = g;
		else p[i] = p[1];
		mx = max(mx, dot(p[i] - a));
		mn = min(mn, dot(p[i] - a));
		if(i > 1) 
		{
			Line l1 = Line(p[i - 1], p[i] - p[i - 1]);
			Line l2 = Line(a, rotate(l1.v, pi / 2));
			Point tmp = inter(l1, l2);
			if(dot(p[i - 1] - tmp, p[i] - tmp) <= 0) mn = min(mn,dot(tmp - a));
		}
	}
	printf("%.18lf\n",(double)(pi * (mx - mn)));
	return 0;
}