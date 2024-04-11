#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1005;
int n,m;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int pre[MAXN],a[MAXN],b[MAXN];
int fnd(int x){
	if(pre[x]!=x) pre[x]=fnd(pre[x]);
	return pre[x];
}
int fa[MAXN],dep[MAXN],d;
void Dfs(int u){
	if(dep[u]>dep[d]) d=u;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		Dfs(v);
	}
	return ;
}
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		pre[i]=b[i]=i;
	for(int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int x=fnd(u),y=fnd(v);
		pre[x]=y;
		adde(u,v);
		adde(v,u);
	}
	for(int i=1; i<=n; i++){
		fa[i]=dep[i]=0;
		d=i;
		Dfs(i);
		if(a[fnd(i)]<dep[d]){
			a[pre[i]]=dep[d];
			ans=max(ans,dep[d]);
			int t=dep[d]/2;
			while(t--) d=fa[d];
			b[pre[i]]=d;
		}
	}
	int w=0;
	for(int i=1; i<=n; i++)
		if(pre[i]==i){
			a[i]=a[i]+1>>1;
			if(!w||a[i]>a[pre[w]]) w=b[i];
		}
	for(int i=1; i<=n; i++)
		if(pre[i]==i&&b[i]!=w) ans=max(ans,a[i]+a[pre[w]]+1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(pre[i]==i&&pre[j]==j&&i!=j&&b[i]!=w&&b[j]!=w) ans=max(ans,a[i]+a[j]+2);
	printf("%d\n",ans);
	for(int i=1; i<=n; i++)
		if(pre[i]==i&&b[i]!=w) printf("%d %d\n",b[i],w);
	return 0;
}