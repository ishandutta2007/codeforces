#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=0,pre=-1;
		for(int i=0;i<N;i++)
		{
			int A;scanf("%d",&A);
			if(A==1)
			{
				if(pre>=0)ans+=i-pre-1;
				pre=i;
			}
		}
		printf("%d\n",ans);
	}
}