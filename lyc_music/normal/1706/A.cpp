// Lynkcat.
// Problem: A. Another String Minimization Problem
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/A
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
#define N 55
using namespace std;
int n,m,a[N],vis[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) vis[i]=0;
	for (int i=1;i<=n;i++)
	{
		int x=a[i],y=m-a[i]+1;
		if (x>y) swap(x,y);
		if (!vis[x]) vis[x]=1;
		else vis[y]=1;
	}
	for (int i=1;i<=m;i++)if (vis[i]) cout<<'A';
	else  cout<<'B';
	cout<<endl;
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