#include<cstdio>
int n,k;
main(){
	scanf("%d%d",&n,&k);
	printf("%d",n+k-n%k);
}