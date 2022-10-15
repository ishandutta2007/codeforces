// Lynkcat.
// Problem: C. Most Similar Words
// URL: https://codeforces.com/contest/1676/problem/C
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
// #define int ll
#define N 55
using namespace std;
int n,m;
string st[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];
	}
	int as=26*m;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int ans=0;
			for (int k=0;k<m;k++)
				ans+=abs(st[i][k]-st[j][k]);
			as=min(as,ans);
			// cout<<"?"<<i<<","<<j<<" "<<as<<endl;
		}
	cout<<as<<endl;
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