#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=3e5+5;
int n,a[N];
int fir[N],to[N<<1],eds,nxt[N<<1],wei[N<<1];
void addedge(int u,int v,int w) {
	to[++eds]=v;
	wei[eds]=w;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
ll ans,dp[N];
void dfs(int u,int fa) {
	dp[u]=a[u];
	foredge(i,u,v) if(v!=fa) {
		dfs(v,u);
		ans=max(ans,dp[u]+dp[v]-wei[i]);
		dp[u]=max(dp[u],dp[v]-wei[i]+a[u]);
	}
}
int main() {
	n=read();
	fr(i,1,n) a[i]=read(),ans=max(ans,0ll+a[i]);
	for(int i=1,u,v,w;i<n;++i) {
		u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}