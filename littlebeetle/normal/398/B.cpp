#include<cstdio>
const int N=2002;
double f[N][N];
int n,m,x,y,g,h,u[N],v[N],i,j;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&x,&y);
		if(!u[x])u[x]=1,g++;
		if(!v[y])v[y]=1,h++;
	}
	g=n-g;h=n-h;
	f[0][0]=0;
	for(i=1;i<=g;i++)
		f[i][0]=f[i-1][0]+1.0*n/i;
	for(i=1;i<=h;i++)
		f[0][i]=f[0][i-1]+1.0*n/i;
	for(i=1;i<=g;i++)
		for(j=1;j<=h;j++)
			f[i][j]=(n*n+f[i-1][j-1]*i*j+f[i][j-1]*j*(n-i)+f[i-1][j]*i*(n-j))/(n*n-(n-i)*(n-j));
    printf("%lf",f[g][h]);
}