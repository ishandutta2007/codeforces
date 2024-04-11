#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n,k;
	scanf("%I64d%I64d",&n,&k);
	long long x=1;
	for (int i=0;i<k;i++)
	x*=10;
	printf("%I64d",n*x/__gcd(n,x));
}