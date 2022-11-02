#include<cstdio>
const int N=400020;
int n,m,q,fa[N],u,v,i,ans;
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n+m;i++)
		fa[i]=i;
	ans=n+m-1;
	while(q--){
		scanf("%d%d",&u,&v);
		v+=n;
		u=p(u);
		v=p(v);
		if(u!=v){
			fa[u]=v;
			ans--;
		}
	}
	printf("%d",ans);
	//while(1);
}