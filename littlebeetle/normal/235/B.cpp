#include<cstdio>
const int N=1000002;
int n,i;
double p,x[N],f[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf",&p);
		x[i]=(x[i-1]+1)*p;
		f[i]=f[i-1]+(x[i-1]*2+1)*p;
	}
	printf("%.10lf",f[n]);
	//while(1);
}