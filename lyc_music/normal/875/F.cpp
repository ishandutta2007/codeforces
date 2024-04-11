// Lynkcat.
// Problem: CF875F Royal Questions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF875F
// Memory Limit: 500 MB
// Time Limit: 1500 ms

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

int n,m,fa[N],f[N];
int ans;
struct node
{
	int x,y,z;
}a[N];
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) fa[i]=i,f[i]=0;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+m+1,[&](node x,node y)
	{
		return x.z>y.z;
	});
	for (int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		if (gf(x)==gf(y)&&f[gf(x)]==0)
		{
			f[gf(x)]=1;
			ans+=a[i].z;
		} else
		if (gf(x)!=gf(y)&&(f[gf(x)]+f[gf(y)]!=2))
		{
			f[gf(x)]|=f[gf(y)];
			fa[gf(y)]=gf(x);
			ans+=a[i].z;
		}
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