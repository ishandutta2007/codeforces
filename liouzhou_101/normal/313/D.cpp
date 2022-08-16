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

const int MaxN=310;
const ll INF=1000000000000000000LL;

int n,m,k;
ll c[MaxN][MaxN],F[MaxN][MaxN];

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i)
		for (int j=i;j<=n;++j)
			c[i][j]=INF;
	for (int i=1;i<=m;++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		c[x][y]=min(c[x][y],(ll)w);
	}
	for (int kk=1;kk<=n;++kk)
		for (int i=1;i<=n;++i)
		{
			int j=i+kk-1;
			if (j>n) continue;
			ll t=INF;
			for (int p=i;p<=j;++p)
			{
				t=min(t,c[p][j]);
				c[i][j]=min(c[i][j],c[i][p]+t);
			}
		}
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
			F[i][j]=INF;
	F[0][0]=0;
	for (int i=1;i<=n;++i)
		for (int j=0;j<=i;++j)
		{
			for (int k=1;k<=i;++k)
				if (j>=i-k+1) F[i][j]=min(F[i][j],F[k-1][j-(i-k+1)]+c[k][i]);
			F[i][j]=min(F[i][j],F[i-1][j]);
		}
	ll ans=INF;
	for (int i=1;i<=n;++i)
		for (int j=k;j<=i;++j)
			ans=min(ans,F[i][j]);
	if (ans==INF)
		puts("-1");
	else
		cout<<ans<<endl;
	return 0;
}