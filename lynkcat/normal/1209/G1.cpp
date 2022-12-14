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
#define N 200005 
using namespace std;
int n,q,a[N],l[N],r[N],mx[N];
int ans;
int cnt[N];
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (!l[a[i]]) l[a[i]]=i;
		r[a[i]]=i;
	}
	for (int i=1;i<=n;i++) mx[l[a[i]]]=max(mx[l[a[i]]],r[a[i]]);
	for (int i=1;i<=n;i++) mx[i]=max(mx[i-1],mx[i]);
	int now=1;
	while (now<=n)
	{
		int r=mx[now];
		while (mx[r]>r)
		{
			r=mx[r];
		}
		int o=0;
		for (int i=now;i<=r;i++)
			cnt[a[i]]++,o=max(o,cnt[a[i]]);
		ans+=(r-now+1)-o;
		for (int i=now;i<=r;i++) cnt[a[i]]--;
		now=r+1;
	}
	cout<<ans<<'\n';
			
	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}