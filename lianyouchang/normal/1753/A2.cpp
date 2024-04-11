// Problem: A1. Make Nonzero Sum (easy version)
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/contest/1753/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
int vis[200005];
int n,a[200005];
void BellaKira()
{
	cin>>n;
	int x=0;
	for (int i=1;i<=n;i++) vis[i]=1;
	for (int i=1;i<=n;i++)
		cin>>a[i],x+=a[i];
	if (x&1) return cout<<-1<<'\n',void();
	int lst=1;
	vector<pa>ans;
	for (int i=1;i<=n;i++)
		if (abs(x-2*a[i])<abs(x))
		{
			if (vis[i-1])
				vis[i]=0,x-=2*a[i];
		}
	for (int i=1;i<=n;i++)
		if (vis[i])
		{
			if (i>1)
				ans.push_back(mp(lst,i-1));
			lst=i;
		}
	ans.push_back(mp(lst,n));
	cout<<ans.size()<<'\n';
	for (auto u:ans) cout<<u.fi<<" "<<u.se<<'\n';
		
				
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}