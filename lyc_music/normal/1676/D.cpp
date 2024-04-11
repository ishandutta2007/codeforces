// Lynkcat.
// Problem: D. X-Sum
// URL: https://codeforces.com/contest/1676/problem/D
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
#define N 205
using namespace std;
const int B=1005;
int n,m,a[N][N],s1[100005],s[100005];
void BellaKira()
{
	int ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[i-j+B]+=a[i][j];
			s1[i+j]+=a[i][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			ans=max(ans,s[i-j+B]+s1[i+j]-a[i][j]);
			// cout<<"?"<<i<<" "<<j<<" "<<s[i-j+B]+s1[i+j]-a[i][j]<<" "<<s[i-j+B]<<" "<<s1[i+j]<<endl;
		}
	cout<<ans<<endl;
	for (int i=1-m;i<=n-1;i++)
		s[i+B]=0;
	for (int i=2;i<=n+m;i++)
		s1[i]=0;
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