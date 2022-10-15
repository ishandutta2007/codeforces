// Lynkcat.
// Problem: B. Making Towers
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/B
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
#define N 100005 
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	map<int,int>f[2];
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=0;
		int j=i%2;
		x=f[j^1][a[i]];
		f[j][a[i]]=max(f[j][a[i]],x+1);
		// cout<<i<<","<<f[0][a[i]]<<" "<<f[1][a[i]]<<" "<<j<<endl;
		
	}
	for (int i=1;i<=n;i++) cout<<max(f[0][i],f[1][i])<<" ";
	cout<<endl;
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