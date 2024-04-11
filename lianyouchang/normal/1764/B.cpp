// Problem: B. Doremy's Perfect Math Class
// Contest: Codeforces - Codeforces Global Round 24
// URL: https://codeforces.com/contest/1764/problem/B
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
	int x=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],x=__gcd(x,a[i]);
	int mx=0;
	for (int i=1;i<=n;i++)
		mx=max(mx,a[i]/x);
	cout<<mx<<'\n';
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