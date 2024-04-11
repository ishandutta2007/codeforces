#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
int n,m,a[N],p[N],b[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y)
	{
		return a[x]<a[y];
	});
	int mn=inf,mn1=inf,mx=0;
	int ans=0;
	for (int i=1;i<m;i++)
	{
		a[p[i]]=inf;
	}
	for (int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	mn=b[1]*2,mn1=b[2]*2;
	for (int i=1;i<n;i++) mx=max(mx,min(a[i],a[i+1]));
	for (int i=1;i<=n;i++)
	{
		int nw=mx;
		if (i>1) nw=max(nw,a[i-1]);
		if (i<n) nw=max(nw,a[i+1]);
		if (b[1]==a[i])
			ans=max(ans,min(nw,mn1));
		else ans=max(ans,min(nw,mn));
	}
	cout<<ans<<'\n';
		
	
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