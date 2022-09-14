#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans[50];
		bool exs[51]={};
		int sz=0;
		for(int i=0;i<2*N;i++)
		{
			int A;
			scanf("%d",&A);
			if(!exs[A])
			{
				exs[A]=true;
				ans[sz++]=A;
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?'\n':' ');
	}
}