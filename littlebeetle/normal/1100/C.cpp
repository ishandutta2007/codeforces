#include<cstdio>
#include<cmath>
const double P=3.14159265359;
int n,r;
int main(){
	scanf("%d%d",&n,&r);
	printf("%.7lf",r*sin(P/n)/(1-sin(P/n)));
}