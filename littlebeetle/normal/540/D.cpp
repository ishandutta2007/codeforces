#include<cstdio>
const int N=102;
int A,B,C,i,j,k,sum;
double f[N][N][N],Ans;
int main(){
	scanf("%d%d%d",&A,&B,&C);
	f[A][B][C]=1;
	for(i=A;i>=0;i--)
		for(j=B;j>=0;j--)
			for(k=C;k>=0;k--){
				sum=i*j+j*k+i*k;
				if(sum){
				if(i)f[i-1][j][k]+=f[i][j][k]*i*k/sum;
				if(j)f[i][j-1][k]+=f[i][j][k]*i*j/sum;
				if(k)f[i][j][k-1]+=f[i][j][k]*j*k/sum;
			}
			}
	for(i=1;i<=A;i++)Ans+=f[i][0][0];
	printf("%.10lf ",Ans);
	Ans=0;
	for(i=1;i<=B;i++)Ans+=f[0][i][0];
	printf("%.10lf ",Ans);
	Ans=0;
	for(i=1;i<=C;i++)Ans+=f[0][0][i];
	printf("%.10lf",Ans);
}