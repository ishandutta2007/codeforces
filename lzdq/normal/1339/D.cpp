#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1],ind[MAXN];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ind[v]++;
	h[u]=cnte;
}
int c[MAXN];
int ans;
bool d1,d2;
void Dfs(int u,int f,bool d){
	if(ind[u]==1){
		if(d) d1=1;
		else d2=1;
	}
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==f) continue;
		Dfs(v,u,d^1);
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	Dfs(1,0,0);
	if(d1&&d2) printf("3 ");
	else printf("1 ");
	for(int i=1; i<=n; i++)
		if(ind[i]==1) c[to[h[i]]]++;
	ans=n-1;
	for(int i=1; i<=n; i++)
		if(c[i]>1) ans-=c[i]-1;
	printf("%d\n",ans);
	return 0;
}