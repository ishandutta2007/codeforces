#include<cstdio>
const int N=52;
int n,m,i,j,k,l,a;
double c[N][N],f[N][N][N];
void prepare(){
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
double ksm(double x,int b){
	double s=1;
	while(b){
		if(b&1)
			s=s*x;
		b>>=1;
		x=x*x;
	}
	return s;
}
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	prepare();	
	scanf("%d%d",&n,&m);
	for(i=1;i<N;i++)
		f[0][0][i]=i;
	for(i=1;i<=m;i++){
		scanf("%d",&a);
		for(j=0;j<=n;j++)
			for(k=0;k<N;k++)
				for(l=0;l<=j;l++)
					f[i][j][k]+=f[i-1][j-l][max(k,(l+a-1)/a)]*c[j][l]*ksm(i-1,j-l)/ksm(i,j);
	}
	printf("%.15lf",f[m][n][0]);
	return 0;
}