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

const int MaxN=100010;
const ll INF=1000000000000000000LL;

int n;
pll p[MaxN];
ll La[MaxN],Lb[MaxN],Ra[MaxN],Rb[MaxN];

bool check(ll d)
{
	for (int i=1,j=1;i<=n;++i)
	{
		while (p[i].X-p[j].X>d) ++j;
		if (j==1&&i==n) return true;
		ll a=min(La[j-1],Ra[i+1]);
		ll b=max(Lb[j-1],Rb[i+1]);
		if (b-a<=d) return true;
	}
	return false;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=pll(x-y,x+y);
	}
	sort(p+1,p+n+1);
	La[0]=INF;
	Lb[0]=-INF;
	for (int i=1;i<=n;++i)
	{
		La[i]=min(La[i-1],p[i].Y);
		Lb[i]=max(Lb[i-1],p[i].Y);
	}
	Ra[n+1]=INF;
	Rb[n+1]=-INF;
	for (int i=n;i>=1;--i)
	{
		Ra[i]=min(Ra[i+1],p[i].Y);
		Rb[i]=max(Rb[i+1],p[i].Y);
	}
	ll L=0,R=4000000000LL;
	ll ans=R;
	while (L<=R)
	{
		ll m=(L+R)/2;
		if (check(m))
		{
			ans=m;
			R=m-1;
		}
		else
			L=m+1;
	}
	printf("%.1lf\n",ans*.5);
	return 0;
}