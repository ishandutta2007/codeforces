#include<cstdio>
#include<algorithm>
int a,b,p[4],s;
main(){
	scanf("%d%d%d%d%d%d",p,p+1,p+2,p+3,&a,&b);
	std::sort(p,p+4);
	if(a>p[0])putchar(48);
	else if(b<p[0])printf("%d",b-a+1);
	else printf("%d",*p-a);
}