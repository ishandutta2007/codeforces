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
#define N 1000005
using namespace std;
int tot;
int fa[N];
int a[N],p[N];
int n;
int ans;
void BellaKira()
{
	ans=0;
	tot=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		p[x]=i;
		a[i]=x;
	}
	int l=p[0],r=p[0];
	for (int i=0;i<n;i++)
	{
		l=min(l,p[i]);
		r=max(r,p[i]);
		int x=2*i+1;
		if (r-l+1>x) continue;
		int L=r-x+1,R=l;
		L=max(L,1ll);
		R=min(R,n-x+1);
		if (L<=R) ans+=R-L+1;
	}
	l=p[0],r=p[0];
	for (int i=0;i<n;i++)
	{
		l=min(l,p[i]);
		r=max(r,p[i]);
		int x=2*(i+1);
		if (r-l+1>x) continue;
		int L=r-x+1,R=l;
		L=max(L,1ll);
		R=min(R,n-x+1);
		if (L<=R) ans+=R-L+1;
	}
	cout<<ans<<'\n';
}
signed main()
{
	// freopen("guitar.in","r",stdin);
	// freopen("guitar.out","w",stdout);
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}