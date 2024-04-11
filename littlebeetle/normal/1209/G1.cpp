#include<cstdio>
const int N=200002;
int n,q,i,a[N],pre[N],loc[N],fa[N],sum[N],sz[N],ans,x,y;
int max(int x,int y){
	return x>y?x:y;
}
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(!pre[a[i]])pre[a[i]]=i;
		loc[i]=pre[a[i]];
		fa[i]=i;
		sum[a[i]]++;
	}
	for(i=1;i<=n;i++)
		sz[i]=sum[a[i]];
	for(i=n;i;i--){
		while(p(i)>loc[i]){
			x=p(i);
			y=p(x-1);
			sz[y]=max(sz[y],sz[x]);
			sz[x]=0;
			fa[x]=y;
		}
	}
	for(i=1;i<=n;i++)
		ans+=sz[i];
	printf("%d",n-ans);
	
}