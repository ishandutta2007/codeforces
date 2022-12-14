// Problem: E. Yet Another Array Counting Problem
// Contest: Codeforces - Codeforces Round #833 (Div. 2)
// URL: https://codeforces.com/contest/1748/problem/E
// Memory Limit: 512 MB
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
#define mod 1000000007
#define int ll
#define N 200005 
using namespace std;
int a[N];
poly dp[N];
int st[N][20];
int n,m;
int cmp(int x,int y)
{
	if (a[x]>a[y]) return x;
	if (a[x]<a[y]) return y;
	return min(x,y);
}
int query(int l,int r)
{
	int t=__lg(r-l+1);
	return cmp(st[l][t],st[r-(1<<t)+1][t]);
}
int solve(int l,int r)
{
	if (l==r)
	{
		for (int i=1;i<=m;i++)
			dp[l][i]=i;
		return l;
	}
	if (l>r) return 0;
	int mid=query(l,r);
	int ls=solve(l,mid-1);
	int rs=solve(mid+1,r);
	for (int i=1;i<=m;i++)
	{
		dp[mid][i]=dp[ls][i-1]*dp[rs][i]%mod;
		dp[mid][i]=(dp[mid][i]+dp[mid][i-1])%mod;
	}
	return mid;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) dp[i]=poly(m+1,0);
	dp[0]=poly(m+1,1);
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		st[i][0]=i;
	for (int j=1;j<=18;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=cmp(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int rt=solve(1,n);
	cout<<dp[rt][m]<<'\n';
	for (int i=1;i<=n;i++) poly().swap(dp[i]);
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}