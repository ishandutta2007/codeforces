#include<cstdio>
int n,k,i;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<n-k;i++)
		printf("%d ",i);
	for(i=n;i>=n-k;i--)
		printf("%d ",i);
}