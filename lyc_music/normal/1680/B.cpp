// Lynkcat.
// Problem: B. Robots
// URL: https://codeforces.com/contest/1680/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
#define N 105
using namespace std;
int n,m,b[N];
void BellaKira()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) b[i]=m+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='R') b[i]=min(j,b[i]);
		}
	int ans=1;
	// cout<<b[1]<<" "<<b[2]<<endl;
	for (int i=1;i<n;i++)
	{
		if (b[i]!=m+1&&b[i+1]<b[i])
		{
			ans=0;
			break;
		} else
		{
			b[i+1]=min(b[i+1],b[i]);
		}
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
		
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