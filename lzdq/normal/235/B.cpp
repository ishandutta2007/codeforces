#include<cstdio>
const int MAXN=1e5+5;
int n;
double p[MAXN],f[MAXN][2];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lf",p+i);
		f[i][0]=p[i]*(f[i-1][0]+1);
		f[i][1]=f[i-1][1]+(2*f[i-1][0]+1)*p[i];
	}
	printf("%.8f\n",f[n][1]);
	return 0;
}