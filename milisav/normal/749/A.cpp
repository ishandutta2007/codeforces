#include <iostream>
#include <cstdio>
using namespace std;
int k;
int n;
int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		k=n/2;
		printf("%d\n",k);
		for(int i=0;i<k;i++) printf("2 "); 
	}
	else
	{
		n--;
		k=n/2;
		printf("%d\n",k);
		printf("3 ");
		k--;
		for(int i=0;i<k;i++) printf("2 ");
	}
	return 0;
}