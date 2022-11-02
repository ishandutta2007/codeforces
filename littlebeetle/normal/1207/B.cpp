#include<cstdio>
const int N=52;
int n,m,i,j,A[N][N],B[N][N];
int X[N*N],Y[N*N],cnt;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",A[i]+j);
	for(i=1;i<n;i++)
		for(j=1;j<m;j++)
			if(A[i][j]&&A[i+1][j]&&A[i][j+1]&&A[i+1][j+1]){
				cnt++;
				X[cnt]=i;
				Y[cnt]=j;
				B[i][j]=1;
				B[i+1][j]=1;
				B[i][j+1]=1;
				B[i+1][j+1]=1;
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(A[i][j]!=B[i][j]){
				printf("-1");
				return 0;
			}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",X[i],Y[i]);
}