// Lynkcat.
// Problem: CF1693E Outermost Maximums
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1693E
// Memory Limit: 250 MB
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
#define N 200005
using namespace std;
int n,a[N];
poly g[N];
int tr[N];
int ans;
void upd(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=x&-x;
	}
}
int qry(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	int l=1,r=n;
	for (int i=n;i>=1;i--)
	{
		if (g[i].size())
		{
			int nl=min(g[i][0],r+1),nr=max(g[i].back(),l-1);
			l=nl,r=nr;
			for (auto u:g[i])
				upd(u,1);
			ans+=qry(r)-qry(l-1);
		}
	}
	cout<<ans<<endl;
		
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}