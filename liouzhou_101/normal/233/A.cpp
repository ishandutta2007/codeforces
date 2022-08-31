#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		if (n&1)
		{
			puts("-1");
			continue;
		}
		for (int i=1;i<=n/2;++i)
		{
			if (i>1) putchar(' ');
			printf("%d %d",2*i,2*i-1);
		}
		puts("");
	}
	return 0;
}