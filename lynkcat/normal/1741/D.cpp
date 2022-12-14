// Lynkcat.
// Problem: D. Masha and a Beautiful Tree
// Contest: Codeforces - Codeforces Round #826 (Div. 3)
// URL: https://codeforces.com/contest/1741/problem/D
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
#define inf 1e9
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
int n,a[N],p[N];
int ans;
void work(int l,int r)
{
	// cout<<l<<" "<<r<<endl;
	if (l==r)
	{
		if (p[l]!=l)
		{
			ans==-1;
		}
		return;
	}
	if (ans==-1) return;
	int mid=l+(r-l)/2;
	int x=0,y=0;
	for (int i=l;i<=r;i++) a[i]=p[i];
	sort(a+l,a+mid+1);
	sort(a+mid+1,a+r+1);
	for (int i=l;i<=r;i++)
		if (a[i]==i) x++;
	if (x==r-l+1)
	{
		work(l,mid);
		work(mid+1,r);
	}else
	{
		for (int i=l;i<=mid;i++)
			y+=(a[i]==(mid+1+i-l));
		for (int i=mid+1;i<=r;i++)
			y+=(a[i]==(l+i-mid-1));
		if (y==r-l+1) 
		{
			ans++;
			for (int i=l;i<=mid;i++)
				swap(p[i],p[mid+i-l+1]);
			work(l,mid);
			work(mid+1,r);
		} else ans=-1;
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i];
	ans=0;
	work(1,n);
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