// Lynkcat.
// Problem: F. Shifting String
// URL: https://codeforces.com/contest/1690/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define N 2005
using namespace std;
int n;
string st;
int p[N];
int vis[N];
int tim;
void BellaKira()
{
	cin>>n;
	cin>>st;
	st=' '+st;
	for (int i=1;i<=n;i++) cin>>p[i];
	++tim;
	int ans=1;
	for (int i=1;i<=n;i++)
		if (vis[i]!=tim)
		{
			int now=i;
			deque<char>g;
			poly G;
			while (vis[now]!=tim)
			{
				vis[now]=tim;
				g.push_back(st[now]);
				G.push_back(now);
				now=p[now];
			}
			int res=1;
			for (auto u:g) if (u==g.front()) res&=1; else res&=0;
			if (res) continue;
			int bd=0;
			for (int j=0;j<g.size();j++)
			{
				int now=g.back();
				g.pop_back();
				g.push_front(now);
				deque<char>g1;
				g1=g;
				bool nowbl=1;
				for (auto u:G)
				{
					if (st[u]!=g.front()) nowbl=0;
					g.pop_front();
				}
				if (nowbl)
				{
					bd=j+1;
					break;
				}
				g=g1;
			}
			// cout<<"?"<<bd<<endl;
			ans=ans/__gcd(ans,bd)*bd;
			
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