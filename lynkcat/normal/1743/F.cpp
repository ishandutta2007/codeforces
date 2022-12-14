// Problem: F. Intersection and Union
// Contest: Codeforces - Educational Codeforces Round 137 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1743/problem/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms

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
#define N 300005
using namespace std;
int tr[N<<2][2][2];
int lf[N<<2];
poly G[N];
int n;
int l[N],r[N];
void pushup(int k)
{
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			tr[k][i][j]=0;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int x=0;x<2;x++)
				tr[k][i][j]=(tr[k][i][j]+tr[k<<1][i][x]*tr[k<<1|1][x^lf[k<<1|1]][j]%mod)%mod;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int x=0;x<2;x++)
				tr[k][i][j]=(tr[k][i][j]+tr[k<<1][i][x]*tr[k<<1|1][x|lf[k<<1|1]][j]%mod)%mod;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int x=0;x<2;x++)
				tr[k][i][j]=(tr[k][i][j]+tr[k<<1][i][x]*tr[k<<1|1][x&lf[k<<1|1]][j]%mod)%mod;
	lf[k]=lf[k<<1];
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k][0][0]=tr[k][1][1]=1;
		lf[k]=0;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}	
void flip(int k,int l,int r,int x)
{
	if (l==r)
	{
		lf[k]^=1;
		return;
	}
	int mid=l+(r-l)/2;
	if (x<=mid) flip(k<<1,l,mid,x);
	else flip(k<<1|1,mid+1,r,x);
	pushup(k);
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		G[l[i]].push_back(i);
		G[r[i]+1].push_back(i);
	}
	build(1,1,n);
	int ans=0;
	for (int i=0;i<=300000;i++)
	{
		for (auto u:G[i])
		{
			flip(1,1,n,u);
		}
		ans=(ans+tr[1][lf[1]][1])%mod;
		// if (tr[1][lf[1]][1]) cout<<i<<" "<<tr[1][lf[1]][1]<<endl;
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}