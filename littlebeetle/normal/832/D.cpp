#include<cstdio>
const int N=200002;
int n,q,i,j,k,b;
int h[N],t[N],v[N];
int fa[N],e[N],dep[N],sz[N],top[N];
int x,y,z,d1,d2,d3,p1,p2,p3;
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs1(int i){
	sz[i]=1;
	for(int j=h[i];j;j=t[j]){
			dep[v[j]]=dep[i]+1;
			dfs1(v[j]);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[e[i]])
				e[i]=v[j];
		}
}
void dfs2(int i){
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
int Lca(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])
			a=fa[top[a]];
		else
			b=fa[top[b]];
	}
	return dep[a]<dep[b]?a:b;
}
void init(){
	scanf("%d%d",&n,&q);
	for(i=2;i<=n;i++){
		scanf("%d",fa+i);
		add(fa[i],i);
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
}
int max(int x,int y){
	return x>y?x:y;
}
void work(){
	while(q--){
		scanf("%d%d%d",&x,&y,&z);
		d1=dep[x]+dep[y]-2*dep[Lca(x,y)];
		d2=dep[z]+dep[y]-2*dep[Lca(z,y)];
		d3=dep[x]+dep[z]-2*dep[Lca(x,z)];	
		p1=d1+d2-d3>>1;
		p2=d2+d3-d1>>1;
		p3=d3+d1-d2>>1;
		printf("%d\n",max(max(p1,p2),p3)+1);
	}
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}