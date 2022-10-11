#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if (n<4)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i=n;i>5;i-=2)
	{
		printf("%d - %d = 1\n",i,i-1);
		printf("1 * 1 = 1\n");
	}
	if (n%2)
	{
		printf("5 - 3 = 2\n");
		printf("1 + 2 = 3\n");
		printf("4 * 3 = 12\n");
		printf("12 * 2 = 24\n");
	}
	else
	{
		printf("4 * 3 = 12\n");
		printf("12 * 2 = 24\n");
		printf("24 * 1 = 24");
	}
}