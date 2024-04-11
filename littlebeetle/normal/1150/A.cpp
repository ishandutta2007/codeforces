#include<cstdio>
const int N=10002;
int n,m,r,a[N],b[N],i,j,ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&m,&r);
	ans=r;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(j=1;j<=m;j++)
		scanf("%d",b+j);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			ans=max(ans,r/a[i]*b[j]+r%a[i]);
	printf("%d",ans);
	//while(1);
}