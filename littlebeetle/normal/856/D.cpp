#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int N=200002;
int n,m,a,b,i,j,k,h[N],t[N],v[N],dep[N],fa[N],top[N],sz[N],e[N],dfn[N],T;
ll f[N],g[N],c[N];
struct edg{
	int x,y,w;
}q;
vector<edg>p[N];
void dfs1(int i){
	sz[i]=1;
	for(int j=h[i];j;j=t[j]){
		dep[v[j]]=dep[i]+1;
		fa[v[j]]=i;
		dfs1(v[j]);
		sz[i]+=sz[v[j]];
		if(sz[v[j]]>sz[e[i]])
			e[i]=v[j];
	}
}
void dfs2(int i){
	dfn[i]=++T;
	if(e[i]){
		top[e[i]]=top[i];
		dfs2(e[i]);
	}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=e[i]){
			top[v[j]]=v[j];
			dfs2(v[j]);
		}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]])
			x=fa[top[x]];
		else
			y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
ll max(ll x,ll y){
	return x>y?x:y;
}
ll sum(int x){
	ll s=0;
	for(;x;x-=x&-x)
		s+=c[x];
	return s;
}
void add(int x,ll y){
	while(x<=n)
		c[x]+=y,x+=x&-x;
}
void dfs(int i){
	int j;
	edg k;
	for(j=h[i];j;j=t[j]){
		dfs(v[j]);
		g[i]+=f[v[j]];
	}
	f[i]=g[i];
	for(j=0;j<p[i].size();j++){
		k=p[i][j];
		f[i]=max(f[i],g[i]+sum(dfn[k.x])+sum(dfn[k.y])+k.w);
	}
	add(dfn[i],g[i]-f[i]);
	add(dfn[i]+sz[i],f[i]-g[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(b=2;b<=n;b++){
		scanf("%d",&a);
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&q.x,&q.y,&q.w);
		a=LCA(q.x,q.y);
		p[a].push_back(q);
	}
	dfs(1);
	printf("%I64d",f[1]);
}