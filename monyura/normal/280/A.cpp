#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

struct point
{
	double x;
	double y;
	double ang;
	point(){}
	point(double a,double b)
	{
		x=a;
		y=b;
	}
	void calcAng()
	{
		ang = atan2(y,x);
	}
};

bool operator<(const point &a,const point &b)
{
	return a.ang<b.ang;
}

point rotate(const point &a,double ang)
{
	double c = cos(ang);
	double s = sin(ang);
	return point(a.x * c - a.y*s,a.x*s + a.y*c);
}

point interVer(double x,const point &a,const point &b)
{
	double y = (x-a.x)/(b.x-a.x)*(b.y-a.y) + a.y;
	return point(x,y);
}

point interHor(double y,const point &a,const point &b)
{
	double x = (y-a.y)/(b.y-a.y)*(b.x-a.x) + a.x;
	return point(x,y);
}

double eps = 1e-8;
double getRes(int w,int h,int al)
{
	if (al>90)
		al = 180-al;
	if (al==0)
		return ll(w)*h;
	if (al==90)
		return SQR(min(ll(w),ll(h)));
	double rad = al*PI/180.0;
	point A[4]={point(-w/2.0,-h/2.0),point(-w/2.0,h/2.0),point(w/2.0,h/2.0),point(w/2.0,-h/2.0)};
	point P[5];
	rep(i,0,4)
		P[i] = rotate(A[i],rad);
	P[4]=P[0];
	double w2 = w/2.0;
	double h2 = h/2.0;
	vector<point> v;
	rep(i,0,4)
	{
		point a = P[i];
		point b = P[i+1];
		double X2[2]={w2,-w2};
		rep(j,0,2)
			if (min(a.x,b.x)-eps<=X2[j] && X2[j]<=max(a.x,b.x)+eps)
			{
				point p = interVer(X2[j],a,b);
				v.push_back(p);
			}
		double Y2[2]={h2,-h2};
		rep(j,0,2)
			if (min(a.y,b.y)-eps<=Y2[j] && Y2[j]<=max(a.y,b.y)+eps)
			{
				point p = interHor(Y2[j],a,b);
				v.push_back(p);
			}
	}
	rep(j,0,v.size())
		v[j].calcAng();
	sort(all(v));
	double res  = 0;
	v.push_back(v[0]);
	rep(j,0,v.size()-1)
		res+= (v[j].y + v[j+1].y)*(v[j+1].x-v[j].x);
	res/=2.0;
	res=fabs(res);
	return res;
	
}

void run()
{
	int w,h,al;
	cin>>w>>h>>al;
	double res= getRes(w,h,al);
	printf("%.10lf\n",res);
}





int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);	
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba
acaba
ba
bacb
*/