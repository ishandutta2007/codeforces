// LUOGU_RID: 91402309
// Problem: E. N Machines
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1753/E
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
#define int ll
// #define N 
using namespace std;
struct node
{
	int x;
	poly sum,G;
	node()
	{
		x=0,G=sum=poly();
	}
};
vector<node>all;
int Sum,ans;
int sum[105];
int vis[105];
int n,b,p,m;
int f[105];
int allsum;
map<int,int>Mp;
int calc(int x)
{
	allsum=0;
	int res=0;
	int nw=1;
	for (int i=0;i<all.size();i++)
	{
		if (vis[i])
			nw=nw*all[i].x;
		if (i==0) continue;
		poly &G=all[i].G;
		int l=0,r=(int)G.size()-1;
		// cout<<"s"<<" "<<l<<" "<<r<<" "<<f[i+1]<<" "<<nw<<" "<<" "<<G.size()<<endl;
		int pos=-1;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if ((f[0]-f[i+1]*nw)*G[mid]>=x) 
			{
				pos=mid;
				l=mid+1;
			} else r=mid-1;
		}
		// cout<<i<<" "<<pos<<endl;
		// cout<<"t"<<endl;
		res+=pos+1;
		if (pos+1)
			allsum+=(f[0]-f[i+1]*nw)*all[i].sum[pos];
	}
	return res;
}
void dfs(int k,int tot)
{
	if (k==all.size())
	{
		int res=(b-tot*m)/p;
		if (b-tot*m<0) return;
		int l=0,r=4e18;
		int o=0;
		Sum=0;
		int nw=1;
		for (int i=0;i<all.size();i++)
		{
			if (vis[i]) nw*=all[i].x;
			Sum+=sum[i]*f[i+1]*nw;
		}
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (calc(mid)>=res)
			{
				o=mid;
				l=mid+1;
			} else
			{
				r=mid-1;
			}
		}
		int lst=calc(o);
		ans=max(ans,allsum-(lst-res)*o+Sum);
		return;
	}
	if (Mp[all[k].x]||k==0) vis[k]=0,dfs(k+1,tot);
	else
	{
		vis[k]=0;
		Mp[all[k].x]++;
		dfs(k+1,tot);
		Mp[all[k].x]--;
		vis[k]=1;
		dfs(k+1,tot+1);
		// vis[k]=0;
	}
}
void BellaKira()
{
	cin>>n>>b>>p>>m;
	all.push_back(node());
	all.back().x=1;
	all.back().G.push_back(1);
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		if (st=="*") 
		{
			int x;
			cin>>x;
			if (x==1) continue;
			all.push_back(node());
			all.back().x=x;
		} else
		{
			int x;
			cin>>x;
			all.back().G.push_back(x);
		}	
	}
	for (int i=0;i<all.size();i++)
	{
		// cout<<all[i].x<<": ";
		sort(all[i].G.begin(),all[i].G.end(),greater<int>());
		all[i].sum=all[i].G;
		for (int j=1;j<all[i].G.size();j++)
			all[i].sum[j]+=all[i].sum[j-1];
		for (auto u:all[i].G) sum[i]+=u;
		// for (auto u:all[i].G) cout<<u<<" ";
		// cout<<'\n';
	}
	f[all.size()]=1;
	for (int i=(int)all.size()-1;i>=0;i--)
		f[i]=f[i+1]*all[i].x;
	dfs(0,0);
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