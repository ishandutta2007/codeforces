// Lynkcat.
// Problem: E. Split Into Two Sets
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/E
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
#define N 400005
using namespace std;
int n,a[N],b[N];
int fa[N];
poly g[N];
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
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	for (int i=1;i<=2*n;i++)
		fa[i]=i;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (g[i].size()>2) cnt++;
		else
		{
			if (g[i].size()==2)
			{
				if (gf(g[i][0])==gf(g[i][1])) cnt++;
				merge(g[i][0],g[i][1]+n);
				merge(g[i][0]+n,g[i][1]);
			}
		}
	}
	if (cnt) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
for (int i=1;i<=n;i++) g[i].clear();
	
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