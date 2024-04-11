// Problem: F. Kazaee
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.ml/contest/1746/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms124

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
#define mod 1000000007
#define int ll
#define N 600005
using namespace std;
mt19937_64 rnd(time(0));
int n,m,a[N],opt[N],l[N],r[N],id[N];
int tr[N];
int Val[N];
int c[N];
int ans[N];
void upd(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=x&-x;
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	poly g;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		g.push_back(a[i]);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>opt[i]>>l[i]>>r[i];
		if (opt[i]==2) cin>>id[i];
		else
		{
			g.push_back(r[i]);
		}
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	for (int i=1;i<=n;i++)	a[i]=lower_bound(g.begin(),g.end(),a[i])-g.begin()+1,c[i]=a[i];
	for (int i=1;i<=m;i++)	
		if (opt[i]==1)
			r[i]=lower_bound(g.begin(),g.end(),r[i])-g.begin()+1;
	for (int i=1;i<=m;i++) ans[i]=1;
	for (int tim=1;tim<=30;tim++)
	{
		for (int i=1;i<=g.size();i++) Val[i]=rnd()%mod;
		for (int i=1;i<=n;i++) a[i]=c[i],upd(i,Val[a[i]]);
		for (int i=1;i<=m;i++)
		{
			if (opt[i]==2)
			{
				int x=query(r[i])-query(l[i]-1);
				// cout<<"?"<<i<<" "<<x<<endl;
				if (x%id[i]) ans[i]=0;
			} else
			{
				upd(l[i],-Val[a[l[i]]]);
				a[l[i]]=r[i];
				upd(l[i],Val[a[l[i]]]);
			}
		}
		for (int i=1;i<=n;i++)  tr[i]=0;
	}
	for (int i=1;i<=m;i++)
		if (opt[i]==2)
		{
			if (ans[i]) cout<<"YES\n";
			else cout<<"NO\n";
		}
			
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