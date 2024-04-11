#include<cstdio>
long long n,m;
int main(){
	scanf("%lld%lld",&n,&m);
	if(n>m)n^=m^=n^=m;
	printf("%lld",n==1?m/6*6+2*(m%6>3?m%6-3:0):n>2?n*m/2*2:m==2?0:m==3?4:m==7?12:m*2);
}