#include<cstdio>
const int N=2002;
int n,t,i,j;
double p,f[N][N];
int main(){
	scanf("%d%lf%d",&n,&p,&t);
	for(i=0;i<=n;i++)
		for(j=1;j<=t;j++)
			f[i][j]=(i?p*(1+f[i-1][j-1]):0)+(1-p)*f[i][j-1];
	printf("%.8lf",f[n][t]);
	//while(1);
}