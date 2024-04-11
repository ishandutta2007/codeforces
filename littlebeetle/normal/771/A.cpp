#include<cstdio>
const int N=1000002;
int n,m,a,b,c,i,j,k,h[N],t[N],v[N],d[N],vis[N],sum,p;
void dfs(int i){
	vis[i]=1;
	sum+=d[i];
	p++;
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
		d[a]++;d[b]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]&&!vis[i]){
			sum=0;p=0;
			dfs(i);
			if(sum!=1ll*p*(p-1)){
				printf("NO");
				return 0;
			}
		}
	printf("YES");
}