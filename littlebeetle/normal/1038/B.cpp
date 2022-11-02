#include<cstdio>
int n,s,i,j;
int main(){
	scanf("%d",&n);
	if(n==1||n==2){
		printf("No");
		return 0;
	}
	s=n*(1+n)/2;
	printf("Yes\n");
	for(i=2;i<=n&&s%i;i++);
	printf("%d %d\n",1,i);
	printf("%d ",n-1);
	j=i;
	for(i=1;i<=n;i++)
		if(i!=j)
			printf("%d ",i);
}
//////