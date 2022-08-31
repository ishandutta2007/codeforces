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

const int MaxN=50010;
const int MOD=1000000009;

int n;
pdd p[MaxN];

bool cmp(pdd a,pdd b)
{
	return a.X*a.Y/(1-a.X)>b.X*b.Y/(1-b.X);
}

ld F[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		double x,y;
		scanf("%lf%lf",&y,&x);
		p[i].X=x/100;
		p[i].Y=y;
	}
	sort(p+1,p+n+1,cmp);
	ld s=0;
	for (int i=1;i<=n;++i)
	{
		F[i]=F[i-1]+p[i].Y+(1-p[i].X)*s;
		s+=p[i].X*p[i].Y;
	}
	printf("%.20lf\n",(double)F[n]);
	return 0;
}