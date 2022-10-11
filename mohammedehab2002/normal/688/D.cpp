#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,a,lcm=1;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		a=__gcd(a,k);
		lcm=lcm/__gcd(lcm,a)*a;
	}
	if (lcm==k)
	printf("Yes");
	else
	printf("No");
}