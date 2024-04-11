// Lynkcat.
// Problem: G. MinOr Tree
// URL: https://codeforces.com/contest/1624/problem/G
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
#define N 2000005
using namespace std;
struct 
{
	int x,y,w;
}E[N<<1];
int fa[N];
int n,m;
int tot;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	fa[x]=y;
	tot++;
}
void BellaKira()
{
	int ans=0;
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>E[i].x>>E[i].y>>E[i].w;
	}
	for (int j=30;j>=0;j--)
	{
		for (int i=1;i<=n;i++) fa[i]=i;
		tot=0;
		for (int i=1;i<=m;i++)
			if ((E[i].w>>j)%2==0&&(((E[i].w|ans)>>j)==(ans>>j))) merge(E[i].x,E[i].y);
		if (tot!=n-1) ans+=(1<<j);
	}
	cout<<ans<<endl;
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