#include <iostream>
#include <stdio.h>
using namespace std;
long long f(long long a)
{
	long long ans[]={a,1,a+1,0};
	return ans[a%4];
}
int main()
{
	int n;
	long long g=0;
	scanf("%d",&n);
	while (n--)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		g^=(f(a+b-1)^f(a-1));
	}
	if (g)
	printf("tolik");
	else
	printf("bolik");
}