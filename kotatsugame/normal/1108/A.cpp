#include<cstdio>
#include<algorithm>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d %d\n",a,a==c?d:c);
	}
}