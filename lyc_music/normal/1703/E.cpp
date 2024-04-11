// Lynkcat.
// Problem: E. Mirror Grid
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/E
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
#define N 1005
using namespace std;
int n,a[N][N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=n;j++)
		{
			if (st[j-1]=='1') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	int ans=0;
	for (int i=1;i<=(n)/2;i++)
		for (int j=1;j<=(n+1)/2;j++)
			{
				// cout<<"?"<<i<<" "<<j<<" "<<
				// min(a[i][j]+a[j][n-i+1]+a[n-i+1][n-j+1]+a[n-i+1][j],4-(a[i][j]+a[j][n-i+1]+a[n-i+1][n-j+1]+a[n-i+1][j]))<<endl;
				// cout<<j<<" "<<n-i+1<<" "<<n-i+1<<" "<<n-j+1<<" "<<n-i+1<<" "<<j<<endl;
				ans+=min(a[i][j]+a[j][n-i+1]+a[n-i+1][n-j+1]+a[n-j+1][i],4-(a[i][j]+a[j][n-i+1]+a[n-i+1][n-j+1]+a[n-j+1][i]));
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
/*
11100
11011
01011
10011
11000

111
110

011
011

000
110

110
101
*/