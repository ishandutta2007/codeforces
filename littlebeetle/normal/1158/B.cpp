#include<cstdio>
int n,k,l,i;
int main(){
	scanf("%d%d",&n,&k);
	l=(n-k)/2+1;
	for(i=1;i<=n;i++)
		printf("%d",i%l>0);
}