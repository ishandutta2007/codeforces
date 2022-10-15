// Lynkcat.
// Problem: E. Text Editor
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/E
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
#define inf 1e9
#define mod 998244353
// #define int ll
#define N 5005
using namespace std;
int n,m;
string st,st1;
int f[N],g[N],lcp[N][N];
void BellaKira()
{
	cin>>n>>m;
	cin>>st>>st1;
	st=' '+st;
	st1=' '+st1;
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (f[i]+1<=m&&st[i]==st1[f[i]+1]) f[i]++;
	}
	g[n+1]=m+1;
	for (int i=n;i>=1;i--)
	{
		g[i]=g[i+1];
		if (g[i]-1>0&&st[i]==st1[g[i]-1]) g[i]--;
	}
	int ans=inf;
	if (g[1]==1) ans=min(ans,n);
	for (int i=1;i<=n;i++)
	{
		if (f[i]!=i) break;
		if (g[i+1]<=i+1) ans=min(ans,n-i);
	}
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=m+1;j++) lcp[i][j]=0;
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
			if (st[i]==st1[j])
				lcp[i][j]=lcp[i+1][j+1]+1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=f[i];j++)
		{
			int x=lcp[i+1][j+1];
			int lst=i+x;
			if (g[lst+1]<=j+x+1)
				ans=min(ans,n-lst+1+i+i-j);
		}
	if (ans==inf) cout<<-1<<endl;
	else cout<<ans<<endl;
		
		
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