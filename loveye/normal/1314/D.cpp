#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=85;
int n,k;
int G[N][N];
int a[10],vis[N];
int f[N][N][6];
ll ans=9e18;
int getval(int u,int v) {
	fr(o,1,k/2) if(f[u][v][o]&&!vis[f[u][v][o]])
		return G[u][f[u][v][o]]+G[f[u][v][o]][v];
	return 2e9;
}
void chk() {
	ll res=0;
	fr(i,2,k/2) res+=getval(a[i-1],a[i]);
	ans=min(ans,res+getval(a[k/2],a[1]));
}
void dfs(int cur) {
	if(cur==k/2+1) return chk();
	fr(i,1,n) ++vis[i],a[cur]=i,dfs(cur+1),--vis[i];
}
int main() {
	cin>>n>>k;
	fr(i,1,n) fr(j,1,n) cin>>G[i][j];
	fr(i,1,n) fr(j,1,n) fr(p,1,n) if(p!=i&&p!=j) {
		fr(o,1,k/2) if(f[i][j][o]==0||G[i][p]+G[p][j]<G[i][f[i][j][o]]+G[f[i][j][o]][j]) {
			rf(oo,k/2,o+1) f[i][j][oo]=f[i][j][oo-1];
			f[i][j][o]=p; break;
		}
	}
	a[1]=1; dfs(2);
	cout<<ans<<endl;
	return 0;
}