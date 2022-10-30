#include<cstdio>
#include<cmath>
void check(int a){
	int t=sqrt(a+0.5);
	for(int i=2;i<=t;i++)
		if(!(a%i)){
			printf("%d ",2);
			return;
		}
	
			printf("%d ",1);
}
int n;
int main()

{
	scanf("%d",&n);
	if(n<=2)
		puts("1");
	else
	puts("2");
		for(int i=2;i<=n+1;i++)
			check(i);
}