#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long n;
		scanf("%I64d",&n);
		long long k=1;
		while (k<=n)
		k*=2LL;
		k--;
		printf("%I64d\n",n*(n+1)/2-2LL*k);
	}
}