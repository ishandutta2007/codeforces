// Problem: E. Bracket Cost
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/E
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
#define N 800005
using namespace std;
int ans,tr[N],tr1[N],a[N],s[N];
int n;
int p[N];
void upd(int x,int y)
{
	x++;
	while (x<=4*n+1)
	{
		tr[x]+=y;
		x+=x&-x;
	}
}
int query(int x)
{
	x++;
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void upd1(int x,int y)
{
	x++;
	while (x<=4*n+1)
	{
		tr1[x]+=y;
		x+=x&-x;
	}
}
int query1(int x)
{
	x++;
	int res=0;
	while (x)
	{
		res+=tr1[x];
		x-=x&-x;
	}
	return res;
}
void solve(int l,int r)
{
	if (l+1==r)
	{
		return;
	}
	int mid=(l+r)/2;
	int x=mid-1;
	int mn=n;
	for (int i=mid;i<r;i++)
	{
		mn=min(mn,a[i]);
		while (x>=l&&a[x]>mn)
		{
			upd(a[x],1);
			upd1(a[x],a[x]);
			x--;
		}
		ans+=query(a[i])*(a[i]-mn);
		ans+=query1(4*n)-query1(a[i])-(query(4*n)-query(a[i]))*mn;
	}
	while (x+1<=mid-1)
	{
		x++;
		upd(a[x],-1);
		upd1(a[x],-a[x]);
	}
	x=mid;
	mn=n;
	for (int i=mid-1;i>=l;i--)
	{
		mn=min(mn,a[i]);
		while (x<r&&a[x]>=mn)
		{
			upd(a[x],1);
			upd1(a[x],a[x]);
			x++;
		}
		ans+=query(a[i])*(a[i]-mn);
		ans+=query1(4*n)-query1(a[i])-(query(4*n)-query(a[i]))*mn;
	}
	while (x-1>=mid)
	{
		x--;
		upd(a[x],-1);
		upd1(a[x],-a[x]);
	}
	solve(l,mid);
	solve(mid,r);
}
void BellaKira()
{
	ans=0;
	cin>>n;
	poly g;
	int mn=0;
	a[0]=0;
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if (ch=='(') a[i]=1;
		else a[i]=-1;
		a[i]+=a[i-1];
		mn=min(mn,a[i]);
	}
	for (int i=0;i<=n;i++) a[i]-=mn;
	a[n+1]=a[n];
	solve(0,n+1);
	cout<<ans<<endl;
	
			
			
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}