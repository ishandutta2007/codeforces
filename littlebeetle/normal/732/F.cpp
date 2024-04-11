#include<cstdio>
const int N=800002;
int n,m,i,j,k,a,b,x[N],y[N],h[N],t[N],v[N],w[N],g[N],s,e[N],dfn[N],low[N],Tim,p[N],cnt,Sum[N];
int H[N],T[N],V[N],q[N],l,r,vis[N],id[N],tmp[N],K;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",x+i,y+i);
		a=x[i];b=y[i];
		t[++k]=h[a];h[a]=k;v[k]=b;w[k]=i;
		t[++k]=h[b];h[b]=k;v[k]=a;w[k]=i;
	}
}
int min(int x,int y){
	return x<y?x:y;
}
void Tarjan(int i,int fa){
	g[++s]=i;
	e[i]=1;
	dfn[i]=low[i]=++Tim;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			if(dfn[v[j]]){
				if(e[v[j]])
				low[i]=min(low[i],dfn[v[j]]);
			}
			else{
				Tarjan(v[j],i);
				low[i]=min(low[i],low[v[j]]);
			}
	if(low[i]==dfn[i]){
		cnt++;
		int j;
		do{
			j=g[s--];
			p[j]=cnt;
			e[j]=0;
			Sum[cnt]++;
		}
		while(j!=i);
	}
}
void Bfs(){
	vis[k]=Tim=1;
	q[l=r=0]=k;
	while(l<=r){
		i=q[l++];
		for(j=H[i];j;j=T[j])
			if(!vis[V[j]]){
				q[++r]=V[j];
				vis[V[j]]=++Tim;
			}
	}
}
void dfs(int i,int fa){
	tmp[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa&&p[i]==p[v[j]]){
			if(!id[w[j]])
			id[w[j]]=(i==x[w[j]])+1;
			if(!tmp[v[j]])
				dfs(v[j],i);
		}
}
int main(){
	init();
	Tarjan(1,0);
	/*for(i=1;i<=n;i++)
		printf("%d ",p[i]);*/
	for(i=1;i<=n;i++)
		for(j=h[i];j;j=t[j])
			if(p[i]!=p[v[j]]){
				a=p[i];
				b=p[v[j]];
				T[++K]=H[a];H[a]=K;V[K]=b;
			}
	for(i=1,k=0;i<=n;i++)
		if(Sum[i]>Sum[k])
			k=i;
	Bfs();
	Tim=0;
	for(i=1;i<=n;i++)
		if(!tmp[i])
			dfs(i,0);
	printf("%d\n",Sum[k]);
	for(i=1;i<=m;i++)
		if(p[x[i]]==p[y[i]]){
			if(id[i]<2)
				printf("%d %d\n",x[i],y[i]);
			else
				printf("%d %d\n",y[i],x[i]);
		}
		else{
			if(vis[p[x[i]]]>vis[p[y[i]]])
				printf("%d %d\n",x[i],y[i]);
			else
				printf("%d %d\n",y[i],x[i]);
		}
}