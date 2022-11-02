#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a<b)
		a^=b^=a^=b;
	printf("%d %d",a-1,b);
}