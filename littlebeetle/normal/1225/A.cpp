#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a+1==b){
		printf("%d %d",a,b);
		return 0;
	}
	if(a==b){
		printf("%d0 %d1",a,b);
		return 0;
	}
	if(a==9&&b==1)
		printf("9 10");
	else
		printf("-1");
}