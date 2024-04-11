#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN];
int ed[MAXN][3];
bool vis[MAXN];
namespace Graph{
	int cnte,h[MAXN],to[MAXN<<2],nx[MAXN<<2],ww[MAXN<<2];
	inline void adde(int u,int v,int w){
		cnte++;
		nx[cnte]=h[u];
		to[cnte]=v;
		ww[cnte]=w;
		h[u]=cnte;
	}
	inline void Adde(int u,int v,int w){
		adde(u,v,w);
		adde(v,u,w);
	}
	void Dfs(int u){
		vis[u]=1;
		for(int i=h[u]; i; i=nx[i]){
			int v=to[i];
			if(!vis[v]){
				a[v]=a[u]^ww[i];
				Dfs(v);
			}
		}
		return ;
	}
	bool Check(){
		for(int i=1; i<=n; i++)
			for(int j=h[i]; j; j=nx[j])
				if(ww[j]!=(a[i]^a[to[j]])) return 0;
		return 1;
	}
}
using Graph::Adde;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN];
void Dfs(int u){
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
		scanf("%d%d",&n,&m);
		cnte=Graph::cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=Graph::h[i]=vis[i]=0;
		for(int i=1; i<n; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			adde(u,v);
			adde(v,u);
			if(~w) Adde(u,v,__builtin_parity(w));
			ed[i][0]=u;
			ed[i][1]=v;
			ed[i][2]=w;
		}
		for(int i=1; i<=m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			Adde(u,v,w);
		}
		for(int i=1; i<=n; i++)
			if(!vis[i]) Graph::Dfs(i);
		if(Graph::Check()){
			puts("YES");
			Dfs(1);
			for(int i=1; i<n; i++){
				int u=ed[i][0],v=ed[i][1],w=ed[i][2];
				if(w==-1) w=a[u]^a[v];
				printf("%d %d %d\n",u,v,w);
			}
		}else puts("NO");
	}
	return 0;
}