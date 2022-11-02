#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	while(b%2==0)
		b/=2;
	if(a%b)
		printf("No");
	else
		printf("Yes");
}