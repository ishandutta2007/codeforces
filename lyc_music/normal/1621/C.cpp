// Lynkcat.
// Problem: C. Hidden Permutations
// URL: https://codeforces.com/contest/1621/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define int ll
//#define N
using namespace std;
int n,a[100005];
int vis[100005];
int qry(int x)
{
	cout<<"? "<<x<<endl;
	int res;
	cin>>res;
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			int x=qry(i);
			poly g;
			while (!vis[x])
			{
				vis[x]=1;
				g.push_back(x);
				x=qry(i);
			}
			for (int j=0;j<g.size();j++)
				a[g[j]]=g[(j+1)%g.size()];
		}
				
				
	cout<<"! ";
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
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