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

const int MaxN=2000010;
const int MOD=1000000007;

int n,m,k;
int u[MaxN];

ll power(ll x,ll y)
{
	if (!y) return 1;
	ll t=power(x,y/2);
	t=t*t%MOD;
	if (y&1) t=t*x%MOD;
	return t;
}

int main()
{
	cin>>n>>m>>k;
	++k;
	for (int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x+1==y) continue;
		if (y-x!=k)
		{
			puts("0");
			return 0;
		}
		u[x]=1;
	}
	for (int i=1;i<=n+k;++i)
		u[i]+=u[i-1];
	ll ans=0;
	for (int i=1;i<=n;++i)
	{
		if (u[n+k]==u[i+k-1]-u[i-1])
		{
			int p=min(i+k-1,n-k)-i+1-u[n+k];
			if (u[i]==u[i-1]) p--;
			if (p>=0) ans+=power(2,p);
		}
	}
	if (!u[n+k]) ++ans;
	cout<<ans%MOD<<endl;
	return 0;
}