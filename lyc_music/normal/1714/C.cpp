// Lynkcat.
// Problem: C. Minimum Varied Number
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/C
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
// #define N 
using namespace std;
int ans;
int f[105];
int n;
int vis[10];
void dfs(int x,int y)
{
	if (x>=ans) return;
	if (y==0)
	{
		ans=x;
		return;
	}
	for (int i=min(9ll,y);i>=(x==0);i--)
	if (!vis[i])
	{
		vis[i]=1;
		dfs(x*10+i,y-i);
		vis[i]=0;
	}
}
		
void BellaKira()
{
	cin>>n;
	if (f[n]!=0) 
	{
		cout<<f[n]<<endl;
		return;
	}
	ans=inf;
	// cin>>n;
	dfs(0,n);
	cout<<ans<<endl;
	f[n]=ans;
}
signed main()
{
	IOS;
	int T=45;
	cin>>T;
	while (T--)
	{
		// n=T+1;
		BellaKira();
	}
}