// Lynkcat.
// Problem: G. 2^Sort
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/G
// Memory Limit: 256 MB
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
#define N 200005
using namespace std;
int n,m,a[N],s[N];
void BellaKira()
{
	cin>>n>>m;
	m++;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	s[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i-1]<a[i]*2) s[i]=1;
		else s[i]=0;
		s[i]=s[i-1]+s[i];
	}
	int ans=0;
	for (int i=1;i+m-1<=n;i++)
	{
		if (s[i+m-1]-s[i]==m-1) ans++;
	}
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