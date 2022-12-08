#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	long long n,k;
	scanf ("%lld %lld",&n,&k);

	long long s = max(k-n,1ll), e = min(n,k-1);

	if (s <= e) printf ("%lld\n",(e-s+1)/2);
	else puts("0");
	return 0;
}