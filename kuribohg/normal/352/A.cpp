#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p==5) a++;
		else b++;
	}
	if(b==0&&a<9) puts("-1");
	else if(b==0) puts("-1");
	else if(a<9) puts("0");
	else
	{
		for(int i=1;i<=a/9*9;i++)
			putchar('5');
		for(int i=1;i<=b;i++)
			putchar('0');
		puts("");
	}
	return 0;
}