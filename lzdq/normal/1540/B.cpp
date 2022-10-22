#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=205,mod=1e9+7;
int n;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int f[MAXN][MAXN];
int fa[MAXN],dep[MAXN],lca[MAXN][MAXN];
void Dfs(int u){
	lca[u][u]=u;
	dep[u]=dep[fa[u]]+1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
	}
}
int GetLca(int x,int y){
	int &l=lca[x][y];
	if(l) return l;
	if(dep[x]<dep[y]) swap(x,y);
	return l=GetLca(fa[x],y);
}
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	for(int i=0; i<n; i++)
		f[0][i]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			f[i][j]=(f[i-1][j]+f[i][j-1])*(mod+1ll)/2%mod;
	for(int i=1; i<=n; i++){
		fa[i]=0;
		memset(lca,0,sizeof(lca));
		Dfs(i);
		for(int j=1; j<=n; j++)
			for(int k=1; k<j; k++){
				int l=GetLca(j,k);
				ans=(ans+f[dep[j]-dep[l]][dep[k]-dep[l]])%mod;
			}
	}
	ans=ans*Fstpw(n,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}