#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],fa[MAXN];
int cnte,h[MAXN],to[MAXN],nx[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int tot[MAXN];
ll f[MAXN],g[MAXN];
void Dfs(int u){
	ll mx=0,s=a[u];
	if(!h[u]){
		tot[u]=1;
		f[u]=s;
		return ;
	}
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		mx=max(mx,f[v]);
		tot[u]+=tot[v];
		s-=g[v];
	}
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		s-=(mx-f[v])*tot[v];
	}
	f[u]=mx;
	//printf("u %d mx %lld s %lld\n",u,mx,s);
	if(s>0) f[u]+=(s+tot[u]-1)/tot[u],g[u]=(s%tot[u]?tot[u]-s%tot[u]:0);
	else g[u]=-s;
	return ;
}
int main(){
	//freopen("d.in","r",stdin);
	scanf("%d",&n);
	for(int i=2; i<=n; i++)
		scanf("%d",fa+i),adde(fa[i],i);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	Dfs(1);
	printf("%lld\n",f[1]);
	return 0;
}