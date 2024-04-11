// Lynkcat.
// Problem: E. Cross Swapping
// Contest: Codeforces - Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/E
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
// #define int ll
#define N 1005
using namespace std;
int n,fa[N],v[N];
int a[N][N];
inline int gf(int x)
{
	if (x==fa[x]) return fa[x];
	int o=fa[x];
	fa[x]=gf(fa[x]);
	v[x]=v[x]^v[o];
	return fa[x];
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) fa[i]=i,v[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int x=a[i][j],y=a[j][i];
			if (x==y) continue;
			int bl=0;
			if (x>y) bl=1;
			gf(i),gf(j);
			if (gf(i)==gf(j)) continue;
			int xx=i,yy=j;
			xx=gf(i),yy=gf(j);
			if  ((v[i]^v[j])!=bl)
			{
				v[yy]=1;
			}
			fa[yy]=xx;
		}
	for (int i=1;i<=n;i++)
	{
		gf(i);
		// cout<<v[i]<<endl;
	}
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if  (v[i]^v[j]) swap(a[i][j],a[j][i]);
		}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<'\n';
	}
	
			
				
		
			
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}