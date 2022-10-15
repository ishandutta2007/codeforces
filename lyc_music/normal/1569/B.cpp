// Lynkcat.
// Problem: B. Chess Tournament
// URL: https://codeforces.com/contest/1569/problem/B
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
#define N 55
using namespace std;
int n,m;
int f[N][N];
void BellaKira()
{
	cin>>n;
	int now=0;
	poly g;
	for (int i=1;i<=n;i++)
	{
		char a;
		cin>>a;
		a-='0';
		if (a==2) g.push_back(i);
		now+=(a==2);
	}
	if (now==1||now==2) return cout<<"NO"<<endl,void();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=1;
	for (int i=0;i<g.size();i++)
	{
		f[g[i]][g[(i+1)%g.size()]]=2;
		
		f[g[(i+1)%g.size()]][g[i]]=0;
	}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (i==j)
			{
				cout<<'X';
			} else
			
			if (f[i][j]==1) cout<<'=';
			else if (f[i][j]==0) cout<<'-';
			else if (f[i][j]==2) cout<<'+';
	cout<<endl;
	}
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