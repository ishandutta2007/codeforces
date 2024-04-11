#include<cstdio>
const int N=100002;
int q,n,fa[N],sz[N],i,a,b;
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			fa[i]=i,sz[i]=1;
		for(i=1;i<=n;i++){
			scanf("%d",&a);b=i;
			a=p(a);b=p(b);
			if(a!=b){
				sz[a]+=sz[b];
				fa[b]=a;
			}
		}
		for(i=1;i<=n;i++)
			printf("%d ",sz[p(i)]);
		printf("\n");
	}
}