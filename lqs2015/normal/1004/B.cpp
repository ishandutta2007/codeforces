#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i+=2)
	{
		if (i==n) printf("0");
		else printf("%d%d",0,1);
	}
	printf("\n");
	return 0;
}