#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k,a[MAXN],fa[MAXN];
int cnte,h[MAXN],to[MAXN],nx[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int val[MAXN];
ll f[MAXN][2];
void Dfs(int u){
	int son=0;
	for(int i=h[u]; i; i=nx[i])
		son++;
	if(!son){
		f[u][0]=1ll*a[u]*val[u];
		f[u][1]=1ll*a[u]*(val[u]+1);
		return ;
	}
	f[u][0]=0;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		val[v]=val[u]/son;
		a[v]+=a[u];
		Dfs(v);
		f[u][0]+=f[v][0];
	}
	static ll g[MAXN];
	int tot=0;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		g[++tot]=f[v][1]-f[v][0];
	}
	sort(g+1,g+tot+1);
	reverse(g+1,g+tot+1);
	for(int i=1; i<=val[u]%son; i++)
		f[u][0]+=g[i];
	f[u][1]=f[u][0]+g[val[u]%son+1];
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=0;
		for(int i=2; i<=n; i++){
			scanf("%d",fa+i);
			adde(fa[i],i);
		}
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		val[1]=k;
		Dfs(1);
		printf("%lld\n",f[1][0]);
	}
	return 0;
}