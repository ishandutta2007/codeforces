#include<cstdio>
using namespace std;
int T,x,y;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&x,&y);
		int n=y<x?x+y:(y/x*x+y)/2;
		if(n%x!=y%n)puts("ERROR");
		printf("%d\n",n);
	}
}