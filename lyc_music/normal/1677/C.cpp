// Lynkcat.
// Problem: C. Tokitsukaze and Two Colorful Tapes
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N  100005
using namespace std;
int n,a[N],b[N];
poly W[N];
int vis[N];
int ans;
poly G[N];
int ansp[N];
bool cmp(int x,int y)
{
	return W[x].size()>W[y].size();
}
void ad(int x,int y)
{
	G[x].push_back(y);
	G[y].push_back(x);
}
void BellaKira()
{
	ans=0;
	poly P;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i])
			ad(a[i],b[i]);
	int tot=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			int now=i;
			poly g;
			while (!vis[now])
			{
				g.push_back(now);
				vis[now]=1;
				for (auto u:G[now])
					if (!vis[u])
					{
						now=u;
						break;
					}
			}
			P.push_back(i);
			W[i]=g;
		}
	int l=1,r=n;
	sort(P.begin(),P.end(),cmp);
	for (auto u:P)
	{
		// cout<<u<<" "<<ans<<" "<<W[u].size()<<endl;
		if (W[u].size()%2==1)
		{
			int lst=0;
			for (int i=0;i<=(int)W[u].size()-i-1;i++)
			{
				int nxt=(int)W[u].size()-i-1;
				if (i==nxt)
				{
					ansp[W[u][i]]=l;
					if (lst)
						ans+=abs(lst-l)+abs(l-ansp[W[u][0]]);
				} else
				{
					ansp[W[u][i]]=l;
					if (lst)	ans+=abs(lst-l);
					lst=l;
					l++;
					ansp[W[u][nxt]]=r;
					if (lst) ans+=abs(lst-r);
					lst=r;
					r--;
				}
			}
		} else
		{
			int lst=0;
			for (int i=0;i<=(int)W[u].size()-i-1;i++)
			{
				int nxt=(int)W[u].size()-i-1;
				if (i==nxt-1)
				{
					ansp[W[u][i]]=l;
					if (lst)	ans+=abs(lst-l);
					lst=l;
					l++;
					ansp[W[u][nxt]]=r;
					if (lst) ans+=abs(lst-r);
					ans+=abs(r-ansp[W[u][0]]);
					lst=r;
					r--;
				} else
				{
					ansp[W[u][i]]=l;
					if (lst)	ans+=abs(lst-l);
					lst=l;
					l++;
					ansp[W[u][nxt]]=r;
					if (lst) ans+=abs(lst-r);
					lst=r;
					r--;
				}
			}
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) vis[i]=0,W[i].clear(),G[i].clear();
			
					
				
				
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