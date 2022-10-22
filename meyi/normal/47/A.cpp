#include<cstdio>
int n;
main(){
	scanf("%d",&n);
	for(int i=1;n>0;n-=i++);
	puts(!n?"YES":"NO");
}