#include<cstdio>
int i,a,b;
int main(){
	printf("? ");
	for(i=1;i<=100;i++)
		printf("%d ",i);
	printf("\n");
	fflush(stdout);
	scanf("%d",&a);
	a=a>>7<<7;
	printf("? ");
	for(i=1;i<=100;i++)
		printf("%d ",i<<7);
	printf("\n");
	fflush(stdout);
	scanf("%d",&b);
	b=b&((1<<7)-1);
	printf("! ");
	printf("%d",a^b);
}