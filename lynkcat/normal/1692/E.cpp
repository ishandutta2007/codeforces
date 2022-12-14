// Lynkcat.
// Problem: E. Binary Deque
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/E
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
#define N 200005
using namespace std;
int n,m,s[N],a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	int l=1;
	int ans=n+1;
	for (int i=1;i<=n;i++)
	{
		l=max(l,i);
		while (l<n&&s[l+1]-s[i-1]<=m)
			l++;
		if (l>n) break;
		if (s[l]-s[i-1]==m) ans=min(ans,i-1+n-l);
	}
	if (ans==n+1) cout<<-1<<endl;
	else
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