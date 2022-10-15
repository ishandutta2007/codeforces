// Lynkcat.
// Problem: CF1616E Lexicographically Small Enough
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1616E
// Memory Limit: 250 MB
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
#define N  200005
using namespace std;
int n;
string st,st1;
poly G[105];
int vis[N],tr[N];
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
	cin>>n>>st>>st1;
	st=' '+st;
	st1=' '+st1;
	for (int i=1;i<=n;i++)
	{
		G[st[i]-'a'+1].push_back(i);
	}
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=26;i++) reverse(G[i].begin(),G[i].end());
	int ans=inf,nowsm=0;
	for (int i=1,ii=1;i<=n;i++)
	{
		while (ii<=n&&vis[ii]) ii++;
		int now=st1[i]-'a'+1;
		for (int j=1;j<now;j++)
		{
			if (G[j].size())
				ans=min(ans,nowsm+qry(G[j].back())+G[j].back()-ii-qry(ii));
		}
		if (!G[now].size()) break;
		int v=G[now].back();
		nowsm+=v+qry(v)-ii-qry(ii);
		vis[v]=1;
		upd(ii,1);
		upd(v,-1);
		G[now].pop_back();
	}
	for (int i=1;i<=n;i++) tr[i]=0;
	for (int i=1;i<=26;i++) G[i].clear();
	if (ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	
		
		
		
			
	
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