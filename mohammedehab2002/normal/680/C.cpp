#include <stdio.h>
#include <string.h>
using namespace std;
char r[100];
int main()
{
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},square[]={4,9,25,49},i;
	for (i=0;i<4;i++)
	{
		printf("%d\n",square[i]);
		fflush(stdout);
		scanf("%s",&r);
		if (r[0]=='y')
		{
			printf("composite\n");
			return 0;
		}
	}
	int c=0;
	for (i=0;i<15;i++)
	{
		printf("%d\n",prime[i]);
		fflush(stdout);
		scanf("%s",&r);
		if (r[0]=='y')
		c++;
		if (c==2)
		{
			printf("composite\n");
			return 0;
		}
	}
	printf("prime\n");
}