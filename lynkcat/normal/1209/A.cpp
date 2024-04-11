#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 105 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		bool bl=0;
		for (int j=1;j<i;j++)
			if (a[i]%a[j]==0) bl=1;
		ans+=bl^1;
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	// cin>>T;
	while (T--)
	{
		BellaKira();
	}
}