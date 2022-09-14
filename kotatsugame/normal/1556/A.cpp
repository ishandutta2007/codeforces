#include<cstdio>
using namespace std;
int T,c,d;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&c,&d);
		if(c==d)
		{
			puts(c==0?"0":"1");
		}
		else puts((c-d)%2==0?"2":"-1");
	}
}