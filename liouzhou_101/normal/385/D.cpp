#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const ld pi=3.1415926535897932384626;

int n;
ld l,r;
struct point
{
	ld x,y,a;
	ld calc(ld x0)
	{
		ld px=x0-x,py=-y;
		ld ax=px*cos(a)-py*sin(a),ay=px*sin(a)+py*cos(a);
		if (fabs(ay)<1e-12) return r;
		if (ay>0) return r;
		return min(x-y*ax/ay,r);
	}
}p[22];
ld F[1<<20];

void fresh(ld &x,ld y)
{
	if (x<y) x=y;
}

int main()
{
	cin>>n>>l>>r;
	r-=l;
	for (int i=0;i<n;++i)
	{
		cin>>p[i].x>>p[i].y>>p[i].a;
		p[i].a=p[i].a/180*pi;
		p[i].x-=l;
	}
	for (int s=0;s<1<<n;++s)
	{
		for (int i=0;i<n;++i) if (!(s&1<<i))
		{
			fresh(F[s|1<<i],p[i].calc(F[s]));
		}
	}
	printf("%.9f\n",min(F[(1<<n)-1],r));
	return 0;
}