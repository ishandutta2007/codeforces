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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n;
const ll INF=10000000000000000LL;

int main()
{
	cin>>n;
	ll lx=INF,rx=-INF,ly=INF,ry=-INF,s=0;
	for (int i=1;i<=n;++i)
	{
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		lx=min(lx,x1);
		rx=max(rx,x2);
		ly=min(ly,y1);
		ry=max(ry,y2);
		s+=(y2-y1)*(x2-x1);
	}
	if (rx-lx==ry-ly) if ((rx-lx)*(rx-lx)==s)
	{
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}