#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,fa[MAXN],a[MAXN],b[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int ans;
ll sum[MAXN];
void Dfs(int u){
	sum[u]=0;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		Dfs(v);
		sum[u]+=sum[v];
	}
	if(sum[u]<a[u]) sum[u]=b[u],ans++;
	if(sum[u]>b[u]) sum[u]=b[u];
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		cnte=0;
		for(int i=1; i<=n; i++)
			h[i]=0;
		for(int i=2; i<=n; i++){
			scanf("%d",fa+i);
			adde(fa[i],i);
		}
		for(int i=1; i<=n; i++)
			scanf("%d%d",a+i,b+i);
		ans=0;
		Dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}