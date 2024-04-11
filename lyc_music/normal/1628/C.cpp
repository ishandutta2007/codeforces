// Lynkcat.
// Problem: C. Grid Xor
// URL: https://codeforces.com/contest/1628/problem/C
// Memory Limit: 256 MB
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
#define N 1005
using namespace std;
int c[N][N];
int n;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>c[i][j];
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0)
			{
				if (i==n||j==n) continue;
				if ((n/2-max(abs(i-n/2),abs(j-n/2)))%4==1||(n/2-max(abs(i-n/2),abs(j-n/2)))%4==2) ans^=c[i][j];
			}
	for (int i=1;i<=n;i++)
	{
		reverse(c[i]+1,c[i]+n+1);
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0)
			{
				if (i==n||j==n) continue;
				if ((n/2-max(abs(i-n/2),abs(j-n/2)))%4==1||(n/2-max(abs(i-n/2),abs(j-n/2)))%4==2) ans^=c[i][j];
			}
	}
	cout<<ans<<endl;
	
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}