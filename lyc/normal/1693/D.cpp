// Lynkcat.
// Problem: D. Decinc Dividing
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/D
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
#define N 200005
using namespace std;
int n,a[N];
int f[2],g[2];
map<pa,int>Mp[N];
int ans;
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		ans++;
		f[0]=inf,f[1]=-inf;
		int l=i;
		int sm=0;
		vector<pa>G;
		for (int j=i+1;j<=n;j++)
		{
			g[0]=-inf;g[1]=inf;
			if (a[j]>a[j-1]&&g[0]<f[0]) g[0]=f[0];
			if (a[j]<a[j-1]&&g[1]>f[1]) g[1]=f[1];
			if (a[j]>f[1]&&g[0]<a[j-1]) g[0]=a[j-1];
			if (a[j]<f[0]&&g[1]>a[j-1]) g[1]=a[j-1];
			f[0]=g[0],f[1]=g[1];
			if (Mp[j].count(mp(f[0],f[1]))) 
			{
				sm=Mp[j][mp(f[0],f[1])];
				ans+=sm;
				l=j-1;
				break;
			}
			if (f[0]!=-inf||f[1]!=inf)
			{
				G.push_back(mp(f[0],f[1]));
				l=j;
				ans++;
			} else
			{
				l=j-1;
				break;
			}
		}
		reverse(G.begin(),G.end());
		for (int j=0;j<G.size();j++)
		{
			Mp[l-j][mp(G[j].fi,G[j].se)]=j+sm+1;
		}
		// cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}