#include<cstdio>
const int N=1002;
const int c[4][4]={
	{8, 9, 1, 13},
	{3, 12, 7, 5},
	{0, 2, 4, 11},
	{6, 10, 15, 14}
};
int n,i,j,u,v,k,a[N][N];
int main(){
	scanf("%d",&n);
	for(i=0;i!=n;i+=4)
		for(j=0;j!=n;j+=4){
			for(u=1;u<=4;u++)
				for(v=1;v<=4;v++)
					a[i+u][j+v]=c[u-1][v-1]+k;
			k+=16;
		}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}					
}