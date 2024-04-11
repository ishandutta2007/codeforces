#include<cstdio>
int a,b,c,d,e,f;
int main(){
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("3\n");
	printf("%d %d\n",-a+c+e,-b+d+f);	
	printf("%d %d\n",-c+a+e,-d+b+f);	
	printf("%d %d\n",-e+a+c,-f+b+d);	
}