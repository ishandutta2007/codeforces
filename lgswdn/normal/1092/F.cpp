#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,a[N],sum;

int s[N],f[N],d[N];
void dfs1(int u,int fa){
	s[u]=a[u];
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		d[v]=d[u]+1;
		dfs1(v,u);
		s[u]+=s[v], f[u]+=(f[v]+s[v]);
	}
} 

int ans[N],anss;
void dfs2(int u,int fa){
	if(u==1) ans[u]=f[u];
	for(int i=hd[u],v;i;i=e[i].nxt){
		if((v=e[i].to)==fa) continue;
		ans[v]=ans[u]+sum-2*s[v];
		dfs2(v,u);
	}
	//cout<<u<<" "<<f[u]<<" "<<ans[u]<<endl;
	anss=max(anss,ans[u]);
}

signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]), sum+=a[i];
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v),
		add(u,v), add(v,u);
	dfs1(1,0), dfs2(1,0);
	printf("%lld",anss);
	return 0;
}