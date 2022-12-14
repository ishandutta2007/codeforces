// Problem: D. Watch the Videos
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
#define N 500005
using namespace std;
int n,m,a[N];
void BellaKira()
{
	int ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int fx=1;
	int l=1,r=n;
	while (l<r)
	{
		if (a[l]+a[r]<=m)
		{
			if (fx==1)
			{
				ans+=a[r];
				r--;
			}  else
			{
				ans+=a[l];l++;
			}
			fx^=1;
		} else
		{
			fx=1;
			ans+=a[r]+1;
			r--;
		}
	}
	if (fx==1) ans+=a[r];
	else ans+=a[l];
	ans++;
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