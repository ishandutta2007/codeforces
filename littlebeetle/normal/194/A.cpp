#include<cstdio>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	k-=n*2;
	if(k<n)
		printf("%d",n-k);
	else
		printf("0");
	return 0;
}