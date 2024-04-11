#include <iostream>
using namespace std;
int main()
{
	long long n;
	scanf("%I64d",&n);
	long long p=1;
	while (n%p==0)
	p*=3LL;
	printf("%I64d",n/p+1);
}