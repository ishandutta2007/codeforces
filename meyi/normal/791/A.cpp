#include<cstdio>
main(){
	register int a,b,c=0;
	scanf("%d%d",&a,&b);
	while(a<=b)a*=3,b<<=1,++c;
	printf("%d",c);
}