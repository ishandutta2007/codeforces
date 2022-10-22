#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll INF=1ll<<60;
int n,k,m,len[MAXN];
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int fa[MAXN],dep[MAXN],mxd[MAXN],son[MAXN];
void Dfs(int u){
	mxd[u]=dep[u];
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		Dfs(v);
		mxd[u]=max(mxd[u],mxd[v]);
		if(mxd[v]>mxd[son[u]])
			son[u]=v;
	}
	return ;
}
ll ans=-INF;
ll Calc(int x,int b){
	b=min(b,n/2);
	return 1ll*(n-x-b)*(x-b);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
	}
	Dfs(1);
	len[m=1]=mxd[1]+1;
	for(int i=2; i<=n; i++)
		if(son[fa[i]]!=i) len[++m]=mxd[i]-dep[i]+1;
	sort(len+1,len+m+1);
	reverse(len+1,len+m+1);
	int b=n;
	for(int i=0; i<=k; i++){
		b-=len[i];
		ans=max(ans,Calc(i,b));
	}
	printf("%lld\n",ans);
	return 0;
}