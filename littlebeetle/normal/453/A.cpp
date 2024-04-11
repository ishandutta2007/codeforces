#include<cstdio>
const int N=1000002;
int m,n,i;
double f[N],ans; 
double ksm(double x,int p){
	double s=1;
	while(p){
		if(p&1)
			s=s*x;
		p>>=1;
		x=x*x;
	}
	return s;
}
int main(){
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		f[i]=ksm(1.0*i/m,n),
		ans+=(f[i]-f[i-1])*i;
	printf("%.10lf",ans);
}