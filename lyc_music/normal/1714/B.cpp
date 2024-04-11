// Lynkcat.
// Problem: B. Remove Prefix
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/B
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
int n,m,a[N];
void BellaKira()
{
	map<int,int>Mp;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	int ans=0;
	for (int i=n;i>=1;i--)
	{
		if (!Mp.count(a[i])) 
		{
			Mp[a[i]]=i;
			continue;
		}
		ans=i;
		break;
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