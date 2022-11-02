#include<cstdio>
const int N=1002;
int n,m,i,j,a[N][N],sum;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",a[i]+j);
	for(i=n;i;i--)
		for(j=m;j;j--){
			if(!a[i][j])
				a[i][j]=min(a[i+1][j],a[i][j+1])-1;
			sum+=a[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]<=a[i-1][j]||a[i][j]<=a[i][j-1]){
				printf("-1");
				return 0;
			}
	printf("%d",sum);
}