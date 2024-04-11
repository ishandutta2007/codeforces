// Lynkcat.
// Problem: E. Eating Queries
// URL: https://codeforces.com/contest/1676/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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
#define N 200005
using namespace std;
int n,m,s[N],a[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		int y=lower_bound(s+1,s+n+1,x)-s;
		if (y==n+1) cout<<-1<<endl;
		else cout<<y<<endl;
	}
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