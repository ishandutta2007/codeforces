#include<cstdio>
const int N=2000002;
int n,m,i,j,k,a,b,h[N],t[N],v[N],dfn[N],sz[N],fa[N],dep[N],c[N],rm[N],cnt;
void dfs(int i){
	sz[i]=1;
	dfn[i]=++cnt;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa[i]){
			fa[v[j]]=i;
			dep[v[j]]=dep[i]+1;
			dfs(v[j]);
			sz[i]+=sz[v[j]];
		}
}
int sum(int x){
	int s=0;
	while(x)
		s+=c[x],x-=x&-x;
	return s;
}
void add(int x,int y){
	while(x<=n)
		c[x]+=y,x+=x&-x;
}
int main(){
	scanf("%d%d",&n,&m);
	m=n-m;
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dep[n]=1;
	dfs(n);
	for(i=n;i;i--){
		if(dep[i]-sum(dfn[i])<=m){
			j=i;
			while(j&&!rm[j]){
				add(dfn[j],1);
				add(dfn[j]+sz[j],-1);
				rm[j]=1;
				j=fa[j];
				m--;
			}
		}
	}
	for(i=1;i<=n;i++)
		if(!rm[i])
			printf("%d ",i);
}