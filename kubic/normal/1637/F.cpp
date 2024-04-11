#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
#define pb push_back
int n,mx,a[N],L[N],R[N],mx1[N],mx2[N],mx3[N];
ll ans=1e18,vl[N];vector<int> e[N];
void dfs1(int u,int f)
{
	L[u]=++L[0];mx1[u]=a[u];
	for(auto v:e[u]) if(v!=f)
	{
		dfs1(v,u);
		if(mx1[v]>mx1[u]) mx2[u]=mx1[u],mx1[u]=mx1[v];
		else if(mx1[v]>mx2[u]) mx2[u]=mx1[v];
	}R[u]=L[0];
}
void dfs2(int u,int f)
{
	for(auto v:e[u]) if(v!=f)
		mx3[v]=max(mx3[u],(mx1[u]==mx1[v]?mx2[u]:mx1[u])),dfs2(v,u);
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),mx=max(mx,a[i]);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs1(1,0);dfs2(1,0);
	for(int i=1,w1,w2,w;i<=n;++i)
	{
		w1=w2=0;
		for(auto j:e[i]) if(L[i]<L[j])
		{if(mx1[j]>w1) w2=w1,w1=mx1[j];else if(mx1[j]>w2) w2=mx1[j];}
		if(mx3[i]>w1) w2=w1,w1=mx3[i];else if(mx3[i]>w2) w2=mx3[i];
		for(auto j:e[i]) if(L[i]<L[j])
			w=max(a[i]-(w1==mx1[j]?w2:w1),0),vl[L[j]]+=w,vl[R[j]+1]-=w;
		w=max(a[i]-(w1==mx3[i]?w2:w1),0);vl[1]+=w;vl[L[i]]-=w;vl[R[i]+1]+=w;
		w=max(a[i]-w1,0);vl[L[i]]+=w;vl[L[i]+1]-=w;
	}for(int i=1;i<=n;++i) vl[i]+=vl[i-1],ans=min(ans,vl[i]+mx);
	printf("%lld\n",ans);return 0;
}