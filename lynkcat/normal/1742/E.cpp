// Lynkcat.
// Problem: E. Scuza
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
#define N  200005
using namespace std;
int n,q,a[N];
pa b[N];
int ans[N];
int s[N];
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	for (int i=1;i<=q;i++)
		cin>>b[i].fi,b[i].se=i;
	sort(b+1,b+q+1);
	int x=0;
	for (int i=1;i<=q;i++)
	{
		while (x+1<=n&&a[x+1]<=b[i].fi)
		{
			x++;
		}
		ans[b[i].se]=s[x];
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<" ";
	cout<<'\n';
	
	
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