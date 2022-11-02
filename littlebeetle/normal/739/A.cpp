#include<cstdio>
int n,m,ans,i,l,r;
int main(){
	scanf("%d%d",&n,&m);
	ans=1<<30;
	while(m--){
		scanf("%d%d",&l,&r);
		r=r-l+1;
		if(r<ans)
			ans=r;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",i%ans);
}