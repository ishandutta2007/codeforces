// Lynkcat.
// Problem: B. Mystic Permutation
// URL: https://codeforces.com/contest/1689/problem/B
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
#define N 20005
using namespace std;
int n,a[N],p[N],vis[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=i;
		vis[i]=0;
	}
	if (n==1) return cout<<-1<<endl,void();
	for (int i=1;i<=n-2;i++)
		for (int j=1;j<=n;j++)
			if (!vis[j]&&a[i]!=j)
			{
				vis[j]=1;
				p[i]=j;
				break;
			}
	poly g;
	for (int i=1;i<=n;i++)
		if (!vis[i]) g.push_back(i);
	// cout<<"?"<<g.size()<<endl;
	if (a[n-1]==g[0]||a[n]==g[1])
	{
		p[n-1]=g[1],p[n]=g[0];
	} else 
		p[n-1]=g[0],p[n]=g[1];
	for (int i=1;i<=n;i++) cout<<p[i]<<" ";
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