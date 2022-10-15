#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e11
#define mod 998244353
#define int ll
#define N 5000005
using namespace std;
int a[N];
int calc(int x)
{
	if (x==3) return 1;
	return x-((x+2)/4)-2;
}
void BellaKira()
{
	int n;
	cin>>n;
	int l=1,r=inf;
	int ans=0;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		if (calc(mid)>=n)
		{
			ans=mid;
			r=mid-1;
		} else l=mid+1;
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