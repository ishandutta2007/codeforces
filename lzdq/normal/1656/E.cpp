#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1],d[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
	d[v]++;
}
int fa[MAXN],dep[MAXN];
void Dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
	}
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=d[i]=0;
		for(int i=1; i<n; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			adde(u,v);
			adde(v,u);
		}
		Dfs(1);
		for(int i=1; i<=n; i++){
			if(dep[i]&1) putchar('-');
			printf("%d ",d[i]);
		}
		puts("");
	}
	return 0;
}