#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N=400002;
int n,m,q,i,j,k,a,b,c,A[N],B[N];
int dfn[N],low[N],Tim,st[N],tp,cnt,id[N];
int h[N],t[N],v[N];
int sz[N],E[N],dep[N],fa[N],top[N],grp[N];
int up[N],down[N],vis[N];
vector<int>e[N],w[N];
void init(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		A[i]=a;B[i]=b;
		e[a].push_back(b);
		w[a].push_back(i+1);
		e[b].push_back(a);
		w[b].push_back(i+1);
	}
}
int min(int x,int y){
	return x<y?x:y;
}
void Tarjan(int i,int fa){
	dfn[i]=low[i]=++Tim;
	st[++tp]=i;
	for(int j=0;j<e[i].size();j++)
		if(w[i][j]!=fa){
			if(!dfn[e[i][j]]){
				Tarjan(e[i][j],w[i][j]);
				low[i]=min(low[i],low[e[i][j]]);
			}
			else
				low[i]=min(low[i],dfn[e[i][j]]);
		}
	if(low[i]==dfn[i]){
		cnt++;
		int j;
		do{
			j=st[tp--];
			id[j]=cnt;
		}
		while(j!=i);
	}
}
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void dfs1(int i){
	grp[i]=Tim;
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			dep[v[j]]=dep[i]+1;
			dfs1(v[j]);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[E[i]])
				E[i]=v[j];
		}
}
void dfs2(int i){
	if(E[i]){
		top[E[i]]=top[i];
		dfs2(E[i]);
	}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]&&v[j]!=E[i]){
			top[v[j]]=v[j];
			dfs2(v[j]);
		}
}
int LCA(int x,int y){
	while(top[x]!=top[y])
		if(dep[top[x]]>dep[top[y]])
			x=fa[top[x]];
		else
			y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
void dfs3(int i){
	vis[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			dfs3(v[j]);
			down[i]+=down[v[j]];
			up[i]+=up[v[j]];
		}
	if(down[i]&&up[i]){
		printf("No");
		exit(0);
	}
}
void work(){
	for(i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i,0);
	for(i=0;i<m;i++){
		a=id[A[i]];b=id[B[i]];
		if(a!=b){
			add(a,b);
			add(b,a);
		}
	}
	for(i=1;i<=cnt;i++)
		if(!sz[i]){
			Tim++;
			dfs1(i);
			top[i]=i;
			dfs2(i);
		}
	while(q--){
		scanf("%d%d",&a,&b);
		a=id[a];b=id[b];
		if(grp[a]!=grp[b]){
			printf("No");
			return;
		}
		c=LCA(a,b);
		up[a]++;
		up[c]--;
		down[b]++;
		down[c]--;
	}
	for(i=1;i<=cnt;i++)
		if(!vis[i])
			dfs3(i);
	printf("Yes");
	//while(1);
}
int main(){
	init();
	work();
}