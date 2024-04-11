#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=3005;
int n;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}

ll dp[N][N],val[N][N];
int dis[N][N],siz[N];
void dfs(int u,int fa,int rt) {
	siz[u]=1;
	foredge(i,u,v) if(v != fa) {
		dis[rt][v]=dis[rt][u]+1;
		dfs(v,u,rt);
		siz[u]+=siz[v];
	}
}
void dfs2(int u,int fa,int rt,int res) {
	//cerr<<u<<' '<<fa<<endl;
	val[rt][u]=1ll*res*siz[u];
	foredge(i,u,v) if(v!=fa) dfs2(v,u,rt,res);
}
typedef pair<int,int> pii;
#define fi first 
#define se second
pii a[N*N]; int tot;

int main() {
	cin>>n;
	for(int i=1,u,v;i<n;++i) {
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	fr(i,1,n) fr(j,i+1,n) a[++tot]=make_pair(i,j);
	fr(i,1,n) {
		dfs(i,0,i);
		foredge(id,i,j) dfs2(j,i,i,n-siz[j]);
	}
	sort(a+1,a+tot+1,[](const pii &a,const pii &b) {
		return dis[a.fi][a.se]>dis[b.fi][b.se];
	});
	ll ans=0;
	fr(i,1,tot) {
		int u=a[i].fi,v=a[i].se;
		foredge(id,u,w) if(dis[u][v]<dis[w][v])
			dp[u][v]=max(dp[u][v],w<v?dp[w][v]:dp[v][w]);
		foredge(id,v,w) if(dis[u][v]<dis[u][w])
			dp[u][v]=max(dp[u][v],w<u?dp[w][u]:dp[u][w]);
		dp[u][v]+=val[u][v];
		if(dis[u][v]==1) ans=max(ans,dp[u][v]);
	}
	cout<<ans<<endl;
	return 0;
}