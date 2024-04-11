#include <iostream>
using namespace std;
int main()
{
	long long n,k;
	scanf("%I64d%I64d",&n,&k);
	n%=(2*k);
	if (n<k)
	printf("NO");
	else
	printf("YES");
}