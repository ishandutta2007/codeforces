#include<cstdio>
#include<algorithm>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int H,W,x,y;
		scanf("%d%d%d%d",&H,&W,&x,&y);
		printf("1 1 %d %d\n",H,W);
	}
}