#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,x;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		if (n==1)
		{
			printf("-1\n");
			continue;
		}
		x=0;
		for (int i=1;i<=n-2;i++)
		{
			putchar('5');
			x=(x*10+5)%7;
		}
		x=(x*100)%7;
		if ((x+50)%7) printf("57\n");
		else printf("27\n");
	}
	return Accepted;
}