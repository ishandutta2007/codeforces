#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007
#define ll long long
#define pb push_back
const ll lim=1e15;
int n,m,a[N],pw[N],s[N],fa[N],mx[N];ll w[N],w1[N],ans[N];bool tg[N];
struct Query {int id,l;};vector<Query> vc[N];
ll add(ll x,ll y) {x+=y;return x<MOD?x:x-MOD;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
void merge(int u,int v) {u=findRt(u);v=findRt(v);if(u!=v) fa[u]=v,mx[v]=mx[u];}
void ins(int x)
{
	int t,t1;w[x]=a[x];
	while(1)
	{
		t=findRt(x);t1=findRt(t-1);if(t<2 || (!tg[t] && w[t]<=0)) break;
		if(tg[t] || t-t1>60 || w[t]>(lim-w[t1]>>t-t1))
			tg[t1]=1,w[t1]=(w[t1]+w[t]%MOD*pw[t-t1])%MOD;
		else w[t1]+=w[t]<<t-t1;merge(t,t1);
	}t=findRt(x);t1=findRt(t-1);w1[t]=(w1[t1]+w[t])%MOD;
}
ll qry(int l,int r)
{
	if(l==r) return add(a[l],MOD);int t=findRt(l+1);
	ll res=w1[findRt(r)]-w1[t]+s[l+1]-1ll*s[mx[t]+1]*pw[mx[t]-l];
	res=res*2+a[l];return add(res%MOD,MOD);
}
int main()
{
	scanf("%d %d",&n,&m);pw[0]=1;for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,l,r;i<=m;++i) scanf("%d %d",&l,&r),vc[r].pb((Query) {i,l});
	for(int i=1;i<=n;++i) fa[i]=mx[i]=i,pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=n;i;--i) s[i]=add(add(s[i+1],s[i+1]),add(a[i],MOD)); 
	for(int i=1;i<=n;++i) {ins(i);for(auto j:vc[i]) ans[j.id]=qry(j.l,i);}
	for(int i=1;i<=m;++i) printf("%lld\n",ans[i]);return 0;
}