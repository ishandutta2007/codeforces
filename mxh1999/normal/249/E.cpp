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
typedef long double db;
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

const ll mo=10000000000LL;
ll cheng(ll a,ll b)
{
	ll mjy=0;
	while (b)
	{
		if (b&1)
		{
			mjy=mjy+a;
			while (mjy>mo)	mjy-=mo;
		}
		a=(a+a);
		while (a>mo)	a-=mo;
		b>>=1;
	}
	return mjy;
}
ll f(int a,int b)
{
	ll x=a,y=b;
	if (a==0||b==0)	return 0;
	if (x<y)
	{
		ll mjy=x*x,xmm=x*x+1,mxh;
		if (mjy%2==0)	mjy/=2;else xmm/=2;
		mjy%=mo,xmm%=mo;
		mjy=cheng(mjy,xmm);
		xmm=(y-1)*y/2;
		if (xmm%3==0)
		{
			xmm/=3;
			xmm%=mo;
			xmm=cheng(xmm,(2*y-1));
		}	else
		{
			xmm%=mo;
			xmm=cheng(xmm,((2*y-1)/3));
		}
		mxh=xmm;
		xmm=(x-1)*x/2;
		if (xmm%3==0)
		{
			xmm/=3;
			xmm%=mo;
			xmm=cheng(xmm,(2*x-1));
		}	else
		{
			xmm%=mo;
			xmm=cheng(xmm,((2*x-1)/3));
		}
		mxh=(mxh-xmm+mo*3)%mo;
		mxh=cheng(mxh,x);
		mjy=(mjy+mxh)%mo;
		mxh=x*(x+1)/2;
		mxh%=mo;
		mxh=cheng(mxh,(y-x));
		mjy=(mjy+mxh)%mo;
		return mjy;
	}	else
	{
		ll mjy=y*y,xmm=y*y+1,mxh;
		if (mjy%2==0)	mjy/=2;else xmm/=2;
		mjy%=mo,xmm%=mo;
		mjy=cheng(mjy,xmm)%mo;
		xmm=x*(x+1)/2;
		if (xmm%3==0)
		{
			xmm/=3;
			xmm%=mo;
			xmm=cheng(xmm,(2*x+1));
		}	else
		{
			xmm%=mo;
			xmm=cheng(xmm,((2*x+1)/3));
		}
		mxh=xmm;
		xmm=y*(y+1)/2;
		if (xmm%3==0)
		{
			xmm/=3;
			xmm%=mo;
			xmm=cheng(xmm,(2*y+1));
		}	else
		{
			xmm%=mo;
			xmm=cheng(xmm,((2*y+1)/3));
		}
		mxh=(mxh-xmm+mo*3)%mo;
		mxh=cheng(mxh,y);
		mjy=(mjy+mxh)%mo;
		mxh=(y*(y-1)/2)%mo;
		mxh=cheng(mxh,(x-y));
		mjy=(mjy-mxh+mo)%mo;
		return mjy;
	}
}
db F(int a,int b)
{
	db x=a,y=b;
	db mxh;
	if (x==0 or y==0)	return 0;
	if (x<y)	mxh=x*x*(x*x+1)/2+x*((y-1)*y*(2*y-1)-(x-1)*x*(2*x-1))/6+x*(x+1)*(y-x)/2;else
				mxh=y*y*(y*y+1)/2+y*(x*(x+1)*(2*x+1)-y*(y+1)*(2*y+1))/6-y*(y-1)*(x-y)/2;
	return mxh;
}
int n;
int main()
{
	read(n);
	while (n--)
	{
		int x0,y0,x1,y1;
		read(x0),read(y0),read(x1),read(y1);
		db q=F(x1,y1)-F(x0-1,y1)-F(x1,y0-1)+F(x0-1,y0-1);
		ll mjy=f(x1,y1)-f(x0-1,y1)-f(x1,y0-1)+f(x0-1,y0-1);
		mjy%=mo;
		while (mjy<0)	mjy+=mo;
		if (q>=1e10)
		{
			printf("...");
			printf("%010I64d\n",mjy);
		}	else printf("%I64d\n",mjy);
	}
	return 0;
}