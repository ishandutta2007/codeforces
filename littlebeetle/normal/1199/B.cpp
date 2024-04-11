#include<cstdio>
const int N=100002;
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	printf("%.10lf",(1.0*b*b-1.0*a*a)/2/a);
}