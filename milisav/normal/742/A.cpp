#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[100];
int main()
{
	a[1]=8;
	a[2]=4;
	a[3]=2;
	a[0]=6;
	scanf("%d",&n);
	if(n==0) printf("1");
	else
	{
		n=n%4;
		printf("%d",a[n]);
	}
	return 0;
}