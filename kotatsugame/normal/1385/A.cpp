#include<cstdio>
using namespace std;
int T,x,y,z;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==y&&x>=z)
		{
			puts("YES");
			printf("%d %d %d\n",x,1,z);
		}
		else if(x==z&&x>=y)
		{
			puts("YES");
			printf("%d %d %d\n",y,x,1);
		}
		else if(y==z&&y>=x)
		{
			puts("YES");
			printf("%d %d %d\n",x,1,y);
		}
		else puts("NO");
	}
}