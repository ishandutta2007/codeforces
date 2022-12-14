#include<bits\stdc++.h>
using namespace std;
int n,x,y,l,r,mid;
int main()
{
	scanf("%d",&n);
	printf("? %d\n",1);
	fflush(stdout);
	scanf("%d",&x);
	printf("? %d\n",n/2+1);
	fflush(stdout);
	scanf("%d",&y);
	if ((x-y)&1) 
	{
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}
	if (x==y) 
	{
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	l=1;r=n/2+1;
	if (x<y)
	{
		while(l<=r)
		{
			mid=(l+r)/2;
			printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",&x);
			printf("? %d\n",mid+n/2);
			fflush(stdout);
			scanf("%d",&y);
			if (x==y)
			{
				printf("! %d\n",mid);
				fflush(stdout);
				return 0;
			}
			if (x>y) r=mid-1;
			else l=mid+1;
		}
	}
	else
	{
		while(l<=r)
		{
			mid=(l+r)/2;
			printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",&x);
			printf("? %d\n",mid+n/2);
			fflush(stdout);
			scanf("%d",&y);
			if (x==y)
			{
				printf("! %d\n",mid);
				fflush(stdout);
				return 0;
			}
			if (x<y) r=mid-1;
			else l=mid+1;
		}
	}
	return 0;
}