#include<cstdio>
int a[1001],k,n,s;
main(){
	scanf("%d%d",&n,&k),k=(n&1)+(n>>1);
	while(n--)scanf("%d",a),s+=a[*a]++&1;
	printf("%d",k+s);
}