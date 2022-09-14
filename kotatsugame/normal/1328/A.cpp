#include<cstdio>
using namespace std;
int t,a,b;
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",a%b==0?0:b-a%b);
	}
}