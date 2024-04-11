#include <iostream>
using namespace std;
int main()
{
	long long n;
	scanf("%I64d",&n);
	printf("2\n");
	for (long long i=2;i<=n;i++)
	printf("%I64d\n",i*(i+1)*(i+1)-i+1);
}