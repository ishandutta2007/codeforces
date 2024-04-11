#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[100];
int sum=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) sum+=a[i];
	if(sum!=0)
	{
		printf("YES\n");
		printf("1\n");
		printf("1 %d",n);
		return 0;
	}
	else
	{
		sum=0;
		for(int i=0;i<n;i++) 
		{
			sum+=a[i];
			if(sum!=0) 
			{
				printf("YES\n");
				printf("2\n");
				printf("1 %d\n",i+1);
				printf("%d %d\n",i+2,n);
				return 0;
			}
			
		}
		printf("NO\n");
		return 0;
	}
	return 0;
}