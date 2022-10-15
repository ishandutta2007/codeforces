// Lynkcat.
// Problem: C. Zero Path
// Contest: Codeforces - Codeforces Round #801 (Div. 2) and EPIC Institute of Technology Round
// URL: https://codeforces.com/contest/1695/problem/C
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
int n,m,a[N][N];
bitset<4000>b[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j];
		for (int j=1;j<=m;j++)
			b[j].reset();
	b[1][2000]=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i][1]==1) b[1]<<=1;
		else b[1]>>=1;
		for (int j=2;j<=m;j++)
		{
			if (a[i][j]==1)
				b[j]=(b[j-1]|b[j])<<1;
			else b[j]=(b[j-1]|b[j])>>1;
		}
	}
	if (b[m][2000]) cout<<"YES"<<endl;
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