// Lynkcat.
// Problem: G. Trader Problem
// URL: https://codeforces.com/contest/1618/problem/G
// Memory Limit: 512 MB
// Time Limit: 4500 ms
// -----------------------------------------------

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
//#define N
using namespace std;
pair <int,int> w[500005],b[500005];
int a[500005],qzh[500005],c[500005];
int fa[500005],sz[500005],ans,out[500005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
inline void mer(int x,int y)
{
	x=ff(x),y=ff(y);
	if(x==y) return;
	if(x>y) swap(x,y);
	ans-=qzh[y]-qzh[y-sz[y]];
	ans-=qzh[x]-qzh[x-sz[x]];
	sz[y]+=sz[x],fa[x]=y;
	ans+=qzh[y]-qzh[y-sz[y]];
}
signed main() 
{
	IOS;
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ans+=a[i]=c[i];
	}
	for(int i=1;i<=m;i++) cin>>a[i+n];
	sort(a+1,a+n+m+1);
	sort(c+1,c+n+1);
	int now=0;
	for(int i=1;i<=n;i++)
	{
		while(now<n+m&&a[now+1]<=c[i]) ++now;
		if(a[now]==c[i]) ++sz[now];
	}
	for(int i=1;i<=n+m;i++)
	{
		qzh[i]=a[i]+qzh[i-1],fa[i]=i;
		w[i]={a[i+1]-a[i],i};
	}
	sort(w+1,w+n+m);
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(b+1,b+q+1),now=1;
	for(int i=1;i<=q;i++)
	{
		while(now<n+m&&w[now].first<=b[i].first)
			mer(w[now].second,w[now].second+1),now++;
		out[b[i].second]=ans;
	}
	for(int i=1;i<=q;i++) cout<<out[i]<<endl;
	return 0;
}