#include<cstdio>
#include<algorithm>
using namespace std;
int t;
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a=n/k;
		printf("%d\n",a*k+min(n%k,k/2));
	}
}