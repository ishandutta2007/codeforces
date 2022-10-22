#include<cstdio>
int a[10],m=32,n;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i),a[i]<m&&(m=a[i]);
	printf("%d",(a[2]^m)+2);
}