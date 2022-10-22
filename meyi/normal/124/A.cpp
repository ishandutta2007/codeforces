#include<cstdio>
#include<algorithm>
main(){
	int a,b,n;
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",std::min(n-a,b+1));
}