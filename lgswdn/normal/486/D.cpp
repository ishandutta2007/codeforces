#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2009,mod=1e9+7;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,d,a[N],f[N],ans;
bool better(int u,int v) {return a[u]>a[v]||a[u]==a[v]&&u<v;}
void dfs(int u,int fa,int p) {
	f[u]=1;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if((v=e[i].to)==fa) continue;
		if((!better(p,v))||a[p]-a[v]>d) continue;
		dfs(v,u,p);
		(f[u]*=(f[v]+1))%=mod;
	}
}

signed main() {
	scanf("%lld%lld",&d,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,u,v;i<n;i++)
		scanf("%lld%lld",&u,&v), add(u,v), add(v,u);
	for(int i=1;i<=n;i++) dfs(i,0,i), (ans+=f[i])%=mod;
	printf("%lld",ans);
	return 0;
}
//