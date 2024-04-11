#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int n,c[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int vis[MAXN];
int fa[MAXN],cnt[MAXN],sum[MAXN],dfn[MAXN],siz[MAXN];
int ans[MAXN];
void Quit(){
	for(int i=1; i<=n; i++)
		printf("1 ");
	puts("");
	exit(0);
}
void Dfs(int u){
	dfn[u]=++*dfn;
	sum[*dfn]=sum[*dfn-1]+c[u];
	siz[u]=1;
	cnt[u]=c[u];
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		siz[u]+=siz[v];
		cnt[u]+=cnt[v];
	}
	return ;
}
inline int Cnt(int u,int f){
	if(f==fa[u]) return cnt[u];
	return cnt[1]-cnt[f];
}
inline void Add(int u,int f){
	if(f==fa[u]) ans[dfn[u]]++,ans[dfn[u]+siz[u]]--;
	else ans[1]++,ans[dfn[f]]--,ans[dfn[f]+siz[f]]--;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",c+i);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	for(int i=1; i<=n; i++)
		if(c[i]){
			vis[i]++;
			for(int j=h[i]; j; j=nx[j])
				vis[to[j]]++;
		}
	for(int i=1; i<=n; i++)
		if(vis[i]>1) Quit();
	Dfs(1);
	for(int u=1; u<=n; u++)
		if(vis[u]){
			ans[dfn[u]]++;
			ans[dfn[u]+1]--;
			if(c[u]){
				int p=0;
				for(int i=h[u]; i; i=nx[i]){
					int v=to[i];
					if(Cnt(v,u)){
						if(p) Quit();
						p=v;
					}
				}
				if(p){
					for(int i=h[u]; i; i=nx[i]){
						int v=to[i];
						if(v!=p) Add(v,u);
					}
				}else puts("fuck");
			}else{
				int p1=0,p2=0;
				for(int i=h[u]; i; i=nx[i]){
					int v=to[i];
					if(Cnt(v,u)){
						if(!p1) p1=v;
						else if(!p2) p2=v;
						else Quit();
					}
				}
				if(p2){
					for(int i=h[u]; i; i=nx[i]){
						int v=to[i];
						if(v!=p1&&v!=p2) Add(v,u);
					}
					//printf("u %d p1 %d p2 %d\n",u,p1,p2);
				}//else printf("u %d p1 %d\n",u,p1);
			}
		}
	for(int i=1; i<=n; i++)
		ans[i]+=ans[i-1];
	for(int i=1; i<=n; i++)
		printf("%c ",ans[dfn[i]]?'1':'0');
	puts("");
	return 0;
}