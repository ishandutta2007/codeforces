#include<cstdio>
int t,n;
const int sum[]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
		{
			putchar('7');
			n-=3;
			while(n)
				putchar('1'),n-=2;
		}
		else
		{
			while(n)
				putchar('1'),n-=2;
		}
		putchar('\n');
	}
	return 0;
}