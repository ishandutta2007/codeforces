#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);
		long long tmp=cbrt(a*b);
		if ((tmp+1)*(tmp+1)*(tmp+1)==a*b)
		tmp++;
		if (tmp*tmp*tmp==a*b && a%tmp==0 && b%tmp==0)
		puts("Yes");
		else
		puts("No");
	}
}