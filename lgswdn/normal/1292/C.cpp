#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3009;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,p[N][N],sz[N][N],f[N][N],ans;
void dfs1(int u,int fa,int rt) {
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		p[v][rt]=u;
		dfs1(v,u,rt);
		sz[u][rt]+=sz[v][rt];
	}
	sz[u][rt]++;
}
int dfs2(int u,int v) {
	//cout<<u<<" "<<v<<endl;
	if(u==v) return 0;
	if(f[u][v]) return f[u][v];
	else return f[u][v]=f[v][u]=
			max(dfs2(u,p[v][u]),dfs2(p[u][v],v))+sz[v][u]*sz[u][v];
}

signed main() {
	scanf("%lld",&n);
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v), add(u,v), add(v,u);
	for(int i=1;i<=n;i++) dfs1(i,0,i);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=max(ans,dfs2(i,j));
	printf("%lld",ans);
	return 0;
}