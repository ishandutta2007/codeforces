#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(x==y)printf("%d\n",x+y);
		else
		{
			printf("%d\n",(x<y?y:x)*2-1);
		}
	}
}