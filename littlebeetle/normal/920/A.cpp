#include<cstdio>
const int N=2002;
int t,n,k,i,x[N],ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++)
			scanf("%d",x+i);
		ans=max(x[1],n-x[k]+1);
		for(i=1;i<k;i++)
			ans=max(ans,(x[i+1]-x[i])/2+1);
		printf("%d\n",ans);
	}
}