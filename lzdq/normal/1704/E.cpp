#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1005,mod=998244353,INF=0x3fffffff;
int n,m,rt,a[MAXN];
int cnte,h[MAXN],to[MAXN],nx[MAXN],d[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	d[v]++;
}
int f[MAXN];
int dfn[MAXN],rev[MAXN];
void Dfs(int u){
	dfn[u]=++*dfn;
	rev[*dfn]=u;
	d[u]=-1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		f[v]=(f[v]+f[u])%mod;
		if(!--d[v]) Dfs(v);
	}
	return ;
}
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		cnte=0;
		for(int i=1; i<=n; i++){
			h[i]=d[i]=f[i]=0;
			scanf("%d",a+i);
		}
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			adde(v,u);
		}
		for(int i=1; i<=n; i++)
			if(!d[i]){
				rt=i;
				break;
			}
		f[rt]=1;
		*dfn=0;
		Dfs(rt);
		ans=0;
		for(int i=1; i<=n; i++)
			ans=(ans+1ll*f[i]*a[i])%mod;
		for(int _=0; _<=n; _++){
			bool ok=0;
			for(int i=1; i<=n; i++)
				if(a[i]){
					ok=1;
					break;
				}
			if(!ok) break;
			if(!a[rt]) ans++;
			for(int i=1; i<=n; i++){
				int u=rev[i];
				if(a[u]) a[u]--;
				for(int j=h[u]; j; j=nx[j]){
					int v=to[j];
					if(a[v]) a[u]++;
				}
				a[u]=min(a[u],INF);
			}
		}
		ans%=mod;
		printf("%d\n",ans);
	}
	return 0;
}