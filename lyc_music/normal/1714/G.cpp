// Lynkcat.
// Problem: G. Path Prefixes
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
int n,st[N][20];
int fa[N],fb[N],dep[N];
poly G[N];
int ans[N];
int ffa[N],A[N],B[N];
void dfs(int i)
{
	int x=ffa[i],a=A[i],b=B[i];
		fa[i]=fa[x]+a;
		fb[i]=fb[x]+b;
		st[i][0]=x;
		dep[i]=dep[x]+1;
		for (int j=1;j<=18;j++)
			st[i][j]=(st[st[i][j-1]][j-1]);
		if (fb[i]<=fa[i]) ans[i]=dep[i];
		else
		{
			int o=0;
			int nw=i;
			for (int j=18;j>=0;j--)
				if (fb[st[nw][j]]>fa[i]) nw=st[nw][j],o+=(1<<j);
			o++;
			ans[i]=dep[i]-o;
		}
	for (auto u:G[i]) dfs(u);
	G[i].clear();
}
void BellaKira()
{
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		cin>>ffa[i]>>A[i]>>B[i];
		G[ffa[i]].push_back(i);
	}
	dfs(1);
	for (int i=2;i<=n;i++) cout<<ans[i]-1<<' ';
	cout<<'\n';
		
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