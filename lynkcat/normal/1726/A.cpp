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
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	static int a[2005];
	for (int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	int ans=a[n-1]-a[0];
	for (int i=0;i<n;i++)
	{
		if (i>0)
			ans=max(ans,a[i]-a[0]);
		ans=max(ans,a[(i+n-1)%n]-a[i]);
		if (i<n-1) ans=max(ans,a[n-1]-a[i]);
	}
	cout<<ans<<'\n';
		
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