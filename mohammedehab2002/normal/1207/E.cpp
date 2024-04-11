#include <iostream>
using namespace std;
int main()
{
	int a,b;
	printf("?");
	for (int i=1;i<=100;i++)
	printf(" %d",i);
	printf("\n");
	fflush(stdout);
	scanf("%d",&a);
	printf("?");
	for (int i=0;i<100;i++)
	printf(" %d",i*128);
	printf("\n");
	fflush(stdout);
	scanf("%d",&b);
	printf("! %d",(a^((a^b)&127)));
	fflush(stdout);
}