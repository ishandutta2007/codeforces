// Lynkcat.
// Problem: C. Paint the Array
// URL: https://codeforces.com/contest/1618/problem/C
// Memory Limit: 256 MB
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
#define N 1005
using namespace std;
int n,s[2],a[N];
void BellaKira()
{
	cin>>n;
	int ans=0;
	s[0]=0,s[1]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i],s[i%2]=__gcd(s[i%2],a[i]);
		// cout<<i<<" "<<s[0]<<" "<<s[1]<<endl;
	}
	bool res=1,res1=1;
	for (int i=1;i<=n;i+=2)
		if (a[i]%s[(i^1)%2]==0) res=0;
	for (int i=2;i<=n;i+=2)
		if (a[i]%s[(i^1)%2]==0) res1=0;
	if (res) cout<<s[0]<<endl;
	else if (res1) cout<<s[1]<<endl;
	else
	cout<<0<<endl;
		
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