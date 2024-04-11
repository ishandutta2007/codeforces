#include<bits/stdc++.h>
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
#define int ll
#define N 100005
using namespace std;
int n,m,a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0;
	int ans=0;
	for (int i=n;i>=1;i--)
	{
		int x=1;
		while (x*a[i]<=m&&l+1<i)
		{
			l++;
			x++;
		}
		if (x*a[i]<=m) break;
		// cout<<l<<
		ans++;
	}
	cout<<ans<<'\n';
			
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}