// Lynkcat.
// Problem: D. Vertical Paths
// URL: https://codeforces.com/contest/1675/problem/D
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
#define N 200005
using namespace std;
int n,a[N],vis[N],ru[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],vis[i]=0,ru[i]=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=i)
		ru[a[i]]++;
	vector<poly>ans;
	for (int i=1;i<=n;i++)
		if (!ru[i])
		{
			poly g;
			int now=i;
			while (!vis[now])
			{
				g.push_back(now);
				vis[now]=1;
				now=a[now];
			}
			reverse(g.begin(),g.end());
			ans.push_back(g);
		}
	cout<<ans.size()<<endl;
	for (auto u:ans)
	{
		cout<<u.size()<<endl;
		for (auto v:u) cout<<v<<" ";
		cout<<endl;
	}
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}