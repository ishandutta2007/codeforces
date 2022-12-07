#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n<=3) {puts("NO");return 0;}
	puts("YES");
	if(n&1)
	{
		puts("3 * 5 = 15");
		puts("2 * 4 = 8");
		puts("15 + 8 = 23");
		puts("23 + 1 = 24");
		for(int i=6;i<=n;i+=2)
		{
			printf("%d - %d = 1\n",i+1,i);
			puts("1 * 24 = 24");
		}
	}
	else
	{
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		for(int i=5;i<=n;i+=2)
		{
			printf("%d - %d = 1\n",i+1,i);
			puts("1 * 24 = 24");
		}
	}
	return 0;
}