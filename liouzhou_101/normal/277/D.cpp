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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=2010;
const ll P=1000000;

int n,t;

struct prob
{
	ld sx,sy,p;
	ll tx,ty;
	void init()
	{
		cin>>sx>>sy>>tx>>ty>>p;
		p=1-p;
		sx*=P;
		sy*=P;
		sy=(ll)(sy*p+0.2);
	}
	bool operator < (prob A) const
	{
		return ty*(1-p)*A.p<A.ty*(1-A.p)*p;
	}
}a[MaxN];

pdd F[MaxN][MaxN];

void fresh(pdd &x,pdd y)
{
	if (x<y) x=y;
}

int main()
{
	cin>>n>>t;
	for (int i=1;i<=n;++i)
		a[i].init();
	sort(a+1,a+n+1);
	pdd ans(0,0);
	for (int i=1;i<=n;++i)
		for (int j=0;j<=t;++j)
		{
			fresh(F[i][j],F[i-1][j]);
			if (j+a[i].tx<=t)
				fresh(F[i][j+a[i].tx],pdd(F[i-1][j].X+a[i].sx,F[i-1][j].Y-a[i].tx));
			if (j+a[i].tx+a[i].ty<=t)
				fresh(F[i][j+a[i].tx+a[i].ty],pdd(F[i-1][j].X+a[i].sx+a[i].sy,-(j+a[i].tx+a[i].ty)*a[i].p+(F[i-1][j].Y-a[i].tx)*(1-a[i].p)));
			ans=max(ans,F[i][j]);
		}
	printf("%.20lf %.20lf\n",(double)(ans.X/P),(double)-ans.Y);
	return 0;
}