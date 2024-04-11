#include<cstdio>
const int N=502;
int n,i,j,cnt,a[N][N];
int main(){
	scanf("%d",&n);
	for(j=1;j<=n;j++)
		if(j&1)
			for(i=1;i<=n;i++)
				a[i][j]=++cnt;
		else
			for(i=n;i;i--)
				a[i][j]=++cnt;			
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	//while(1);
}