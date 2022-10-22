#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll INF=1ll<<60;
int n,a[MAXN],rt;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN];
ll f[MAXN],ans;
void Dfs(int u){
	f[u]=0;
	int mx=0;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		f[u]+=f[v]+a[v];
		mx=max(mx,a[v]);
	}
	f[u]-=mx;
	a[u]=max(a[u],mx);
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	rt=1;
	for(int i=2; i<=n; i++)
		if(a[i]>a[rt]) rt=i;
	Dfs(rt);
	int mx1=0,mx2=0;
	for(int i=h[rt]; i; i=nx[i]){
		int v=to[i];
		ans+=f[v]+a[v];
		if(a[v]>mx1) mx2=mx1,mx1=a[v];
		else if(a[v]>mx2) mx2=a[v];
	}
	ans=ans+a[rt]*2-mx1-mx2;
	printf("%lld\n",ans);
	return 0;
}