// Lynkcat.
// Problem: E. Count Seconds
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
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
#define N 1005
using namespace std;
int n,m,a[N],b[N],ru[N];
poly G[N],G1[N];
bool chk()
{
	bool res=1;
	for (int i=1;i<=n;i++)
		if (a[i]) return 0;
		return 1;
}
void work()
{
	for (int i=1;i<=n;i++)
		if (a[i]>0)
		{
			a[i]--;
			for (auto u:G[i])
			{
				b[u]++;
			}
		}
	for (int i=1;i<=n;i++) a[i]+=b[i],b[i]=0;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G1[y].push_back(x);
		ru[x]++;
	}
	int ans=0;
	for (int i=1;i<=1000;i++)
	{
		if (chk())
		{
			break;
		}
		ans++;
		work();
	}
	if (ans!=1000) cout<<ans<<endl;
	else
	{
		queue<int>q;
		for (int i=1;i<=n;i++)
			if (!ru[i]) q.push(i),b[i]=1;
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			// cout<<"!"<<u<<endl;
			for (auto v:G1[u])
			{
				ru[v]--;
				b[v]=(b[v]+b[u])%mod;
				if (!ru[v]) q.push(v);
				
			}
		}
		for (int i=1;i<=n;i++)
			ans=(ans+a[i]*b[i]%mod)%mod,b[i]=0;
		cout<<ans<<endl;
	}
	for (int i=1;i<=n;i++) G[i].clear(),ru[i]=0,G1[i].clear();
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