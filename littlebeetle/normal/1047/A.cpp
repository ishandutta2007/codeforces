#include<cstdio>
int n,a,b;
int main(){//
	scanf("%d",&n);//
	a=1;b=1;n-=2;
	if(n%3==0)
		b++,n--;
	printf("%d %d %d",a,b,n);
	return 0;	//
}