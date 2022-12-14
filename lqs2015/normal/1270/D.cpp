#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,a,b,c,d,aa,bb,x,y;
int main()
{
	scanf("%d%d",&n,&k);
	a=b=c=d=-1;
	for (int i=1;i<=k+1;i++)
	{
		printf("? ");
		for (int j=1;j<=k+1;j++)
		{
			if (i==j) continue;
			printf("%d ",j);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d%d",&x,&y);
		if (a==-1)
		{
			a=x;b=y;
			aa=1;
		}
		else if (a==x) aa++;
		else if (c==-1)
		{
			c=x;d=y;
			bb=1;
		}
		else bb++;
	}
	if (b>d) 
	{
		swap(b,d);
		swap(a,c);
		swap(aa,bb);
	}
	printf("! %d\n",bb);
	fflush(stdout);
	return Accepted;
}