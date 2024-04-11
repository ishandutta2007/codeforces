#include<cstdio>
const int N=1000002;
int n,m,a,b,i,j,k,h[N],v[N],t[N],deg[N],vis[N],ans;
void dfs(int i){
	vis[i]=1;
	if(deg[i]!=2)
		k=0;
	for(int j=h[i];j;j=t[j])
		if(!vis[v[j]])
			dfs(v[j]);
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
		deg[a]++;deg[b]++;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			k=1;
			dfs(i);
			ans+=k;
		}
	printf("%d\n",ans);
	//while(1);
}