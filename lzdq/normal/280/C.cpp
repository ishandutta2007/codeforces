#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n;
double ans;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN],dep[MAXN];
void Dfs(int u){
	dep[u]=dep[fa[u]]+1;
	ans+=1.0/dep[u];
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	Dfs(1);
	printf("%f\n",ans);
	return 0;
}