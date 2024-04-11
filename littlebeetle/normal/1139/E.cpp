#include<cstdio>
const int N=10002;
int n,m,T,i,j,k,p[N],c[N],d[N],g,x;
int h[N],t[N],v[N],Mc[N],vis[N],ans[N];
bool f[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
		scanf("%d",d+i),f[d[i]]=1;
	for(i=1;i<=n;i++)
		if(!f[i])
			add(p[i],c[i]);
	for(i=0;i<N;i++)
		Mc[i]=-1;
}
bool dfs(int i){
	for(int j=h[i];j;j=t[j])
		if(vis[v[j]]!=x){
			vis[v[j]]=x;
			if(Mc[v[j]]==-1||dfs(Mc[v[j]])){
				Mc[v[j]]=i;
				return 1;
			}
		}
	return 0;
}
void work(){
	for(i=T;i;i--){
		x++;
		while(dfs(g))
			g++,x++;
		ans[i]=g;
		add(p[d[i]],c[d[i]]);
	}
	for(i=1;i<=T;i++)
		printf("%d\n",ans[i]);
}
int main(){
	init();
	work();
	//while(1);
}