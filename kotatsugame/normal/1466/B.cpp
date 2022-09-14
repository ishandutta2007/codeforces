#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int pre=0;
		int ans=0;
		for(;N--;)
		{
			int X;scanf("%d",&X);
			if(pre<X)
			{
				ans++;
				pre=X;
			}
			else if(pre==X)
			{
				ans++;
				pre=X+1;
			}
		}
		printf("%d\n",ans);
	}
}