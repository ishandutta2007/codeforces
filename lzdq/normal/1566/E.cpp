#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN],vis[MAXN],ans;
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		if(!vis[v]) vis[u]++;
	}
	if(u>1&&vis[u]) ans+=vis[u]-1;
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=vis[i]=0;
		for(int i=1; i<n; i++){
			int u,v;
			scanf("%d%d",&u,&v);
			adde(u,v);
			adde(v,u);
		}
		ans=0;
		Dfs(1);
		ans+=max(vis[1],1);
		printf("%d\n",ans);
	}
	return 0;
}