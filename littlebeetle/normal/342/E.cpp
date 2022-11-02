#include<cstdio>
const int  N=200002;
int n,m,i,j,k,a,b,c,h[N],t[N],v[N],p[N],dis[N],dep[N],fa[N],sz[N],en[N],top[N],g[N],o,q[N],s,e,opt,ans;
void dfs1(int i){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			dep[v[j]]=dep[i]+1;
			dfs1(v[j]);
			sz[i]+=sz[v[j]];
			if(sz[v[j]]>sz[en[i]])
				en[i]=v[j];
		}
}
void dfs2(int i){
	if(en[i])
		top[en[i]]=top[i],dfs2(en[i]);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]&&v[j]!=en[i]){
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
void bfs(){
	o=0;s=1;e=0;
	for(i=1;i<=n;i++){
		dis[i]=-1;
		if(p[i])
			q[++e]=i,dis[i]=0;
	}
	while(s<=e){
		i=q[s++];
		for(j=h[i];j;j=t[j])
			if(dis[v[j]]==-1){
				dis[v[j]]=dis[i]+1;
				q[++e]=v[j];
			}
	}
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs1(1);
	top[1]=1;
	dfs2(1);
	p[1]=1;
	for(k=0;k<m;k++){
		if(k%200==0)
			bfs();
		scanf("%d%d",&opt,&a);
		if(opt==1){
			p[a]=1;
			g[++o]=a;
		}
		else{
			ans=dis[a];
			for(i=1;i<=o;i++){
				b=g[i];
				c=LCA(a,b);
				ans=min(ans,dep[a]+dep[b]-dep[c]*2);
			}
			printf("%d\n",ans);
		}
	}
}