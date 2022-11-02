#include<cstdio>
int n,k,l,r,sall,sk,i;
int main(){
	scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sall,&sk);
	sall-=sk;
	n-=k;
	for(i=1;i<=n;i++)
		printf("%d ",sall/n+(sall%n>=i));
	for(i=1;i<=k;i++)
		printf("%d ",sk/k+(sk%k>=i));	
	return 0;
}