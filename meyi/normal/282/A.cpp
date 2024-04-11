#include<cstdio>
int n,m;
char s[3];
main(){
	scanf("%d",&n);
	while(n--)scanf("%s",s),m+=(s[1]=='+'?1:-1);
	printf("%d",m);
}