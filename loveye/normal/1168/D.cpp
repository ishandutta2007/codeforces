#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1.5e5+5;
int n,q;
int fa[N],up[N],ups[N];
char c[N];
int cnt[N][26],dp[N][26],dep[N],h[N],sum[N],bad;
vector<int> G[N],cpr[N];
void dfs(int u) {
	if(u!=1&&c[u]!='?') ++cnt[ups[u]][c[u]-'a'];
	if(G[u].size()!=1) cpr[up[u]].push_back(u);
	for(auto v:G[u]) {
		if(u==1||G[u].size()>1) up[v]=u,ups[v]=v;
		else up[v]=up[u],ups[v]=ups[u];
		dfs(v);
		if(!h[u]) h[u]=h[v]+1;
		else if(h[u]!=h[v]+1) {
			while(q--) cout<<"Fou\n";
			exit(0);
		}
		fo(i,0,26) dp[u][i]=max(dp[u][i],dp[v][i]+(c[v]-'a'==i));
	}
	fo(i,0,26) sum[u]+=dp[u][i];
	bad+=sum[u]>h[u];
}
void update(int u,int id) {
	bad-=sum[u]>h[u]; sum[u]-=dp[u][id];
	dp[u][id]=0;
	for(auto v:cpr[u]) dp[u][id]=max(dp[u][id],dp[v][id]+cnt[ups[v]][id]);
	sum[u]+=dp[u][id]; bad+=sum[u]>h[u];
	if(u!=1) update(up[u],id);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	fr(i,2,n) {
		cin>>fa[i]>>c[i];
		G[fa[i]].push_back(i);
	}
	dfs(1);
	while(q--) {
		static int u; static char ch;
		cin>>u>>ch;
		if(c[u]!='?') {
			--cnt[ups[u]][c[u]-'a'];
			update(up[u],c[u]-'a');
		}
		c[u]=ch;
		if(c[u]!='?') {
			++cnt[ups[u]][c[u]-'a'];
			update(up[u],c[u]-'a');
		}
		if(bad) cout<<"Fou\n";
		else {
			ll ans=0;
			fo(i,0,26) ans+=1ll*(i+1)*(h[1]-sum[1]+dp[1][i]);
			cout<<"Shi "<<ans<<'\n';
		}
		cout.flush();
	}
	return 0;
}