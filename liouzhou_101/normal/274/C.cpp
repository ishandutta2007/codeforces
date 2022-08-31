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

const int MaxN=110;

int n;
pdd p[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>p[i].X>>p[i].Y;
	sort(p+1,p+n+1);
}

pdd operator + (pdd a,pdd b)
{
	return pdd(a.X+b.X,a.Y+b.Y);
}

pdd operator - (pdd a,pdd b)
{
	return pdd(a.X-b.X,a.Y-b.Y);
}

pdd operator / (pdd a,ld k)
{
	return pdd(a.X/k,a.Y/k);
}

ld sqrmod(pdd a)
{
	return a.X*a.X+a.Y*a.Y;
}

ld sqrgetdis(pdd a,pdd b)
{
	return sqrmod(a-b);
}

ld getdis(pdd a,pdd b)
{
	return sqrt(sqrgetdis(a,b));
}

void line(pdd a,pdd b,ld &A,ld &B,ld &C)
{
	pdd c=(a+b)/2;
	A=(a-b).X;
	B=(a-b).Y;
	C=A*c.X+B*c.Y;
}

void solve(ld a,ld b,ld c,ld d,ld e,ld f,ld &x,ld &y)
{
	x=(c*e-b*f)/(a*e-b*d);
	y=(c*d-a*f)/(b*d-a*e);
}

pdd inner(pdd A,pdd B,pdd C)
{
	ld a,b,c,d,e,f;
	line(A,B,a,b,c);
	line(A,C,d,e,f);
	ld x,y;
	solve(a,b,c,d,e,f,x,y);
	return pdd(x,y);
}

void work()
{
	ld ans=-1;
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
			for (int k=j+1;k<=n;++k)
			{
				ld a=sqrgetdis(p[i],p[j]),b=sqrgetdis(p[i],p[k]),c=sqrgetdis(p[j],p[k]);
				if (a+b>c&&a+c>b&&b+c>a)
				{
					pdd x=inner(p[i],p[j],p[k]);
					ld t=1e40;
					for (int d=1;d<=n;++d) if (d!=i&&d!=j&&d!=k)
						t=min(t,getdis(x,p[d]));
					if (t>=getdis(x,p[i])) ans=max(ans,getdis(x,p[i]));
				}
				if (a+b==c||a+c==b||b+c==a)
				{
					pdd x,y;
					if (a+b==c)
					{
						x=p[j]+p[k]-p[i];
						y=(p[j]+p[k])/2;
					}
					if (a+c==b)
					{
						x=p[i]+p[k]-p[j];
						y=(p[i]+p[k])/2;
					}
					if (b+c==a)
					{
						x=p[i]+p[j]-p[k];
						y=(p[i]+p[j])/2;
					}
					if (p[lower_bound(p+1,p+n+1,x)-p]==x)
					{
						x=y;
						ld t=1e40;
						for (int d=1;d<=n;++d) if (d!=i&&d!=j&&d!=k)
							t=min(t,getdis(x,p[d]));
						if (t>=getdis(x,p[i])) ans=max(ans,getdis(x,p[i]));
					}
				}
			}
	if (ans==-1)
		puts("-1");
	else
		printf("%.20lf\n",(double)ans);
}

int main()
{
	init();
	work();
	return 0;
}