#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200020,M=1000000007;
int n,q,i,j,k,m,r,a,b;
int h[N],t[N],v[N],Lca[N],Dep[N],x[N],s;
int sz[N],fa[N],e[N],dep[N],top[N],Tim,dfn[N];
int f[N/2][302],c[N],ans;
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs1(int i){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			dep[v[j]]=dep[i]+1;
			dfs1(v[j]);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[e[i]])
				e[i]=v[j];
		}
}
void dfs2(int i){
	dfn[i]=++Tim;
	if(e[i]){
		top[e[i]]=top[i];
		dfs2(e[i]);
	}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]&&v[j]!=e[i]){
			top[v[j]]=v[j];
			dfs2(v[j]);
		}
}
void init(){
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
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
bool cmp(int a,int b){
	return Dep[a]<Dep[b];
}
void Update(int x,int y){
	while(x<=n)
		c[x]+=y,x+=x&-x;
}
int Query(int x){
	int s=0;
	while(x)
		s+=c[x],x-=x&-x;
	return s;
}
void work(){
	while(q--){
		scanf("%d%d%d",&k,&m,&r);
		for(i=1;i<=k;i++){
			scanf("%d",x+i);
			Lca[x[i]]=LCA(x[i],r);
			Dep[x[i]]=dep[x[i]]+dep[r]-2*dep[Lca[x[i]]];
		}
		sort(x+1,x+k+1,cmp);
		for(i=0;i<=k;i++)
			for(j=0;j<=m;j++)
				f[i][j]=0;
		f[0][0]=1;
		for(i=0;i<k;i++){
			s=Query(dfn[x[i+1]])+Query(dfn[r])-Query(dfn[Lca[x[i+1]]])-Query(dfn[fa[Lca[x[i+1]]]]);
			for(j=0;j<=m;j++){	
				if(j>=s)
					f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*(j-s))%M;
				f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%M;
			}
			Update(dfn[x[i+1]],1);
			Update(dfn[x[i+1]]+sz[x[i+1]],-1);
		}
		for(i=0;i<k;i++){
			Update(dfn[x[i+1]],-1);
			Update(dfn[x[i+1]]+sz[x[i+1]],1);
		}
		ans=0;
		for(i=1;i<=m;i++)
			ans=(ans+f[k][i])%M;
		printf("%d\n",ans);
	}
}
int main(){
	init();
	work();
	return 0;
}