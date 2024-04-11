#include<cstdio>
const int N=1002;
long double f[N][N],g[N][N];
double x;
int n,m,i,j;
int main(){
	scanf("%d%d",&n,&m);
	f[0][0]=0;
	g[0][0]=1;
	g[0][1]=1;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++){
			if(i)f[i][j]+=1.0*i/(i+j);
			if(j)f[i][j]+=j*(1-g[i][j-1])/(i+j);
			if(i)g[i][j]+=1.0*i/(i+j);
			if(j){
				if(j-1)
					g[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*(1-f[i][j-2]);
				if(i)
					g[i][j]+=1.0*j/(i+j)*i/(i+j-1)*(1-f[i-1][j-1]);				
			}
		}
	x=f[n][m];
	printf("%.10lf",x);
}