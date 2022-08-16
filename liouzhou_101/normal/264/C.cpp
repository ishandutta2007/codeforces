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

const int MaxN=100010;
const ll INF=10000000000000000LL;

int n;
ll v[MaxN];
int c[MaxN];
ll F[MaxN];

void solve(ll a,ll b)
{
	for (int i=0;i<=n;++i)
		F[i]=-INF;
	F[0]=0;
	pll x(0,0),y(-INF,1);
	for (int i=1;i<=n;++i)
	{
		F[c[i]]=max(F[c[i]],v[i]*a+F[c[i]]);
		if (x.Y!=c[i])
			F[c[i]]=max(F[c[i]],v[i]*b+x.X);
		else
			F[c[i]]=max(F[c[i]],v[i]*b+y.X);
		pll p(F[c[i]],c[i]);
		if (p>x)
		{
			if (x.Y==p.Y)
			{
				x=p;
			}
			else
			{
				y=x;
				x=p;
			}
		}
		else if (p>y)
			if (p.Y!=x.Y) y=p;
	}
	ll ans=0;
	for (int i=0;i<=n;++i)
		ans=max(ans,F[i]);
	printf("%I64d\n",ans);
}

int main()
{
	int q;
	cin>>n>>q;
	for (int i=1;i<=n;++i)
		scanf("%I64d",&v[i]);
	for (int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	while (q--)
	{
		ll a,b;
		scanf("%I64d%I64d",&a,&b);
		solve(a,b);
	}
	return 0;
}