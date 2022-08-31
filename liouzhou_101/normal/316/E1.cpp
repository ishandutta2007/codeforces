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

const int MaxN=200010;
const int MOD=1000000000;

int n,m;
int f[MaxN],a[MaxN];

int main()
{
	cin>>n>>m;
	f[0]=f[1]=1;
	for (int i=2;i<=n;++i)
		f[i]=(f[i-1]+f[i-2])%MOD;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	while (m--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x,v;
			scanf("%d%d",&x,&v);
			a[x]=v;
		}
		else if (t==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ll ans=0;
			for (int i=0;i<=y-x;++i)
			{
				(ans+=(ll)a[x+i]*f[i])%=MOD;
			}
			printf("%d\n",(int)ans);
		}
		else if (t==3)
		{
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			for (int i=0;i<=y-x;++i)
			{
				(a[i+x]+=d)%=MOD;
			}
		}
	}
	return 0;
}