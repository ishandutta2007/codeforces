#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3e5+5;
int n,k;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int h[N],son[N];
void dfs(int u,int fa) {
	foredge(i,u,v) if(v!=fa) {
		dfs(v,u);
		if(h[v]>h[son[u]]) son[u]=v;
	}
	h[u]=h[son[u]]+1;
}
int a[N],tot;
signed main() {
	cin>>n>>k;
	for(int i=1,u,v;i<n;++i) {
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	fr(u,1,n) foredge(i,u,v) if(h[v]<h[u]&&v!=son[u]) a[++tot]=h[v];
	a[++tot]=h[1];
	if(k>=tot) {
		k=max(tot,min(k,n/2));
		cout<<1ll*k*(n-k)<<endl;
		return 0;
	}
	sort(a+1,a+tot+1,greater<int>());
	int rw=0;
	ll ans=-1ll*(n/2)*(n-n/2);
	fr(i,1,k) {
		rw+=a[i];
		ll r=i,w=rw-i,b=n-rw;
		if(r>=b) ans=max(ans,w*(r-b));
		else if(b>=n+1>>1) ans=max(ans,(n-r-n/2)*(r-n/2));
		else ans=max(ans,w*(r-b));
	}
	cout<<ans<<endl;
	return 0;
}