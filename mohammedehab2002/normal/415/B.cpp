#include <iostream>
using namespace std;
int main()
{
	int n;
	long long a,b;
	scanf("%d%I64d%I64d",&n,&a,&b);
	while (n--)
	{
		long long x;
		scanf("%I64d",&x);
		printf("%d ",((x*a)%b)/a);
	}
}