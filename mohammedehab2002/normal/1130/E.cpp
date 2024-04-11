#include <iostream>
using namespace std;
#define x 1300
int main()
{
	int k;
	scanf("%d",&k);
	int a=(k+x-4)/(x-3),b=a*(x-3)-k;
	a+=x/2-2;
	while (b+x-3<=1e6)
	{
		a++;
		b+=x-3;
	}
	printf("%d\n",x);
	for (int i=0;i<x/2-2;i++)
	printf("0 -1 ");
	printf("%d -1000000 -1000000 %d",a,b);
}