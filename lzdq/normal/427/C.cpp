#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,MAXM=6e5+5,Mod=1e9+7;
int n,m;
int a[MAXN];
int cnte,h[MAXN],to[MAXM],nx[MAXM];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int clk,dfn[MAXN],low[MAXN];
int top,stk[MAXN];
bool instk[MAXN];
int cntg,f[MAXN],g[MAXN];
void Dfs(int u){
	dfn[u]=low[u]=++clk;
	stk[++top]=u;
	instk[u]=1;
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(!dfn[v]) Dfs(v),low[u]=min(low[u],low[v]);
		else if(instk[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]<dfn[u]) return ;
	f[++cntg]=2e9;
	int p=stk[top];
	while(p!=u){
		instk[p]=0;
		if(f[cntg]>a[p]) f[cntg]=a[p],g[cntg]=0;
		if(f[cntg]==a[p]) g[cntg]++;
		p=stk[--top];
	}
	instk[p]=0;
	if(f[cntg]>a[p]) f[cntg]=a[p],g[cntg]=0;
	if(f[cntg]==a[p]) g[cntg]++;
	top--;
	return ;
}
ll ans1;
int ans2;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v);
	}
	for(int i=1; i<=n; i++)
		if(!dfn[i]) Dfs(i);
	ans2=1;
	for(int i=1; i<=cntg; i++)
		ans1+=f[i],ans2=1ll*ans2*g[i]%Mod;
	printf("%I64d %d\n",ans1,ans2);
	return 0;
}