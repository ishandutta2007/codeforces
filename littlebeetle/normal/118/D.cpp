#include<cstdio>
const int N=502,P=100000000;
int n,m,x,y,i,j,k,u[N][N],v[N][N];
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=1;i<=n&&i<=x;i++)
		u[i][0]=1;
	for(j=1;j<=m&&j<=y;j++)
		v[0][j]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			u[i][j]=(v[i-1][j]-(x<i?v[i-x-1][j]:0)+u[i][j-1]+P)%P;
			v[i][j]=(u[i][j-1]-(y<j?u[i][j-y-1]:0)+v[i-1][j]+P)%P;
		}
	printf("%d",(u[n][m]-u[n][m-1]+v[n][m]-v[n-1][m]+P*2)%P);
	return 0;	
}