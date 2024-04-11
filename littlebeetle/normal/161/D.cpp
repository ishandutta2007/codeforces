#include<cstdio>
const int N=100002,M=10002;
int n,m,i,j,k,a,b,c,q[N],h[N],t[N],v[N],w[N],rt,s,sz[N],p[N],dep[N],id[N],vis[N],sum,ok[M]={1},tmp[N];
long long ans;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
}
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int fa){
	sz[i]=1;
	p[i]=0;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa&&!vis[v[j]]){
			dfs(v[j],i);
			sz[i]+=sz[v[j]];
			p[i]=max(p[i],sz[v[j]]);
		}
	p[i]=max(p[i],sum-sz[i]-1);
	if(p[i]<s)
		rt=i,s=p[i];
}
void dfs2(int i,int fa){
	p[++k]=dep[i];
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa&&!vis[v[j]]){
			dep[v[j]]=dep[i]+1;
			dfs2(v[j],i);
			sz[i]+=sz[v[j]];
		}
}
void work(int i,int Sz){
	s=1<<30;
	sum=Sz;
	dfs(i,0);
	vis[rt]=1;
	int l=0;
	ok[0]=1;
	for(int j=h[rt];j;j=t[j])
		if(!vis[v[j]]){
			k=0;
			dep[v[j]]=1;
			dfs2(v[j],rt);
			for(int x=1;x<=k;x++)
				if(p[x]<=m)
					ans+=ok[m-p[x]];
			for(int x=1;x<=k;x++)
				if(p[x]<=m)
				ok[p[x]]++,id[++l]=p[x];
		}
	for(int x=1;x<=l;x++)
		ok[id[x]]=0;
	for(int j=h[rt];j;j=t[j])
		if(!vis[v[j]])
			work(v[j],sz[v[j]]);
}
int main(){
	init();
	work(1,n);
	printf("%I64d",ans);
}