// Lynkcat.
// Problem: D. Array and Operations
// URL: https://codeforces.com/contest/1618/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// -----------------------------------------------

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
#define N 50005
using namespace std;
int n,m,a[N],vis[N];
void BellaKira()
{
	cin>>n>>m;
	int ans=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],vis[i]=0;
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);	
	for (int i=1;i<=m;i++)
	
		  if (a[m-i+1]==a[2*m-i+1]) ans++;
		for (int i=2*m+1;i<=n;i++) ans+=a[i];
	cout<<ans<<endl;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}