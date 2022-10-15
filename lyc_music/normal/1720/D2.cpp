#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
// #define int ll
#define N 300005
using namespace std;
mt19937_64 rnd(time(0));
gp_hash_table<int,int>aa[30][2];
int n,a[N],dp[N];
inline void upd(int x)
{
	int nw=0;
	int xx=x,yy=a[x];
	for (int dep=0;dep<=29;dep++)
	{
		xx^=1;
		aa[dep][xx&1][xx^yy]=max(aa[dep][xx&1][xx^yy],dp[x]);
		xx>>=1,yy>>=1;
	}
}
inline int query(int x)
{
	int nw=0;
	int xx=a[x],yy=x;
	for (int dep=0;dep<=29;dep++)
	{
		if (aa[dep][xx&1].find(xx^yy)!=aa[dep][xx&1].end())
		nw=max(aa[dep][xx&1][xx^yy],nw);
		xx>>=1,yy>>=1;
	}
	return nw;
}
void BellaKira()
{
	cin>>n;
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	int ans=0;
	for (int i=0;i<n;i++)
	{
		dp[i]=query(i)+1;
		ans=max(ans,dp[i]);
		upd(i);
	}
	cout<<ans<<'\n';
	for (int i=0;i<=29;i++) for (int j=0;j<2;j++) aa[i][j].clear();
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}